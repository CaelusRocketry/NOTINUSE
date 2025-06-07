#include <set>
#include <ArduinoJson.h>
#include <flight/modules/lib/logger_util.hpp>
#include <flight/modules/mcl/Supervisor.hpp>
#include <flight/modules/tasks/SensorTask.hpp>
#include <flight/modules/tasks/TelemetryTask.hpp>
#include <flight/modules/tasks/ValveTask.hpp>
#include <flight/modules/lib/Util.hpp>
#include <flight/modules/mcl/Config.hpp>
#include <flight/modules/lib/ConfigString.hpp>

#ifndef DESKTOP
    #include "Arduino.h"
#endif


Supervisor::~Supervisor() {
    delete control_task;

    for (auto task : tasks) {
        delete task;
    }
}

void Supervisor::initialize() {
    /* Load config */

    Util::doc.clear();
    deserializeJson(Util::doc, CONFIG_STR);
    JsonObject j = Util::doc.as<JsonObject>();

    global_config = Config(j);
    global_registry.initialize();

    print("Supervisor: Parsing config");
    parse_config();

    print("Tasks: Initializing");
    for (Task* task : tasks){
        task->initialize();
    }

    print("Control tasks: Initializing");
    control_task->begin();
    last_blink_time = (int)Util::getTime();
}

void Supervisor::read() {
    print("Supervisor: Reading");
    for (Task* task : tasks){
        task->read();
    }
}

void Supervisor::control() {
    print("Supervisor: Controlling");
    control_task->control();
}

void Supervisor::actuate() {
    print("Supervisor: Actuating");
    for (Task* task : tasks){
        task->actuate();
    }
}

void Supervisor::run() {
    while (true) {
        // double delay = global_config.timer.delay;
        // Serial.println(delay);
        // Serial.println("HELLOO");
        // Serial.println(millis());
        // double delay = 0;
        // long double start_time = Util::getTime();
        print("------------------ITERATION------------------");
        // print(Util::getTime());
        if((int)Util::getTime - last_blink_time > 1000){
            ledState = 1 - ledState;
            #ifndef DESKTOP
                digitalWrite(13, ledState);
            #endif
            last_blink_time = (int)Util::getTime();
        }
        read();
        control();
        actuate();
        // temp placeholder for TimerControl
        // print("TIME: " + Util::to_string((int)Util::getTime()));
        // Util::pause(500);
        // long double end_time = Util::getTime();
        // long double diff = end_time - start_time;
        // if(delay > diff){
        //     Util::pause(delay - diff);
        // }
        // Serial.println(millis());
        // Serial.println("WHATSUPPPP");
    }
}

void Supervisor::parse_config() {
    // parse_json_list automatically parses config.json
    for (const string& task : global_config.task_config.tasks) {
        print("Found task: " + task);
        if (task == "sensor") tasks.push_back(new SensorTask());
        if (task == "telemetry") tasks.push_back(new TelemetryTask());
        if (task == "valve") tasks.push_back(new ValveTask());
    }

    set<string> control_tasks;
    for (const string& control_task : global_config.task_config.control_tasks) {
        control_tasks.insert(control_task);
        print("Control task [" + control_task + "]: Enabled");
    }

    control_task = new ControlTask(control_tasks);
}