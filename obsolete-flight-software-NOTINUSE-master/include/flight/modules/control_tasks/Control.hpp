#ifndef FLIGHT_CONTROL_HPP
#define FLIGHT_CONTROL_HPP

// Parent class for all ControlTasks

class Control {
public:
    virtual void begin() = 0;
    virtual void execute() = 0;
};

#endif //FLIGHT_CONTROL_HPP
