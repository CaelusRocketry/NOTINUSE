#ifndef DESKTOP

    #ifndef FLIGHT_THERMODRIVER_HPP
    #define FLIGHT_THERMODRIVER_HPP

    #include <flight/modules/lib/Enums.hpp>
    #include <flight/modules/lib/Util.hpp>

    #include <vector>
    #include <Adafruit_MAX31856.h>

    // THESE VALUES ARE NOT CORRECT, please confirm with someone on propulsion
    #define MIN_TEMP 15
    #define MAX_TEMP 1000
    #define MIN_VOLTAGE 0.5
    #define MAX_VOLTAGE 4.5

    using namespace std;

    class ThermoDriver {
    private:
        vector<int> thermo_pins;
        vector<float> thermo_vals;
        vector<Adafruit_MAX31856*> maxthermos;

        float readSensor(int pin);

        // #ifndef DESKTOP
        //     Adafruit_MAX31856 *maxthermo;
        // #endif
    
    public:
        ThermoDriver(vector<vector<int>> pins);
        void read();
        float getThermoValue(int pin);
    };

    #endif // FLIGHT_VALVEDRIVER_HPP

#endif // DESKTOP