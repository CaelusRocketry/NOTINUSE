#ifndef COMPRESSIONLOGGER_HPP
#define COMPRESSIONLOGGER_HPP

#include "Logger.hpp"

#include <iostream>

namespace caelus {

enum class CompressionKey {
	CONTROLLER_INITIALIZED = 0,
	VALVE_DATA = 1,
	STAGE_DATA = 2,
	STAGE_PROGRESSION_REQUEST = 3,
	SOFT_ABORT_SUCCESS = 4,
	UNDO_SOFT_ABORT_SUCCESS = 5,
	HEARTBEAT = 6,
	SOLENOID_ACTUATION_SUCCESS = 7,
	SOLENOID_NOT_FOUND = 8,
	SOLENOID_PRIORITY_TOO_LOW = 9,
	SOLENOID_PACKET_INVALID = 10,
	SOLENOID_DATA_RESPONSE = 11,
	SENSOR_NOT_FOUND = 12,
	SENSOR_DATA_RESPONSE = 13,
	INVALID_FUNCTION_ARGUMENTS = 14,
	INVALID_FUNCTION_NAME = 15
};

class CompressionLogger : Logger {
	private:
	// class PacketWriteGuard {
	// 	public:
	// 		CompressionLogger& parent;
	// 	public:
	// 		PacketWriteGuard(CompressionLogger& parent): parent(parent) {
	// 		}
	// 		~PacketWriteGuard() {
	// 			parent.writer << "$end";
	// 		}
	// };

	std::ostream& writer = std::cout;
	void begin(CompressionKey packetKey);
	void end();

	public:
	void critical(string tag, string data);
	void info(string tag, string data);
	void warning(string tag, string data);
	void debug(string tag, string data);

	void controllerInitialized(string id);
	void sendValveData(string serialized);
	void sendStageData(string serialized);
	void stageProgressionRequest(Stage currentStage, Stage nextStage);

	void softAbortSuccess();
	void undoSoftAbortSuccess();
	void heartbeat();

	void solenoidActuationSuccess(string id, SolenoidActuationType type, SolenoidActuationPriority priority);
	void solenoidNotFound(string id);
	void solenoidPriorityTooLow(string id, SolenoidActuationType type, SolenoidActuationPriority actuationPriority);
	void solenoidPacketInvalid(string id, SolenoidActuationType type, SolenoidActuationPriority priority);
	void solenoidDataResponse(string id, SolenoidActuationType type, SolenoidActuationPriority priority, long double actuationTime);

	void sensorNotFound(string type, string id);
	void sensorDataResponse(string type, string id, SensorStatus status);

	void invalidFunctionArguments(string functionName, string args);
	void invalidFunctionName(string functionName);
};

}

#endif

//https://github.com/ProjectCaelus/mcl-rewrite