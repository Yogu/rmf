#include "motor.hpp"

void Motor::init() {
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
