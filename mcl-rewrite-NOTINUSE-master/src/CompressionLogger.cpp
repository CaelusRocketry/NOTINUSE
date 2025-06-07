#include "CompressionLogger.hpp"

#include <iostream>
#include <map>

namespace caelus
{
	int n(Stage v)
	{
		return static_cast<int>(v);
	}

	int n(SolenoidActuationPriority v)
	{
		return static_cast<int>(v);
	}

	int n(SolenoidActuationType v)
	{
		return static_cast<int>(v);
	}

	void CompressionLogger::begin(CompressionKey key)
	{
		writer << static_cast<int>(key) << ":";
	}

	void CompressionLogger::end()
	{
		writer << '\n';
	}

	void CompressionLogger::controllerInitialized(string id)
	{
		begin(CompressionKey::CONTROLLER_INITIALIZED);
		writer << id;
		end();
	}

	void CompressionLogger::sendValveData(string serialized)
	{
		begin(CompressionKey::VALVE_DATA);
		writer << serialized;
		end();
	}

	void CompressionLogger::sendStageData(string serialized)
	{
		begin(CompressionKey::STAGE_DATA);
		writer << serialized;
		end();
	}

	void CompressionLogger::stageProgressionRequest(Stage currentStage, Stage nextStage)
	{
		begin(CompressionKey::STAGE_PROGRESSION_REQUEST);
		writer << n(currentStage) << "->" << n(nextStage);
		end();
	}

	void CompressionLogger::softAbortSuccess()
	{
		begin(CompressionKey::SOFT_ABORT_SUCCESS);
		end();
	}

	void CompressionLogger::undoSoftAbortSuccess()
	{
		begin(CompressionKey::UNDO_SOFT_ABORT_SUCCESS);
		end();
	}

	void CompressionLogger::heartbeat()
	{
		begin(CompressionKey::HEARTBEAT);
		end();
	}

	void CompressionLogger::solenoidActuationSuccess(string id, SolenoidActuationType type, SolenoidActuationPriority priority)
	{
		begin(CompressionKey::SOLENOID_ACTUATION_SUCCESS);
		writer << n(type) << ":" << n(priority) << ":" << id;
		end();
	}

	void CompressionLogger::solenoidNotFound(string id)
	{
		begin(CompressionKey::SOLENOID_NOT_FOUND);
		writer << id;
		end();
	}

	void CompressionLogger::solenoidPriorityTooLow(string id, SolenoidActuationType type, SolenoidActuationPriority priority)
	{
		begin(CompressionKey::SOLENOID_PRIORITY_TOO_LOW);
		writer << n(type) << ":" << n(priority) << ":" << id;
		end();
	}

	void CompressionLogger::solenoidPacketInvalid(string id, SolenoidActuationType type, SolenoidActuationPriority priority)
	{
		begin(CompressionKey::SOLENOID_PACKET_INVALID);
		writer << n(type) << ":" << n(priority) << ":" << id;
		end();
	}

	void CompressionLogger::solenoidDataResponse(string id, SolenoidActuationType type, SolenoidActuationPriority priority, long double actuationTime)
	{
		begin(CompressionKey::SOLENOID_DATA_RESPONSE);
		writer << n(type) << ":" << n(priority) << ":" << id << ":" << actuationTime;
		end();
	}

	void CompressionLogger::sensorNotFound(string type, string id)
	{
		begin(CompressionKey::SENSOR_NOT_FOUND);
		writer << type << ":" << id;
		end();
	}

	void CompressionLogger::sensorDataResponse(string type, string id, SensorStatus status)
	{
		begin(CompressionKey::SENSOR_DATA_RESPONSE);
		writer << type << ":" << id << ":" << static_cast<int>(status);
		end();
	}

	void CompressionLogger::invalidFunctionArguments(string function, string args)
	{
		begin(CompressionKey::INVALID_FUNCTION_ARGUMENTS);
		writer << function << "(" << args << ")";
		end();
	}

	void CompressionLogger::invalidFunctionName(string function)
	{
		begin(CompressionKey::INVALID_FUNCTION_NAME);
		writer << function;
		end();
	}
}
