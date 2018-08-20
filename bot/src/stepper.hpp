#ifndef STEPPER_H
#define STEPPER_H

#include <ESP8266WiFi.h>

class Stepper {
    public:
        Stepper(int port1, int port2, int port3, int port4): port1(port1), port2(port2), port3(port3), port4(port4) { init(); }
        static const int MAX_SPEED = 1023;
        void setSpeed(int newSpeed);
        int getSpeed();
        void doSequence();
        
    private:
        int speed = 0;
        int port1;
        int port2;
        int port3;
        int port4;
        void init();
        int getDelay(int sp);
        void doSequenceForward(int sp);
        void doSequenceBackwards(int sp);
        void setOutputs(int value1, int value2, int value3, int value4, int sp);
};

#endif // STEPPER_H
