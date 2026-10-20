# CameraMode and FOV sidequest notes

This page documents camera findings made while debugging render-anchor instability.

The camera research matters because it explains why different views materially change the render stream.

## 1. V is CameraMode, not View

The provided DInput mapping exposed the semantic action names:

```text
RSC = V
RSC = CameraMode
View = SwitchRadarMap
```

The active setup uses SteamInput, but the game normalizes it into the same gameplay action layer.

Important distinction:

```text
V  → RSC → CameraMode
M  → View → SwitchRadarMap
```

## 2. Input normalization chain

```text
sub_14021D4C0
    ↓
sub_140188A80
    ↓
sub_140188550
    ↓
sub_140187C80
    ↓
sub_1401040C0
```

`sub_140188A80` splits the raw controller bitfield.

Relevant observed mapping:

| Raw bit | Raw-state field | Interpreted action |
| --- | --- | --- |
| `0x20` | `+4` | Back / View-like button |
| `0x80` | `+5` | Right thumb / RSC / CameraMode |
| `0x10` | `+6` | Start/Menu |
| `0x40` | `+7` | Left thumb |
| `0x1000` | `+8` | A |
| `0x2000` | `+9` | B |
| `0x4000` | `+10` | X |
| `0x8000` | `+11` | Y |

## 3. CameraMode action ID

In `sub_1401040C0`:

```text
ActionQuery(..., 0x22, ...)
```

is associated with the RSC/CameraMode path.

Current conclusion:

```text
gameplay action ID 0x22 = CameraMode
```

## 4. Three-state cycle

Current camera mode byte:

```text
object +0x2094
```

Verified transition logic:

```text
0 → 2
2 → 1
1 → 0
```

Observed user-facing V-cycle:

```text
first-person/no cockpit
→ cockpit
→ third-person
→ first-person/no cockpit
```

High-confidence mapping:

```text
mode 0 = first-person / no cockpit model
mode 2 = cockpit
mode 1 = third-person
```

## 5. CameraMode affects rendering, not only transforms

`sub_140108620` reads `+0x2094` multiple times:

```text
0x140109277
0x140109484
0x14010975C
0x1401097FB
```

and selects different builders such as:

```text
sub_140109DC0
sub_14010A2E0
sub_140156D10
sub_140157F40
sub_1401580C0
sub_140158D00
```

So third-person is not simply the same draw list with a different camera matrix.

This is a direct explanation for why fixed draw-sequence HUD anchors were brittle.

## 6. Angle-limit constants

Player/model initialization writes:

```text
90°, 90°
60°, 60°
120°, 120°
```

at:

```text
+0xC70
+0xC74
+0xC78
+0xC7C
+0xC80
+0xC84
```

`sub_1401580C0` uses them in arithmetic such as:

```text
current - limit
current + limit
comparison/clamping
```

Current interpretation:

```text
camera yaw/pitch/view-angle limits
```

not actual perspective FOV.

Do not patch these values as a FOV mod just because they look like attractive 60°/90°/120° constants.

## 7. FOV/projection lead

Short sidequest found a more promising path:

```text
camera/gameplay code
    ↓
sub_1401FBEC0
    ├─ sub_140202C00
    └─ sub_140202C90
```

`sub_1401FBEC0` is called from multiple camera/gameplay routines and:

- builds camera transform data;
- reads several scalar camera/frustum fields;
- invokes `sub_140202C90`;
- computes matrix-like scale/depth terms and writes them to the camera structure.

`sub_140202C90` has only one caller: `sub_1401FBEC0`.

High-confidence hypothesis:

```text
sub_1401FBEC0 = camera matrix/frustum update
sub_140202C90 = projection/frustum builder
```

No FOV field has yet been definitively labeled.

## 8. Suggested future FOV workflow

1. Trace writers of fields consumed immediately before `sub_140202C90`.
2. Classify likely near/far/frustum/aspect values by runtime magnitude.
3. Compare values across the three CameraMode states.
4. Change one field at a time.
5. Distinguish:
   - horizontal/vertical FOV change;
   - aspect distortion;
   - near/far clipping;
   - camera-position change;
   - rotation-limit change.
6. Only then expose a user FOV multiplier.

Plausible eventual interface:

```text
first-person FOV multiplier
cockpit FOV multiplier
third-person FOV multiplier
```

This is not yet implemented or validated.
