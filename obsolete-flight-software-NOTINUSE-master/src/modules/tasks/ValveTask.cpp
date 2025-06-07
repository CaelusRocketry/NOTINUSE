#include <flight/modules/lib/logger_util.hpp>
#include <flight/modules/tasks/ValveTask.hpp>
#include <flight/modules/lib/Util.hpp>
#include <flight/modules/mcl/Config.hpp>


const unsigned char SEND_DATA_CMD = 255;
const unsigned char ACTUATE_CMD = 254;

void ValveTask::initialize() {
    print("Valve task: Starting");
    for (const auto& valve_type : global_config.valves.list) {
        string type = valve_type.first;
        auto valve_locations = valve_type.second;
        for (const auto& valve_location : valve_locations) {
            string location = valve_location.first;
            ConfigValveInfo valve_info = valve_location.second;
            int pin = valve_info.pin;
            pins.push_back(pin);
            pin_to_valve[pin] = make_pair(type, location);
            valve_infos.push_back(valve_info);
            valve_list.push_back(make_pair(type, location));
        }
    }
    valve_driver = new ValveDriver(valve_infos);
}

// Reads all actuation states from valve and updates registry
void ValveTask::read(){
    print("Valve task: Reading");

    for(unsigned int i = 0; i < valve_list.size(); i++){
        int pin = pins[i];
        string valve_type = pin_to_valve[pin].first;
        string valve_location = pin_to_valve[pin].second;

        // SolenoidState state = valve_driver->getSolenoidState(pin);
        // ActuationType actuation_type = valve_driver->getActuationType(pin);

        /* Update the registry NOTE: We no longer do this in read(), instead we just update registry in actuate() */ 
        // global_registry.valves[valve_type][valve_location].state = state;
        // global_registry.valves[valve_type][valve_location].actuation_type = actuation_type;
    }
}

// Given a valve type and location, return its corresponding pin number
int ValveTask::get_pin(string valve_type, string valve_loc) {
    for(int pin : pins){
        pair<string, string> valve_info = pin_to_valve[pin];
        if(valve_info.first == valve_type && valve_info.second == valve_loc){
            return pin;
        }
    }
    return -1;
}

/*
 * For each solenoid:
 *  if the actuation priority attached to that solenoid is not NONE and is greater than the current priority:
 *      allow the solenoid to be actuated
 *  else:
 *      deny the request to actuate this solenoid, revert back to the current actuation
 */
void ValveTask::actuate() {
    // printEssential("Actuating valves");

    for (const auto& valve_info : valve_list) {
        string valve_type = valve_info.first;
        string valve_location = valve_info.second;

        if (valve_type != "solenoid") {
            continue;
        }

        int pin = get_pin(valve_type, valve_location);
        FlagValveInfo target_valve_info = global_flag.valves[valve_type][valve_location];
        RegistryValveInfo current_valve_info = global_registry.valves[valve_type][valve_location];

        if (
            target_valve_info.actuation_priority != ValvePriority::NONE &&
            target_valve_info.actuation_priority >= current_valve_info.actuation_priority
        ) {

            printEssential("Running actuation on valve type: " + valve_type + ", valve location: " + valve_location + ", pin: " + Util::to_string(pin));
            printEssential("Actuation type: " + actuation_type_inverse_map.at(target_valve_info.actuation_type) + ", Actuation priority: " + valve_priority_inverse_map.at(target_valve_info.actuation_priority));

            // Send actuation signal
            valve_driver->actuate(pin, target_valve_info.actuation_type);

            if(target_valve_info.actuation_type == ActuationType::CLOSE_VENT) {
                print("closed");
                global_registry.valves[valve_type][valve_location].state = SolenoidState::CLOSED;
            }
            if(target_valve_info.actuation_type == ActuationType::OPEN_VENT) {
                print("open");
                global_registry.valves[valve_type][valve_location].state = SolenoidState::OPEN;
            }
            // Reset the flags
            global_flag.valves[valve_type][valve_location].actuation_type = ActuationType::NONE;
            global_flag.valves[valve_type][valve_location].actuation_priority = ValvePriority::NONE;

            // Send response message
            global_flag.send_packet("INF", "SAC at " + valve_type + "." + valve_location + " to " + actuation_type_inverse_map.at(target_valve_info.actuation_type) + ".");
            printEssential("Set solenoid actuation at " + valve_type + "." + valve_location + " to " + actuation_type_inverse_map.at(target_valve_info.actuation_type) + ".");
        }
    }
}