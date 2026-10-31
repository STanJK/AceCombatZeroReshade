//! Same-build campaign-wingman evidence. These values never grant native write permission.
#![forbid(unsafe_code)]
mod memory;
mod native;
mod readiness;
mod selection;
mod views;
pub use native::{Candidate, EventSnapshot, WingmanSnapshot, capture};
pub use readiness::{Blocker, Readiness, assess};
pub use selection::{Selection, SelectionSnapshot};
pub use views::{CameraSource, View};

#[cfg(test)]
mod tests;
