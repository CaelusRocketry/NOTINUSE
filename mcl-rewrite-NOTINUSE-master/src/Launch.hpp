#ifndef LAUNCH_HPP
#define LAUNCH_HPP

#include <map>
#include <queue>

namespace caelus
{
	class Launch;
}

#include "Enums.hpp"

#include "Config.hpp"
#include "Logger.hpp"
#include "PressureSensorController.hpp"
#include "Solenoid.hpp"
#include "SolenoidController.hpp"
#include "StageController.hpp"
#include "Store.hpp"
#include "TelemetryController.hpp"

namespace caelus
{
	using std::map;
	using std::priority_queue;
	using std::string;

	typedef struct SolenoidActuationTask
	{
		SolenoidActuationPriority priority;
		string id;
		SolenoidActuationType type;
	} SolenoidActuationTask;

	bool operator<(const SolenoidActuationTask &a, const SolenoidActuationTask &b);

	class Launch
	{
	private:
		priority_queue<SolenoidActuationTask> solenoidActuationQueue;

		double startTime = 0;

		Stage stage = Stage::WAITING;
		int stageCompletionProgress = 0;
		double stageUpdateInterval;
		bool softAborting = false;
		bool progressPending = false;

		Store *store;
		Logger *logger;
		PressureSensorController *pressureSensorController;
		SolenoidController *solenoidController;
		StageController *stageController;
		TelemetryController *telemetryController;

		void actuateSolenoid(
				string solenoidID,
				SolenoidActuationPriority priority,
				SolenoidActuationType type);

		void readSensorMeasurements();
		void uploadSensorMeasurements();
		void executeSolenoidActuations();
		void executeSingleTick();

	public:
		Launch(Config config);

		void enqueueSolenoidActuation(string id, SolenoidActuationPriority priority, SolenoidActuationType type);

		void loop();

		double getStageUpdateInterval() const;

		void setStage(Stage stage);
		Stage getStage() const;

		void setSoftAborting(bool softAborting);
		bool isSoftAborting() const;

		void setStageCompletionProgress(int progress);
		int getStageCompletionProgress() const;

		bool isProgressPending() const;
		void setProgressPending(bool pending);

		Store *getStore() const;
		Logger *log() const;

		double getStartTime() const;
	};
} // namespace caelus

#endif
