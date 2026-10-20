# ACZ renderer/camera function index

Target:

| Item | Value |
| --- | --- |
| Module | `acz.exe` |
| Architecture | PE64 / x86-64 |
| IDA image base | `0x140000000` |
| SHA-256 | `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664` |
| RVA | `IDA_VA - 0x140000000` |

Analysis names are descriptive labels, not original symbols.

## Function index

| ID | Analysis name | IDA VA | RVA | Confidence | Role |
| --- | --- | --- | --- | --- | --- |
| F01 | CombatHudPacketEmitter | `0x1400AE510` | `0x00AE510` | Verified | Emits the whole combat-HUD logical packet range. |
| F02 | LegacyDisplayListParser | `0x14018F920` | `0x018F920` | Verified | Parses tagged legacy display-list/control blocks. |
| F03 | PacketInterpreter | `0x14019D160` | `0x019D160` | Verified | Four-argument packet interpreter; dispatches packet opcodes. |
| F04 | BatchStateFlush | `0x14019CBF0` | `0x019CBF0` | High-confidence | Flush/state boundary; may invoke legacy renderer. |
| F05 | PacketStateUnpack | `0x14019CD40` | `0x019CD40` | High-confidence | State/data unpack/copy path, not a direct modern draw. |
| F06 | LegacyBatchRenderer | `0x140194840` | `0x0194840` | Verified | Legacy batch renderer feeding modern backend. |
| F07 | ModernD3D12DrawBuilder | `0x14020F8E0` | `0x020F8E0` | Verified | Builds modern D3D12 draw work from legacy state. |
| F08 | D3D12DrawHelper | `0x14020F680` | `0x020F680` | Verified | Game-side command-list helper issuing root/draw calls. |
| F09 | FrameBegin | `0x14020B9C0` | `0x020B9C0` | Verified | Reset/begin frame, barriers and clear. |
| F10 | FrameEnd | `0x14020C280` | `0x020C280` | Verified | RT→present barrier, close, execute, present and fence work. |
| F11 | RenderHudFrameTop | `0x140108620` | `0x0108620` | Verified | Large render/HUD builder; calls F01 and reads camera mode repeatedly. |
| F12 | DisplayListFinalize | `0x1402011A0` | `0x02011A0` | Verified | Finalizes/links returned display-list block; writes `0x20000000`. |
| F13 | DisplayListLink | `0x140197B30` | `0x0197B30` | Verified call role | Linked-list/display-list helper. |
| F14 | CameraModeGameplay | `0x1401040C0` | `0x01040C0` | Verified | Consumes action `0x22`; cycles three camera modes. |
| F15 | CameraPacketBuilderA | `0x140109DC0` | `0x0109DC0` | High-confidence | Camera-mode-dependent packet/render builder. |
| F16 | CameraPacketBuilderB | `0x14010A2E0` | `0x010A2E0` | High-confidence | Alternate camera-mode-dependent builder. |
| F17 | CameraOverlayBuilder | `0x1401580C0` | `0x01580C0` | High-confidence | Camera/HUD builder using angle-limit fields; called from F11. |
| F18 | CameraMatrixUpdate | `0x1401FBEC0` | `0x01FBEC0` | High-confidence | Repeated camera matrix/frustum/projection update path. |
| F19 | ProjectionLikeBuilder | `0x140202C90` | `0x0202C90` | Open/high-confidence | Sole caller F18; likely projection/frustum helper. |
| F20 | ViewTransformBuilder | `0x140202C00` | `0x0202C00` | High-confidence | Called by F18 on camera transform vectors. |
| F21 | RawInputNormalize | `0x140188A80` | `0x0188A80` | Verified | Splits XInput/SteamInput button bits into gameplay input fields. |
| F22 | ActionStateCopy | `0x140188550` | `0x0188550` | Verified | Copies raw fields into normalized action state. |
| F23 | ActionQuery | `0x140187C80` | `0x0187C80` | Verified | Gameplay action query used by camera mode and other systems. |
| F24 | InputAggregate | `0x14021D4C0` | `0x021D4C0` | High-confidence | Unified Steam/controller/keyboard input aggregation. |

## Important globals

