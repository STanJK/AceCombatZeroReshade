# Function and capability inventory

Build/confidence: [README](README.md).
All names below are research labels. S confirms mechanics; H denotes inferred semantics.
No row grants permission to call an inferred ABI directly from a patch.

## Focused contracts

| RVA | Research label | Evidence | Area | Usage boundary |
| --- | --- | --- | --- | --- |
| [`0x19ef0`](evidence/decompiled/140019ef0.c) | HistorySingleton | S/H | history | Returns lazy singleton at RVA 0x31E980; not a complete save-state API. |
| [`0x19f80`](evidence/decompiled/140019f80.c) | HistoryPoolReset | S | history | Rebuilds record lists/free pools and resets counters; invalidates history links. |
| [`0x1a0c0`](evidence/decompiled/14001a0c0.c) | HistoryAgeAndRecycle | S/H | history | Recycles bounded/aged records; time scale is unmeasured. |
| [`0x1a2a0`](evidence/decompiled/14001a2a0.c) | HistoryCaptureActor | S/H | history | Selective actor-event capture; includes capacity/decimation policy. |
| [`0x1aac0`](evidence/decompiled/14001aac0.c) | HistoryEncodeStateRecord | H | history | Record encoder; exact format and inverse/restore contract remain open. |
| [`0x1adc0`](evidence/decompiled/14001adc0.c) | HistoryEncodeEventRecord | H | history | Record encoder; not accepted as a network packet. |
| [`0x1b010`](evidence/decompiled/14001b010.c) | HistoryEncodeAuxRecord | H | history | Auxiliary history record path; ownership and inverse remain open. |
| [`0x1ddc0`](evidence/decompiled/14001ddc0.c) | DecodeHistoryPoseRecord | S/H | history | Decodes tag-specific record fields into an intermediate pose/state block; units and orientation representation remain open. |
| [`0x1df10`](evidence/decompiled/14001df10.c) | InterpolateHistoryPose | S/H | history | Interpolates decoded position and orientation using record times; not a full integrator or rollback restore. |
| [`0xc04e0`](evidence/decompiled/1400c04e0.c) | TargetSlotLimitUpdate | S/H | targeting | Changes retained target slots and actor flags; four explicit slots observed. |
| [`0xc1030`](evidence/decompiled/1400c1030.c) | TargetSlotClear | S/H | targeting | Clears target selector pairs and corresponding actor flags. |
| [`0xc11c0`](evidence/decompiled/1400c11c0.c) | TargetSelectionStep | H | targeting | Player target-selection substate; full selection semantics need tracing. |
| [`0xc2630`](evidence/decompiled/1400c2630.c) | TargetOptionBitA | S | targeting | Updates local flag bits; semantic name intentionally unresolved. |
| [`0xc2680`](evidence/decompiled/1400c2680.c) | TargetOptionBitB | S | targeting | Updates local flag bits; semantic name intentionally unresolved. |
| [`0xc4660`](evidence/decompiled/1400c4660.c) | PlayerContextInitialize | S/H | player | Initializes a player context and subobjects; not safe to memcpy. |
| [`0xc6a50`](evidence/decompiled/1400c6a50.c) | AllocatePlayerResources | S | player | Count-based player/resource allocation; ten ABI positions, arrays and arena lifetime matter. |
| [`0xc70e0`](evidence/decompiled/1400c70e0.c) | PlayerResourceLoadContinue | H | player | Resource/setup continuation; requires loaded assets and native ordering. |
| [`0xc7f90`](evidence/decompiled/1400c7f90.c) | MissionResourceSelectA | H | campaign | Campaign/VS resource selection path; asset meanings need game data. |
| [`0xc9690`](evidence/decompiled/1400c9690.c) | MissionResourceSelectB | H | campaign | Second setup resource path, not a proven spawn API. |
| [`0xcbcc0`](evidence/decompiled/1400cbcc0.c) | WireWorldAndPlayers | S/H | campaign | Constructs and wires world resources; stock binding uses group i, actor 0 for player i. |
| [`0xcd880`](evidence/decompiled/1400cd880.c) | WorldStartOrReset | H | campaign | Resets mission/player/actor state; not established as a complete checkpoint restore. |
| [`0xce880`](evidence/decompiled/1400ce880.c) | ActiveWorldPlayerStep | S/H | simulation | Processes mission branches, player contexts, group updates and history; contains pause gates. |
| [`0xd03a0`](evidence/decompiled/1400d03a0.c) | SpecialViewMissionBranch | H | camera | Special mission/camera branch; not a network synchronization function. |
| [`0xd0c40`](evidence/decompiled/1400d0c40.c) | MissionSubstateReset | H | campaign | Walks actor/player state and resets subsystems; broad side effects. |
| [`0xd1780`](evidence/decompiled/1400d1780.c) | MissionStateDriver | S/H | simulation | Called by campaign and VS after setup readiness; drives special states and active world step. |
| [`0xd2580`](evidence/decompiled/1400d2580.c) | WorldScenePacketBuild | S/H | render | Gameplay scene/display-list construction; avoid authoritative simulation writes here. |
| [`0xd46a0`](evidence/decompiled/1400d46a0.c) | MissionControlFlagUpdate | H | campaign | Count-based state/flag update; full semantics require traces. |
| [`0xd4c40`](evidence/decompiled/1400d4c40.c) | MissionPresentationBranch | H | camera | Special UI/view/game-state branch invoking player processing; not a save-state loader. |
| [`0x102540`](evidence/decompiled/140102540.c) | WeaponCooldownStep | S/H | weapon | Decrements a timer and reloads it from per-weapon values when a flag is set. |
| [`0x1040c0`](evidence/decompiled/1401040c0.c) | PlayerControlAndViewStep | S/H | player | Large mixed player/control/view/weapon path; action slot and actor binding are explicit. |
| [`0x10b000`](evidence/decompiled/14010b000.c) | PlayerPresentationStateBuild | H | player | Copies flight/weapon/target state into presentation data; not a network serializer. |
| [`0x10c9a0`](evidence/decompiled/14010c9a0.c) | PlayerWeaponHitQueryPath | H | weapon | Walks actors/targets and effects; trace launch/hit ownership before use. |
| [`0x10e220`](evidence/decompiled/14010e220.c) | PlayerControlSubstateReset | H | player | Called by several death/pause/special paths; broader than a camera toggle. |
| [`0x10ead0`](evidence/decompiled/14010ead0.c) | PlayerPostStepConstraints | H | player | Touches movement/transform and constraints; not the complete flight integrator contract. |
| [`0x111d40`](evidence/decompiled/140111d40.c) | PlayerInputSubstateStep | H | player | Uses logical input slot and updates a player subobject; inferred vector types are unreliable. |
| [`0x115c20`](evidence/decompiled/140115c20.c) | ActorLifecycleAux | H | entity | Participates in actor state/death behavior; not a recovered free/despawn contract. |
| [`0x117a10`](evidence/decompiled/140117a10.c) | ActorDeathEffectsAndState | S/H | damage | Lethal-state/effect path; does not prove object destruction or pool release. |
| [`0x118040`](evidence/decompiled/140118040.c) | ApplyActorDamage | S/H | damage | Damage scaling/guards, health subtraction, attribution, score and recursive effects. |
| [`0x12bf60`](evidence/decompiled/14012bf60.c) | MissionControllerStep | H | campaign | Mission-controller subobject update; VM/event semantics remain a separate gate. |
| [`0x12c410`](evidence/decompiled/14012c410.c) | SizeGroupActorResources | S/H | entity | Includes actor_count * 0x520 and resource-dependent storage. |
| [`0x12c520`](evidence/decompiled/14012c520.c) | UnitInitializeActors | S/H | entity | Unit vtable slot 0 initializes actor storage/selectors/resources; not a standard destructor slot. |
| [`0x12c740`](evidence/decompiled/14012c740.c) | UnitResetActors | S/H | entity | Unit vtable slot 8 resets actors and data-driven controls. |
| [`0x132240`](evidence/decompiled/140132240.c) | UnitUpdateActors | S/H | entity | Unit vtable slot 0x10; substantial actor/gameplay update with side effects. |
| [`0x1338c0`](evidence/decompiled/1401338c0.c) | UnitRelationshipDamageStep | S/H | entity | Category/proximity path can apply damage; client authority gates must cover it. |
| [`0x135b50`](evidence/decompiled/140135b50.c) | SizeInitialGroupArena | S | entity | Sizes initial group table/objects and actor resources from definitions. |
| [`0x135cb0`](evidence/decompiled/140135cb0.c) | ConstructInitialGroups | S | entity | Builds initial groups from definitions and invokes specialized initialization; not runtime spawn. |
| [`0x1363c0`](evidence/decompiled/1401363c0.c) | DispatchGroupUpdates | S | entity | Group virtual-update loop, actor stamping and periodic relationship pass. |
| [`0x13ace0`](evidence/decompiled/14013ace0.c) | LaunchScatterPool32 | S/H | weapon | Selects one of 32 mask-owned 0x38-byte slots; two RNG draws, source selectors and subtype-2 history record; gun-like semantics need tracing. |
| [`0x13d140`](evidence/decompiled/14013d140.c) | LaunchProjectilePool16 | S/H | weapon | Selects one of 16 mask-owned 0x58-byte slots, source/target selectors, resource pointer and subtype-0 history record; return -1 on exhaustion. |
| [`0x141200`](evidence/decompiled/140141200.c) | DispatchWeaponFamilyLaunch | S/H | weapon | Chooses weapon controller by type byte and calls virtual +0x38; records subtype 1 on accepted launch; inferred float/register ABI remains open. |
| [`0x16d940`](evidence/decompiled/14016d940.c) | InitializeWorldState | S/H | campaign | Initializes the 0xA8940-byte world storage and embedded subsystems. |
| [`0x16e0b0`](evidence/decompiled/14016e0b0.c) | CampaignControlEnter | S | lifecycle | Allocates world/view storage and writes lifecycle diagnostic; original call and arena rules matter. |
| [`0x16e4c0`](evidence/decompiled/14016e4c0.c) | CampaignControlLeave | S/H | lifecycle | Copies result state and releases arena state; invalidate network work before lifetime ends. |
| [`0x16e880`](evidence/decompiled/14016e880.c) | CampaignControlUpdate | S | lifecycle | Runs 18 setup phases until ready, then mission driver and transition checks. |
| [`0x16e9b0`](evidence/decompiled/14016e9b0.c) | GameControlAuxiliary | S/H | lifecycle | Shares campaign/VS auxiliary render path after readiness. |
| [`0x16eb20`](evidence/decompiled/14016eb20.c) | CampaignLoadoutSetup | S | campaign | Selects count/loadouts and passes ten initializer positions; P2 data is not automatic. |
| [`0x16ef50`](evidence/decompiled/14016ef50.c) | CampaignWorldSetup | S/H | campaign | Sets campaign options before common world wiring/reset. |
| [`0x16f080`](evidence/decompiled/14016f080.c) | CampaignControlOptions | S/H | campaign | Applies per-player mappings/options after world setup. |
| [`0x16f470`](evidence/decompiled/14016f470.c) | VSControlEnter | S | lifecycle | Calls common enter then applies VS-specific mode transition setup. |
| [`0x16f4c0`](evidence/decompiled/14016f4c0.c) | VSControlLeave | S | lifecycle | Additional VS cleanup followed by common leave. |
| [`0x16f550`](evidence/decompiled/14016f550.c) | VSControlUpdate | S | lifecycle | 15 setup phases, shared mission driver, distinct return modes. |
| [`0x16f6c0`](evidence/decompiled/14016f6c0.c) | VSLoadoutSetup | S | campaign | Explicitly prepares two player selections for AllocatePlayerResources. |
| [`0x16f860`](evidence/decompiled/14016f860.c) | VSWorldSetup | S/H | campaign | VS options, shared world wiring/reset, different rule configuration. |
| [`0x16fa80`](evidence/decompiled/14016fa80.c) | VSControlOptions | S/H | campaign | Per-player mappings plus VS limits/options; do not transplant whole body into campaign. |
| [`0x16ff00`](evidence/decompiled/14016ff00.c) | GameEndEnter | S/H | lifecycle | Return/selector transition root; complete save authority remains open. |
| [`0x16fff0`](evidence/decompiled/14016fff0.c) | GameEndUpdate | S/H | lifecycle | Result/return sequence selection; not a replicated campaign commit API. |
| [`0x179120`](evidence/decompiled/140179120.c) | VSControlConstruct | S | lifecycle | Constructs mode with VS vtable, zero readiness and setup index. |
| [`0x1796f0`](evidence/decompiled/1401796f0.c) | CampaignControlConstruct | S | lifecycle | Constructs 32-byte mode with campaign vtable and reset setup state. |
| [`0x187390`](evidence/decompiled/140187390.c) | ComputeInputEdgesAndRepeat | S | input | Builds pressed-edge/previous/repeat bitmaps from held state. |
| [`0x187c80`](evidence/decompiled/140187c80.c) | QueryActionPressed | S/H | input | AL boolean; DL logical player slot, R8B action; RCX unused in recovered body. |
| [`0x187ec0`](evidence/decompiled/140187ec0.c) | QueryActionMagnitude | H | input | Related mapped analog/action query; exact return units/ABI need validation. |
| [`0x188180`](evidence/decompiled/140188180.c) | BuildAndSelectInputDevices | S | input | 0x50-byte device records and two logical selections at +0x140/+0x148. |
| [`0x188550`](evidence/decompiled/140188550.c) | ConvertRawLaneToActions | S | input | RCX low-16 buttons, RDX raw lane, R8 output; scalar storage annotation applied. |
| [`0x188a80`](evidence/decompiled/140188a80.c) | PollAndNormalizeTwoInputLanes | S | input | Raw lanes stride 0x24; candidate remote-input injection after native polling. |
| [`0x1b6480`](evidence/decompiled/1401b6480.c) | PrepareHistoryPlaybackWindow | S/H | history | Chooses bounded playback window and record cursors, writes actor state/HP=255 and builds replay actor list; not exact live-world restore. |
| [`0x1b7480`](evidence/decompiled/1401b7480.c) | HistoryPlaybackWorldStep | S/H | history | Mission-driver playback branch invokes recorded-state application then mirrors actor pose into player context; retains group-i binding assumption. |
| [`0x1b7ce0`](evidence/decompiled/1401b7ce0.c) | CaptureWorldHistory | S/H | history | Traverses actor state, records selected events and copies previous vectors. |
| [`0x1b8130`](evidence/decompiled/1401b8130.c) | EnterOrRestartHistoryPlayback | S/H | history | Saves selected player/world fields on first entry, resets effects/controllers and prepares playback cursors; broad side effects. |
| [`0x1b9400`](evidence/decompiled/1401b9400.c) | ApplyAndInterpolateHistoryWorld | S/H | history | Writes actor/player pose/flags and replays weapon/death/effect events; pointer-bearing records and no complete rollback proof. |
| [`0x1eda90`](evidence/decompiled/1401eda90.c) | BroadcastUIControlPlayer | S | ui | Broadcasts an integer to registered UI listeners; not proven aircraft ownership. |
| [`0x1ef650`](evidence/decompiled/1401ef650.c) | UIZeroResultStub | S | ui | Writes zero to the result pointer; getMissionTime/getMissionScore bindings are misleading. |
| [`0x1ef7b0`](evidence/decompiled/1401ef7b0.c) | UISetControlPlayerBinding | S | ui | Tail wrapper forwarding R9 argument data to the UI broadcast. |
| [`0x1f51a0`](evidence/decompiled/1401f51a0.c) | UIVSPlayerStateBinding | H | ui | VS menu binding; not a network-state serialization API. |
| [`0x1fbec0`](evidence/decompiled/1401fbec0.c) | UpdateCameraMatrices | S/H | camera | Existing camera matrix builder; local presentation ownership must be maintained. |
| [`0x1ff820`](evidence/decompiled/1401ff820.c) | InputModeAndRenderFrame | S | simulation | Pumps input then virtual mode update/auxiliary dispatch; broader than simulation tick. |
| [`0x200c00`](evidence/decompiled/140200c00.c) | OuterFrameCaller | S/H | simulation | Direct caller of the frame driver; timing and scheduling need runtime traces. |
| [`0x201dc0`](evidence/decompiled/140201dc0.c) | PumpNormalizeAndBindInput | S | input | Raw poll, device rebuild, logical action-map binding and feedback update. |
| [`0x21d4c0`](evidence/decompiled/14021d4c0.c) | AggregatePlatformInput | S/H | input | Steam/controller/platform aggregation and lifecycle-mirror checks. |
| [`0x242630`](evidence/decompiled/140242630.c) | CrtStyleRand | S | determinism | LCG state from CRT thread context +0x28; 271 indexed call sites. |
| [`0x24265c`](evidence/decompiled/14024265c.c) | CrtStyleSeed | S | determinism | Writes seed to the same thread-context field; not a fixed module-global pointer. |

## Unrecovered/new contracts

| Capability | Current result | Implementation consequence |
| --- | --- | --- |
| Online session/send/receive/replication | No accepted gameplay networking contract | New transport and protocol |
| Safe arbitrary runtime spawn/despawn | Initial constructors and death effects recovered; release/reuse closure open | RE07 blocks entity replication |
| Complete snapshot/rollback | Selective history/event pools only | No join-in-progress/rollback promise |
| Campaign P2 actor definitions | Asset format/content not supplied | RE05/RE06 must precede networking |
| Typed flight integrator state | Several movement/control seams; full dependency closure open | No pose-only correctness claim |
| Complete mission VM/commit/save API | Lifecycle/result roots recovered; semantic closure open | RE12/RE17 block campaign certification |

The full selected-function ledger is [here](../../usage/FUNCTION_REVIEW_LEDGER.md).
All required contracts and experiments are tracked in [the plan](../../mp/REVERSE_ENGINEERING_PLAN.md).
