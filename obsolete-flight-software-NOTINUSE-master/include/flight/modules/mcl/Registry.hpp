#ifndef FLIGHT_REGISTRY_HPP
#define FLIGHT_REGISTRY_HPP

#include <string>
#include <map>
#include <queue>
#include <flight/modules/lib/Enums.hpp>
#include <flight/modules/lib/Log.hpp>

using namespace std;

struct RegistryValveInfo {
    SolenoidState state = SolenoidState::CLOSED;
    ActuationType actuation_type = ActuationType::NONE;
    ValvePriority actuation_priority = ValvePriority::NONE;
};

struct RegistrySensorInfo {
    double measured_value;
    double normalized_value;
    SensorStatus status;
};

class Registry {
public:
    Registry() = default;

    /**
     * Load sensor data from global_config
     * Do not call if global_config has not been created yet
     */
    void initialize();

    struct {
        bool soft_abort = false;
        Stage stage = Stage::WAITING;
        int stage_status = 0;
        int stage_progress = 0;
    } general;

    struct {
        int status = 0;
        bool resetting = false;
        priority_queue<Log, vector<Log>, Log::compareTo> ingest_queue; 
    } telemetry;

    // valve type --> valve location --> valve info
    std::map<string, std::map<string, RegistryValveInfo>> valves;
    std::map<string, std::map<string, RegistrySensorInfo>> sensors;

    bool valve_exists(const string& type, const string& location);
    bool sensor_exists(const string& type, const string& location);
};

extern Registry global_registry;

#endif //FLIGHT_REGISTRY_HPP

