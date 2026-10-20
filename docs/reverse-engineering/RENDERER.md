# Legacy renderer and D3D12 seam

This page collects renderer-specific findings that justify the production ReShade architecture.

## 1. The port is not native D3D12 all the way down

Observed architecture:

```text
gameplay/HUD logic
    ↓
legacy display-list / packet generation
    ↓
tag parser
    ↓
packet interpreter
    ↓
legacy batch/state renderer
    ↓
modern D3D12 draw builder
    ↓
ID3D12GraphicsCommandList
```

This explains why a useful semantic seam exists well before D3D12 calls.

## 2. Combat HUD packet region

`sub_1400AE510` emits the complete combat-HUD packet list and returns the result/end pointer to `sub_1402011A0`.

This gave the temporary oracle an explicit CPU-side region:

```text
packet_begin ≤ packet pointer < packet_result
```

The production add-on no longer depends on this address, but the seam remains the semantic reason we know which GPU work corresponds to the combat HUD.

## 3. Display-list parser

`sub_14018F920` uses a global/source cursor and handles a tagged command stream.

Observed concrete values:

```text
0x10000006
0x50000006
0x30000004
0x50000004
0x10000007
0x50000007
```

The parser extracts a low-16 length and calls:

```cpp
sub_14019D160(a1, a2 + 2, 4 * (uint16_t)tag + 2, v5);
```

The exact legacy packet ABI should not be described as PS2 GS/GIF without further proof.

## 4. Packet interpreter and batch boundary

`sub_14019D160` dispatches opcode-like values and eventually reaches `sub_14019CBF0`.

`sub_14019CBF0` is best treated as a state/batch flush point, not the final GPU draw.

It may invoke:

```text
sub_140194840(state + 24)
```

`sub_140194840` is the legacy batch renderer and directly calls `sub_14020F8E0`.

## 5. D3D12 layer

```text
sub_140194840
    ↓
sub_14020F8E0
    ↓
sub_14020F680
    ↓
ID3D12GraphicsCommandList
```

`sub_14020F680` performs modern root/descriptor state setup and issues indexed/non-indexed draws.

## 6. Frame lifecycle

### Begin

`sub_14020B9C0`:

- selects/reset frame resources;
- transitions resources;
- clears/initializes current target.

### End

`sub_14020C280`:

```text
render target → present
Close command list
ExecuteCommandLists
Present(1, 0)
Signal / fence wait
```

A tail path `sub_1401FE9C0` sequences:

```text
sub_14020C280
→ sub_14020B9C0
→ sub_14018FA80
```

## 7. The critical timing failure

First proposed bridge:

```text
enter sub_14020F8E0 from HUD parser
→ set thread-local scope
→ ReShade draw callback inspects scope
```

Calibration showed correct HUD draws arrived at ReShade with scope `0`.

Lesson:

```text
legacy semantic traversal
→ queue/build work
→ semantic function returns
→ later D3D12 draw events
```

Therefore production must identify HUD work from GPU-visible properties.

## 8. GPU anchor evolution

### A. Known draw sequence

```text
IDX64
DRAW4
IDX89
```

Useful for calibration/bootstrap, not invariant.

### B. Runtime PSO handle

Failed across camera/view changes because runtime PSO identity is not semantic identity.

### C. Partial stable fingerprint

Example:

```text
stable = 0xc45ffe89e386cb09
VS     = 0x70848fc93426bb4e
PS     = 0xae6370c8685b4894
```

Too coarse. Many different PSOs collided.

Symptoms:

- cockpit geometry flashing into `SceneClean`;
- airspeed/HUD elements flashing into `SceneClean`;
- occasional black frame;
- wrong `IDX89` selected.

### D. `DRAW4 → IDX89`

More selective, still failed when transient UI changed packet ordering.

### E. normalized full PSO

Current full fingerprint includes root-signature/layout content and stable graphics-PSO subobjects exposed by ReShade.

A miss frame proved:

```text
bootstrap first HUD:
full_pso = 0x3ef04bb2bb111cce
count    = 89

later miss frame:
same full_pso
first matching draw count = 94
```

Direct conclusion:

```text
draw count = incidental
normalized full PSO = useful semantic GPU identity
```

## 9. MSAA

Initial production log:

```text
unsupported HUD target desc type=3 size=2560x1440 samples=8
```

The game target was 8× MSAA.

Production path:

```text
source MSAA render target
render_target → resolve_source

SceneClean single-sample texture
shader_resource → resolve_dest

resolve_texture_region(...)

source resolve_source → render_target
SceneClean resolve_dest → shader_resource
```

For non-MSAA targets the bridge retains a copy path.

This fix changed raw output from black to a valid SceneClean image.
