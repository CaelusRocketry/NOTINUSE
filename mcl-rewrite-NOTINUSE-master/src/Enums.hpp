#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <string>

namespace caelus {

using std::string;

enum class SolenoidState {
	CLOSED = 0,
	OPEN = 1
};

string toString(SolenoidState state);

enum class SolenoidActuationType {
	NONE = 1,
	CLOSE_VENT = 2,
	OPEN_VENT = 3,
	PULSE = 4
};

string toString(SolenoidActuationType type);

enum class SolenoidActuationPriority {
	ABORT_PRIORITY = 0,
	MAX_TELEMETRY_PRIORITY = 1,
	PI_PRIORITY = 2,
	LOW_PRIORITY = 3,
	NONE = 4,
};

string toString(SolenoidActuationPriority priority);

SolenoidActuationPriority toSolenoidActuationPriority(string s);

enum class Stage {
	WAITING = 0,
	PRESSURIZATION = 1,
	AUTOSEQUENCE = 2,
	POSTBURN = 3,
};

string toString(Stage stage);

Stage nextStage(Stage stage);

enum class SensorStatus {
	SAFE = 3,
	WARNING = 2,
	CRITICAL = 1
};

string toString(SensorStatus status);

}

#endif