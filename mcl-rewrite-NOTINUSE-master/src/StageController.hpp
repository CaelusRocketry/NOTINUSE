#ifndef STAGE_CONTROLLER_HPP
#define STAGE_CONTROLLER_HPP

#include <vector>

#include "Launch.hpp"

namespace caelus {

using std::string;
using std::vector;

const double AUTOSEQUENCE_DELAY = 5.0 * 1000;
const double POSTBURN_DELAY = 10.0 * 1000;

class StageController {
private:
    long double lastSendTime = 0;
    long double lastStageStartTime = 0;
    long double lastProgressionRequestTime = 0;
    long requestInterval = 10000;
    long sendInterval;
    bool actuatedPostburn = false;

		Launch *launch;

    int calculateStageCompletionProgress() const;
    void sendProgressionRequest();
    void sendStageData();
    void progress();
    void actuatePressureRelief();

public:
    StageController(Launch *launch);
    void execute();
};

}

#endif