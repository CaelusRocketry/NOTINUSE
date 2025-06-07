#include "TelemetryController.hpp"

#include <iostream>

#include "ArduinoJson.h"

#include "Debug.hpp"
#include "Errors.hpp"
#include "Util.hpp"

namespace caelus
{

	// TODO: add custom packet enqueuing interface to gs???
	TelemetryController::TelemetryController(Launch *launch) : launch(launch)
	{
		launch->log()->controllerInitialized("telemetry");
	}

	void TelemetryController::execute()
	{
		if (connected)
		{
			while (!packetQueue.empty())
			{
				auto packet = packetQueue.front();
				packetQueue.pop();

				for (const Log &log : packet.getLogs())
				{
					ingest(log);
				}
			}
		}
	}

	void TelemetryController::ingest(const Log &log)
	{
		string header = log.getHeader();

		if (header == "solenoid_actuate")
		{
			std::cout << "Received Solenoid Actuate";
		}

		ArduinoJson::DynamicJsonDocument logJson(1);
		deserializeJson(logJson, log.getMessage());
		ArduinoJson::DynamicJsonDocument messageJson(1);
		deserializeJson(messageJson, logJson["message"].as<string>());

		if (this->functions.find(header) == this->functions.end())
		{
			launch->log()->invalidFunctionName(header);
			return;
		}

		auto function = this->functions.at(header);
		vector<string> parameters;

		try
		{
			for (const string &argumentName : argumentOrder.at(header))
			{
				parameters.push_back(messageJson[argumentName].as<string>());
			}
		}
		catch (...)
		{
			launch->log()->invalidFunctionArguments(header, logJson["message"].as<string>());
			throw INVALID_PACKET_ARGUMENTS_ERROR();
		}

		(this->*function)(parameters); // call function which maps to the GS command sent w/ all params necessary
	}
	void TelemetryController::heartbeat(const vector<string> &args)
	{
		launch->log()->heartbeat();
	}

	void TelemetryController::softAbort(const vector<string> &args)
	{
		launch->setSoftAborting(true);
		launch->log()->softAbortSuccess();
	}

	void TelemetryController::undoSoftAbort(const vector<string> &args)
	{
		launch->setSoftAborting(false);
		launch->log()->undoSoftAbortSuccess();
	}
	void TelemetryController::actuateSolenoid(const vector<string> &args)
	{
		auto store = launch->getStore();
		auto solenoid = store->getSolenoid(args[0]);
		if (solenoid == nullptr)
		{
			launch->log()->solenoidNotFound(args[0]);
		}

		string valveID = args[0];
		SolenoidActuationType type = (SolenoidActuationType)parseInt(args[1]);
		SolenoidActuationPriority priority = (SolenoidActuationPriority)parseInt(args[2]);

		if (priority < solenoid->getActuationPriority())
		{
			launch->log()->solenoidPriorityTooLow(valveID, type, priority);
		}

		debug("telemetry", "actuating solenoid at " + valveID + " with actuation type " + toString(type));

		try
		{
			// TODO: make sure gs packets have the upper case version of the enum as the value for the actuation type

			launch->enqueueSolenoidActuation(valveID, priority, type);
		}
		catch (...)
		{
			launch->log()->solenoidPacketInvalid(valveID, type, priority);
			throw INVALID_PACKET_MESSAGE_ERROR();
		}

		launch->log()->solenoidActuationSuccess(valveID, type, priority);
	}

	void TelemetryController::requestSensorData(const vector<string> &args)
	{
		string sensorType = args[0];
		string sensorID = args[1];

		auto store = launch->getStore();
		if (sensorType == "pressure")
		{
			auto sensor = store->getPressureSensor(sensorID);
			if (sensor == nullptr)
			{
				launch->log()->sensorNotFound(sensorType, sensorID);
				throw INVALID_SENSOR_LOCATION_ERROR();
			}

			double value = sensor->getMostRecentMeasurement().value;
			double kalmanValue = sensor->getMostRecentMeasurement().value;

			launch->log()->sensorDataResponse(sensorType, sensorID, sensor->getStatus() /** data string **/);
		}
	}

	void TelemetryController::requestValveData(const vector<string> &args)
	{
		string valveType = args[0];
		string valveID = args[1];

		auto store = launch->getStore();
		if (valveType == "solenoid")
		{
			if (!store->hasSolenoid(valveID))
			{
				launch->log()->solenoidNotFound(valveID);
				throw INVALID_VALVE_LOCATION_ERROR();
			}

			auto solenoid = store->getSolenoid(valveID);

			launch->log()->solenoidDataResponse(
					valveID,
					solenoid->getActuationType(),
					solenoid->getActuationPriority(),
					now());
		}
	}

	void TelemetryController::progress(const vector<string> &args)
	{
		launch->setProgressPending(true);
	}

	void TelemetryController::test(const vector<string> &args)
	{
		debug("telemetry", "test received: " + args[0]);
	}

}