| Name | IDA VA | RVA | Meaning |
| --- | --- | --- | --- |
| DeviceResourcesGlobal | `0x14033DA48` | `0x033DA48` | Pointer/global for D3D12 device-resources object. |
| GameplayInputRaw | `0x14032C8E0` | `0x032C8E0` | Raw normalized gameplay input state pointer/global. |
| GameplayActionState | `0x14032C8E8` | `0x032C8E8` | Higher-level action-state pointer/global. |
| CameraGlobalAngle | `0x140328448` | `0x0328448` | Camera/render angle-related global used by `sub_1401580C0`; not yet identified as FOV. |

## DeviceResources approximate layout

| Offset | Meaning |
| --- | --- |
| `+0x00` | current frame/backbuffer index |
| `+0x08` | `ID3D12Device*` |
| `+0x10` | `ID3D12GraphicsCommandList*` |
| `+0x18` | `ID3D12CommandQueue*` |
| `+0x40` | `IDXGISwapChain*` |
| `+0x48` | backbuffer resource array |
| `+0x68` | `ID3D12Fence*` |
| `+0x90` | fence event handle |
| `+0xE8` | DXGI format |
| `+0xF0` | backbuffer count |
| `+0x108` | HWND |

This is a research layout, not a complete C++ class definition.

## Combat HUD call seam

Inside `sub_140108620`:

```asm
0x140108976  call sub_1400AE510
0x14010897B  mov  rdx, rax
0x140108981  call sub_1402011A0
```

Normalized semantics:

```cpp
packet_end = CombatHudPacketEmitter(...);
FinalizeDisplayList(..., packet_end);
```

## Legacy parser notes

`sub_14018F920`:

```cpp
tag = *Src;
length = low16(tag);

switch (tag & 0x70000000) {
    case 0x10000000: /* inline block */ ...
    case 0x20000000: /* jump/link */ ...
    case 0x30000000: /* control */ ...
    case 0x50000000: /* call/return-like */ ...
    case 0x60000000: /* flush/submit-like */ ...
    case 0x70000000: /* end */ ...
}

sub_14019D160(a1, a2 + 2, 4 * length + 2, v5);
```

Do not describe this format as PS2 GS/GIF without further proof.

## Packet interpreter notes

`sub_14019D160` loops words using:

```cpp
opcode = HIBYTE(*word) & 0x7F;
```

Observed opcode branches include:

```text
1, 2, 3, 20, 23, 31, 32, 74, 80, 81
```

The function signature is four-argument. Earlier three-argument handling was wrong.

## CameraMode action chain

Input semantics:

```text
Keyboard V
  → RSC
  → CameraMode
```

The DInput sample established that `View` is a separate action used for radar-map switching, not camera mode.

Static chain:

```text
sub_14021D4C0
  → sub_140188A80
      XInput/SteamInput 0x80 RightThumb/RSC → raw state +5
  → sub_140188550
      raw +5 → action-state +3
  → sub_140187C80
      query action
  → sub_1401040C0
      action id 0x22 = CameraMode
```

## Camera-mode state field

Within `sub_1401040C0`:

```text
object +0x2094 = current camera mode byte
```

Verified transition logic:

```text
0 → 2
2 → 1
1 → 0
```

Observed V-cycle gives a high-confidence mapping:

```text
0 = first-person / no cockpit model
2 = cockpit
1 = third-person
```

The same byte is read repeatedly by `sub_140108620`, proving camera changes affect render/display-list construction rather than only a final camera matrix.

## Camera angle-limit fields

Initialization writes:

```text
+0xC70 = 90°
+0xC74 = 90°
+0xC78 = 60°
+0xC7C = 60°
+0xC80 = 120°
+0xC84 = 120°
```

`sub_1401580C0` uses these values in add/subtract/compare operations.

Current interpretation: **camera yaw/pitch/view-angle limits**, not projection FOV.

## FOV/projection lead

`sub_1401FBEC0` is the preferred future FOV entry.

It:

1. builds view/transform data through `sub_140202C00`;
2. reads camera/frustum-like scalar fields;
3. calls `sub_140202C90`, whose only caller is `sub_1401FBEC0`;
4. computes/writes projection-like coefficients around `+0xD0`, `+0xE4`, etc.

Suggested future path:

```text
identify writers of camera +0x08/+0x0C/+0x10/+0x1C/+0x20/...
    ↓
classify near/far/frustum extents/aspect
    ↓
confirm sub_140202C90 projection role
    ↓
apply FOV multiplier per CameraMode
```
