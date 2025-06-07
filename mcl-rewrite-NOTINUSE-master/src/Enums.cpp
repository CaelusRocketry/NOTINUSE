#include "Enums.hpp"

namespace caelus {
	string toString(SolenoidState state) {
		if (state == SolenoidState::CLOSED) {
			return "closed";
		} else {
			return "open";
		}
	}

	string toString(SolenoidActuationType type) {
		switch (type) {
			case SolenoidActuationType::NONE:
				return "none";
			case SolenoidActuationType::CLOSE_VENT:
				return "close_vent";
			case SolenoidActuationType::OPEN_VENT:
				return "open_vent";
			case SolenoidActuationType::PULSE:
				return "pulse";
		}
		return "invalid";
	}

	string toString(SolenoidActuationPriority priority) {
		switch (priority) {
			case SolenoidActuationPriority::ABORT_PRIORITY:
				return "abort_priority";
			case SolenoidActuationPriority::MAX_TELEMETRY_PRIORITY:
				return "max_telemetry_priority";
			case SolenoidActuationPriority::PI_PRIORITY:
				return "pi_priority";
			case SolenoidActuationPriority::LOW_PRIORITY:
				return "low_priority";
			case SolenoidActuationPriority::NONE:
				return "none";
		}
		return "invalid";
	}

	SolenoidActuationPriority toSolenoidActuationPriority(string s) {
		if (s == "ABORT_PRIORITY") {
			return SolenoidActuationPriority::ABORT_PRIORITY;
		} else if (s == "MAX_TELEMETRY_PRIORITY") {
			return SolenoidActuationPriority::MAX_TELEMETRY_PRIORITY;
		} else if (s == "PI_PRIORITY") {
			return SolenoidActuationPriority::PI_PRIORITY;
		} else if (s == "LOW_PRIORITY") {
			return SolenoidActuationPriority::LOW_PRIORITY;
		}

		return SolenoidActuationPriority::NONE;
	}

	string toString(Stage stage) {
		switch (stage) {
			case Stage::WAITING:
				return "waiting";
			case Stage::PRESSURIZATION:
				return "pressurization";
			case Stage::AUTOSEQUENCE:
				return "autosequence";
			case Stage::POSTBURN:
				return "postburn";
			default:
				return "[invalid]";
		}
	}
	
	Stage nextStage(Stage stage) {
		return static_cast<Stage>(static_cast<int>(stage) + 1);
	}

	string toString(SensorStatus status) {
		switch (status) {
			case SensorStatus::CRITICAL:
				return "critical";
			case SensorStatus::SAFE:
				return "safe";
			case SensorStatus::WARNING:
				return "warning";
		}
		return "invalid";
	}
}