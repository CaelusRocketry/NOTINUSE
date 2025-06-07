#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <vector>

#include "PressureSensor.hpp"
#include "Solenoid.hpp"
#include "Enums.hpp"

namespace caelus {

using std::string;
using std::vector;
using std::map;

struct Boundary {
    double lower, upper;
};
struct StageBoundaries {
    Boundary safe, warn;
};

struct ConfigValveInfo {
    int pin;
    string natural;
    bool special;
};

class Config {
public:
    /* Default constructor */
    Config() = default;

    struct {
        string GS_IP;
        int GS_PORT;

        string SOCKETIO_HOST;
        int SOCKETIO_PORT;

        double DELAY;

        int XBEE_RX_PIN;
        int XBEE_TX_PIN;
        int XBEE_BAUD_RATE;
    } telemetry;

    struct {
			map<string, PressureSensorConfig> pressureSensors;
			string address;
			int baud;
			double send_interval;
    } sensors;

    struct {
			map<string, Solenoid> solenoids;
			string address;
			int baud;
			double send_interval;
    } valves;

    struct {
        vector<string> list;
        double request_interval;
        double send_interval;
    } stages;

    struct {
        double delay = 1;
    } timer;

    struct {
        vector<string> active_stages;
    } pressure_control;

    struct {
        vector<string> tasks, control_tasks;
    } task_config;

    string arduino_type;
};

}

#endif //FLIGHT_CONFIG_HPP
