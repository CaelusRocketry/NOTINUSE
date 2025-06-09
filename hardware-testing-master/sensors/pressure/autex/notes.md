# Running the code

Run the autex.ino file w/ the Arduino wired up (wiring explained below) and the Arduino plugged in to the computer.

Before you run the code, make sure that the `MIN_PSI`, `MAX_PSI`, `MIN_VOLTAGE`, and `MAX_VOLTAGE` are set (at the top of the code) based on the pressure sensor. MIN_PSI will probably be 0 and MAX_PSI should be labeled on the pressure transducer itself. `MIN_VOLTAGE` and `MAX_VOLTAGE` can prolly be found somewhere either on the sensor itself or in the Amazon description.


# Wiring

There should be 2 wires coming out of the pressure transducer: red, black, and green.

The wiring should be as follows:

Sensor | Arduino
--- | ---
Red | 5V
Black | GND
Green | A1
