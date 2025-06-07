#ifndef TELEMETRY_CONTROLLER_HPP
#define TELEMETRY_CONTROLLER_HPP

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace caelus {
	class TelemetryController;
}

#include "Launch.hpp"
#include "Packet.hpp"

namespace caelus {

using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

typedef const vector<string>& FunctionArgs;
typedef void (TelemetryController::*Function)(FunctionArgs);

const unordered_map<string, vector<string>> argumentOrder {
	{"heartbeat", {}},
	{"soft_abort", {}},
	{"undo_soft_abort", {}},
	{"solenoid_actuate", {"valve_location", "actuation_type", "priority"}},
	{"sensor_request", {"sensor_type", "sensor_location"}},
	{"valve_request", {"valve_type", "valve_location"}},
	{"progress", {}},
	{"test", {"response"}}
};

class TelemetryController {

private:
		queue<Packet> packetQueue;

		bool connected = false;

		Launch *launch;

    void ingest(const Log& log);
    void heartbeat(const vector<string>& args);
    void softAbort(const vector<string>& args);
    void undoSoftAbort(const vector<string>& args);
    void actuateSolenoid(const vector<string>& args);
    void requestSensorData(const vector<string>& args);
    void requestValveData(const vector<string>& args);
    void progress(const vector<string>& args);
    void test(const vector<string>& args);

		const unordered_map<string, Function> functions {
			{ "heartbeat", &TelemetryController::heartbeat },
			{ "soft_abort", &TelemetryController::softAbort },
			{ "undo_soft_abort", &TelemetryController::undoSoftAbort },
			{ "solenoid_actuate", &TelemetryController::actuateSolenoid },
			{ "sensor_request", &TelemetryController::requestSensorData },
			{ "valve_request", &TelemetryController::requestValveData },
			{ "progress", &TelemetryController::progress },
			{ "test", &TelemetryController::test },
		};

public:
    TelemetryController(Launch *launch);

		bool isConnected() const;
    void execute();
};

}

#endif //FLIGHT_TELEMETRYCONTROL_HPP
