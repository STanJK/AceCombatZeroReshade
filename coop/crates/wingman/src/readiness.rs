use crate::{CameraSource, WingmanSnapshot};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Blocker {
    NotCampaign,
    OriginalRoleUnverified,
    NoBoundHelperActor,
    AmbiguousHelperActors,
    NoSecondPlayer,
    WrongPlayerBinding,
    NoTwoPlayerViews,
    EventPolicyUnverified,
    GuestLifecycleUnimplemented,
    AiExclusionUnimplemented,
    ActorIndexAdaptationUnimplemented,
    SelectionFlowUnimplemented,
}
impl Blocker {
    pub fn code(self) -> &'static str {
        match self {
            Self::NotCampaign => "not_campaign",
            Self::OriginalRoleUnverified => "original_role_unverified",
            Self::NoBoundHelperActor => "no_bound_helper_actor",
            Self::AmbiguousHelperActors => "ambiguous_helper_actors",
            Self::NoSecondPlayer => "no_second_player",
            Self::WrongPlayerBinding => "wrong_player_binding",
            Self::NoTwoPlayerViews => "no_two_player_views",
            Self::EventPolicyUnverified => "event_policy_unverified",
            Self::GuestLifecycleUnimplemented => "guest_lifecycle_unimplemented",
            Self::AiExclusionUnimplemented => "ai_exclusion_unimplemented",
            Self::ActorIndexAdaptationUnimplemented => "actor_index_adaptation_unimplemented",
            Self::SelectionFlowUnimplemented => "selection_flow_unimplemented",
        }
    }
}
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Readiness {
    pub candidate_index: Option<u8>,
    pub blockers: Vec<Blocker>,
}
impl Readiness {
    pub fn native_takeover_ready(&self) -> bool {
        self.blockers.is_empty()
    }
}
/// Report native evidence and outstanding implementation gates. Never authorizes writes.
pub fn assess(s: &WingmanSnapshot) -> Readiness {
    let mut blockers = Vec::new();
    if !s.campaign {
        blockers.push(Blocker::NotCampaign)
    }
    // Static topology alone cannot identify Pixy/PJ across missions.
    blockers.push(Blocker::OriginalRoleUnverified);
    let mut bound = s
        .candidates
        .iter()
        .filter(|c| c.helper_bound && c.model_bound && !c.foreign_human_link);
    let first = bound.next();
    let candidate = if bound.next().is_some() {
        blockers.push(Blocker::AmbiguousHelperActors);
        None
    } else {
        first
    };
    if first.is_none() {
        blockers.push(Blocker::NoBoundHelperActor)
    }
    if s.player_count != 2 {
        blockers.push(Blocker::NoSecondPlayer)
    }
    if let Some(c) = candidate {
        if s.player_selectors.first() != Some(&[0, 0])
            || s.player_selectors.get(1) != Some(&[0, c.actor_index])
            || c.human_slot != Some(1)
        {
            blockers.push(Blocker::WrongPlayerBinding);
        }
    }
    if !(0..2).all(|slot| {
        s.views
            .iter()
            .any(|v| v.owner == slot as u32 && v.source == CameraSource::Player(slot))
    }) {
        blockers.push(Blocker::NoTwoPlayerViews);
    }
    blockers.extend([
        Blocker::EventPolicyUnverified,
        Blocker::GuestLifecycleUnimplemented,
        Blocker::AiExclusionUnimplemented,
        Blocker::ActorIndexAdaptationUnimplemented,
        Blocker::SelectionFlowUnimplemented,
    ]);
    Readiness {
        candidate_index: candidate.map(|c| c.actor_index),
        blockers,
    }
}
