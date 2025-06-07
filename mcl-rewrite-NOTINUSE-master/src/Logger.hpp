#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <vector>

#include "Enums.hpp"

namespace caelus {
	using std::string;
	using std::vector;

	class Logger {
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