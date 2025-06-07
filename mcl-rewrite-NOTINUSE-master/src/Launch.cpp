#include "Launch.hpp"

#include <iostream>

#include "Debug.hpp"
#include "Util.hpp"

namespace caelus
{
	bool operator<(const SolenoidActuationTask &a, const SolenoidActuationTask &b)
	{
		return a.priority < b.priority;
	}

	Launch::Launch(Config config)
	{
		startTime = now();
		store = new Store(config);
		logger = new Logger();
		pressureSensorController = new PressureSensorController(this, store);
		// TODO sendInterval
		solenoidController = new SolenoidController(this, 0);
		stageController = new StageController(this);
		telemetryController = new TelemetryController(this);
	}

	void Launch::actuateSolenoid(
			string solenoidID,
			SolenoidActuationPriority priority,
			SolenoidActuationType type)
	{
		debug("launch", "actuating " + solenoidID);
	}

	void Launch::uploadSensorMeasurements()
	{
		debug("launch", "uploading sensor measurements");
	}

	void Launch::executeSolenoidActuations()
	{
		while (!solenoidActuationQueue.empty())
		{
			const auto &top = solenoidActuationQueue.top();
			solenoidActuationQueue.pop();

			actuateSolenoid(top.id, top.priority, top.type);
		}
	}

	void Launch::executeSingleTick()
	{
		// Read data
		readSensorMeasurements();

		// Process data
		solenoidController->execute();
		pressureSensorController->execute();
		telemetryController->execute();
		stageController->execute();

		// Execute queued tasks
		executeSolenoidActuations();
	}

	void Launch::enqueueSolenoidActuation(string id, SolenoidActuationPriority priority, SolenoidActuationType type)
	{
		SolenoidActuationTask task{
				priority,
				id,
				type};

		debug("launch", "enqueuing " + toString(i(type)) + " solenoid actuation @" + id + " with priority " + toString(i(priority)));

		solenoidActuationQueue.push(task);
	}

	void Launch::loop()
	{
		while (true)
		{
			executeSingleTick();
		}
	}

	void Launch::setStage(Stage stage)
	{
		this->stage = stage;
	}

	Stage Launch::getStage() const
	{
		return stage;
	}

	void Launch::setSoftAborting(bool softAborting)
	{
		this->softAborting = softAborting;
	}

	bool Launch::isSoftAborting() const
	{
		return softAborting;
	}

	void Launch::setStageCompletionProgress(int progress)
	{
		stageCompletionProgress = progress;
	}

	int Launch::getStageCompletionProgress() const
	{
		return stageCompletionProgress;
	}

	void Launch::setProgressPending(bool pending)
	{
		progressPending = pending;
	}

	bool Launch::isProgressPending() const
	{
		return progressPending;
	}

	Store *Launch::getStore() const
	{
		return store;
	}

	Logger *Launch::log() const
	{
		return logger;
	}

	double Launch::getStartTime() const
	{
		return startTime;
	}
}
