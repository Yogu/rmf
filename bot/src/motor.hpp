#ifndef MOTOR_H
#define MOTOR_H

#include <ESP8266WiFi.h>

class Motor {
    public:
        Motor(int port1, int port2): port1(port1), port2(port2) { init(); }
        static const int MAX_SPEED = 1024;
        void setSpeed(int newSpeed);
        int getSpeed();
        
    private:
        int speed = 0;
        int port1;
        int port2;
        void init();
        void setOutputs(int value1, int value2);
};

#endif // MOTOR_H
