# 已实现接口、消费者与验收索引

本表对应 `coop/` 中实际存在的 Rust 接口。表中的测试名可直接传给 `cargo test` 过滤器；
默认 `cargo test --manifest-path coop/Cargo.toml --workspace --locked` 运行全部验收。
设计语义见 [INTERFACES](INTERFACES.md)，逐模块结果见 [AUDIT_LOG](AUDIT_LOG.md)。
未来的游戏写端口见 [NATIVE_MODULE_PLAN](NATIVE_MODULE_PLAN.md)，不混入本表的已实现清单。

| 模块 / 源码 | 实际入口 | 消费者与提交契约 | 关键验收测试名 |
| --- | --- | --- | --- |
| [contracts](../../../coop/crates/contracts/src/lib.rs) | `Epoch::new/next`、`EntityId::new/require_epoch`、`Pose::validate`、`Agreement::compatible`、`forward_distance`、`signed_tick_distance` | 其余核心 crate 共用类型；ID 不带原生地址；非法值先拒绝再进入状态机 | `slots_and_epochs_are_bounded`；`serial_wrap_and_half_range`；`network_pose_rejects_nan_and_degenerate_orientation`；`agreement_requires_target_and_identical_content` |
| [protocol](../../../coop/crates/protocol/src/lib.rs) | `Packet::encode/decode`、`SnapshotChunk::validate`、`Event::validate`、`Message::allowed_sender` | transport 接收完整帧后解码；明确字节布局；无 IO；精确消费载荷 | `golden_input`；`every_variant_and_every_truncation`；`reject_flags_lengths_ids_and_nonfinite_pose`；`chunk_bounds_and_empty_world`；`bounded_noise_does_not_panic` |
| [session](../../../coop/crates/session/src/lib.rs) | `Session::host_prepare/guest_prepare`、`local_ready`、`host_start/guest_start`、`host_finish/guest_follow_result`、`take_save_permit`；`InputGate::submit/consume/reset` | CLI 装配会话；连接身份转为 Role；输入每 accepted tick 消费一次；SavePermit 是一次性权限对象，尚未连接原生存档 | `readiness_and_authority`；`save_and_retry_are_single_owner_single_epoch`；`input_once_edges_future_and_stale_release`；`input_spoof_window_wrap_and_retry`；`input_queue_is_bounded_without_partial_sequence_commit` |
| [replication](../../../coop/crates/replication/src/lib.rs) | `split_snapshot`、`Assembler::push/reset`、`WorldState::apply_event/apply_snapshot/digest/reset`、`EventCursor::apply_with`、`HostIds::allocate` | CLI 使用完整 Snapshot；不会暴露半份组装；事件失败不推进游标；本地原生写事务仍另需证明 | `reversed_chunks_commit_only_when_complete`；`event_duplicate_gap_and_failure_do_not_half_commit`；`snapshot_set_and_values_are_validated_before_any_pose_write`；`retired_id_is_not_reused_and_late_attacker_can_be_inactive`；`old_replays_outside_content_window_are_stale`；`cursor_commits_after_adapter_success_only` |
| [transport](../../../coop/crates/transport/src/lib.rs) | `Psk::generate/create_file/read_file`；`AuthenticatedStream::accept_host/connect_guest/send/receive/peer_role/is_poisoned` | CLI 拥有 socket；构造器接管为阻塞流，读写各有总截止时间；认证角色不信任报文自报；任一交换错误后连接不可复用 | `authenticated_loopback_both_directions`；`owned_nonblocking_sockets_are_normalized_before_handshake`；`wrong_key_fails_both_peers`；`corrupt_mac_never_returns_a_packet_and_poisons_connection`；`oversized_and_truncated_frames_are_closed`；`authenticated_identity_cannot_send_host_events_as_guest`；`timeout_is_total_and_session_is_not_reusable` |
| [game](../../../coop/crates/game/src/lib.rs) | `MemoryReader::read_exact`；`VerifiedImage::from_pe/verify_loaded/executable_address`；`Observer::enter/observe/leave`；`require_capability` | runtime 提供 Win32 MemoryReader；CLI 仅作文件 doctor；Observer 输出本地 NativeFrame，不能直接当网络 Pose；所有游戏写能力明确拒绝 | `real_file_hash_required_and_rva_must_be_code`；`loaded_bytes_must_match_all_candidates`；`lifecycle_read_validates_binding_and_preserves_raw_orientation`；`wrong_thread_and_leave_fail_closed`；`partial_setup_never_reads_uninitialized_world_fields`；`corrected_world_subobject_pointer_matches_assembly_not_old_documentation`；`write_capabilities_are_not_inferred_from_read_success` |
| [trace](../../../coop/crates/trace/src/lib.rs) | `channel`、`TraceSender::try_record/metrics`、`TraceDrain::run` | runtime 回调只投递；独立线程编码/写盘；满队列可见丢弃；IO 错误可从 metrics 观察；空闲刷新不发生在 Hook | `queue_capacity_never_blocks_and_reports_drops`；`drain_writes_provenance_record_and_summary`；`io_failure_is_visible_to_producers`；`idle_writer_publishes_last_lifecycle_record_before_shutdown`；`invalid_capacity_is_rejected` |
| [runtime](../../../coop/crates/runtime/src/lib.rs) / [Win64](../../../coop/crates/runtime/src/windows.rs) | `ObserverConfig::parse`、`HookBackend`、`HookPlan::install/stop`；导出 `AddonInit/AddonUninit/NAME/DESCRIPTION` | ReShade API 20 装配；默认关闭原生 Hook；MinHook 仅操作本模块四个目标；尝试启用后保留 trampoline 的进程期所有权 | `config_defaults_off_and_rejects_ambiguity`；`create_failure_rolls_back_without_enabling`；`enable_failure_retains_trampolines_and_disables_only_owned_plan`；`successful_plan_is_not_reentrant`；另以实际 PE 验证导出和数据指针 |
| [cli](../../../coop/crates/cli/src/lib.rs) / [进程验收](../../../coop/crates/cli/tests/cli.rs) | `doctor`、`demo`、`model_host/model_guest`、`ModelReport::json` | 装配可移植模块，独立客机进程和系统 TCP；四次摘要相等；没有调用游戏写函数 | `two_process_authenticated_model_campaign_contract`；`altered_peer_digest_is_rejected_over_authenticated_tcp`；`digest_covers_outcomes_and_reset`；`wrong_exe_never_reports_compatible`；`unknown_command_fails_and_help_does_not_launch_game` |

## 两个装配根

CLI 通过 transport 接收 Packet，用 session 判定权限/阶段，用 replication 提交模型状态。
`agreement()` 内的内容 SHA 与任务号只是演练常量，不能作为实际游戏资源指纹。

runtime 经 ReShade 加载，只装配 game 和 trace。它没有链接 transport/session/replication，
不会在运行观察器时自动开放端口，也没有把模型世界连接到游戏内存。
未来连接这两条路径必须通过已确认的模拟线程适配器，不能把 CLI 成功输出视为游戏已接通。

## 真实代码依据

game 的指纹来自 [HOOK_CANDIDATES.json](../HOOK_CANDIDATES.json)，
生成文件保留来源 SHA。`verify_interfaces.py` 核对 workspace 的九个依赖边界、兼容摘要、
实际导出、原生关键指令及补充索引的来源。
P+1FC0、update 的 RDX 和 holder 返回值的关联见 [SOURCE_AUDIT](SOURCE_AUDIT.md)。
