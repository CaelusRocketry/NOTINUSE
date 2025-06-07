#include "Logger.hpp"

#include <iostream>

namespace caelus {

using std::cout;
using std::cerr;

void Logger::critical(string tag, string message) {
	cerr << "[CRIT] " << tag << ": " << message;
}

void Logger::warning(string tag, string message) {
	cerr << "[WARN] " << tag << ": " << message;
}

void Logger::info(string tag, string message) {
	cout << "[INFO] " << tag << ": " << message;
}

void Logger::debug(string tag, string message) {
	cout << "[DEBUG] " << tag << ": " << message;
}

void Logger::controllerInitialized(string id) {
	info("controller initialized", id);
}

void Logger::sendValveData(string serialized) {
	info("valve data", serialized);
}

void Logger::sendStageData(string serialized) {
	info("stage data", serialized);
}

void Logger::stageProgressionRequest(Stage currentStage, Stage nextStage) {
	critical("stage progression request", toString(currentStage) + "->" + toString(nextStage));
}

void Logger::softAbortSuccess() {
	info("soft abort success", "");
}

void Logger::undoSoftAbortSuccess() {
	info("undo soft abort success", "");
}

void Logger::heartbeat() {
	info("heartbeat", "");
}

void Logger::solenoidActuationSuccess(string id, SolenoidActuationType type, SolenoidActuationPriority priority) {
	info("solenoid actuation success", id + " [" + toString(type) + "] " + toString(priority));
}

void Logger::solenoidNotFound(string id) {
	warning("solenoid not found", id);
}

void Logger::solenoidPriorityTooLow(string id, SolenoidActuationType type, SolenoidActuationPriority priority) {
	warning("solenoid priority too low", id + " [" + toString(type) + "] " + toString(priority));
}

void Logger::solenoidPacketInvalid(string id, SolenoidActuationType type, SolenoidActuationPriority priority) {
	warning("solenoid packet invalid", id + " [" + toString(type) + "] " + toString(priority));
}

void Logger::solenoidDataResponse(string id, SolenoidActuationType type, SolenoidActuationPriority priority, long double time) {
	info("solenoid data response", id + " [" + toString(type) + "] " + toString(priority));
}

void Logger::sensorNotFound(string type, string id) {
	warning("sensor not found", id + " [" + type + "]");
}

void Logger::sensorDataResponse(string type, string id, SensorStatus status) {
	info("sensor data response", id + " [" + type + "] " + toString(status));
}

void Logger::invalidFunctionArguments(string functionName, string args) {
	info("invalid function args", functionName + ": " + args);	
}

void Logger::invalidFunctionName(string functionName) {
	info("invalid function name", functionName);
}

}