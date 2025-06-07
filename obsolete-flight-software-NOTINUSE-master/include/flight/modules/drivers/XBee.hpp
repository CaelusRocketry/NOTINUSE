#ifndef FLIGHT_XBEE_HPP
#define FLIGHT_XBEE_HPP

#include <queue>
#include <cstdio>
#include <unistd.h>
#ifndef DESKTOP
    #include <SoftwareSerial.h>
#endif

using namespace std;

class XBee  {
private:
    #ifndef DESKTOP
        // SoftwareSerial *xbee;
        HardwareSerial *xbee;
    #endif

    bool connection;
    queue<string> ingest_queue;
    string rcvd;

    // lockable object used to specify when things need exclusive access.
    bool TERMINATE_FLAG = false;


public:
    queue<string> send_queue;

    XBee();
    queue<string> read(int num_messages);
    bool write();
    void read_buffer();
    bool get_status() const;
    void reset();
    bool connect();
    void end();
};


#endif //FLIGHT_XBEE_HPP

