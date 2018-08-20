#include "motor.hpp"

void Motor::init() {
    pinMode(port1, OUTPUT);
    pinMode(port2, OUTPUT);
    setSpeed(0);
}

int Motor::getSpeed()
{
    return speed;
}

void Motor::setSpeed(int newSpeed)
{
    speed = newSpeed;
    if (newSpeed > 0)
    {
        setOutputs(0, newSpeed);
    }
    else
    {
        setOutputs(-newSpeed, 0);
    }
}

void Motor::setOutputs(int value1, int value2)
{
    analogWrite(port1, value1);
    analogWrite(port2, value2);
}
