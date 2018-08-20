#include "stepper.hpp"

void Stepper::init() {
    pinMode(port1, OUTPUT);
    pinMode(port2, OUTPUT);
    pinMode(port3, OUTPUT);
    pinMode(port4, OUTPUT);
    setSpeed(0);
}

int Stepper::getSpeed()
{
    return speed;
}

void Stepper::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

int Stepper::getDelay(int speed)
{
    return 1000 / speed;
}

void Stepper::doSequence()
{
    int sp = speed;
    if (sp > -10 && sp < 10) {
        delay(100);
        return;
    }

    if (sp < 0) {
        doSequenceBackwards(-sp);
    }
    else
    {
        doSequenceForward(sp);
    }
}

void Stepper::doSequenceForward(int sp) {
    setOutputs(HIGH, LOW, LOW, LOW, sp);
    setOutputs(HIGH, HIGH, LOW, LOW, sp);
    setOutputs(LOW, HIGH, LOW, LOW, sp);
    setOutputs(LOW, HIGH, HIGH, LOW, sp);
    setOutputs(LOW, LOW, HIGH, LOW, sp);
    setOutputs(LOW, LOW, HIGH, HIGH, sp);
    setOutputs(LOW, LOW, LOW, HIGH, sp);
    setOutputs(HIGH, LOW, LOW, HIGH, sp);
}

void Stepper::doSequenceBackwards(int sp) {
    setOutputs(HIGH, LOW, LOW, HIGH, sp);
    setOutputs(LOW, LOW, LOW, HIGH, sp);
    setOutputs(LOW, LOW, HIGH, HIGH, sp);
    setOutputs(LOW, LOW, HIGH, LOW, sp);
    setOutputs(LOW, HIGH, HIGH, LOW, sp);
    setOutputs(LOW, HIGH, LOW, LOW, sp);
    setOutputs(HIGH, HIGH, LOW, LOW, sp);
    setOutputs(HIGH, LOW, LOW, LOW, sp);

}

void Stepper::setOutputs(int a, int b, int c, int d, int sp)
{
  digitalWrite(port1, a);
  digitalWrite(port2, b);
  digitalWrite(port3, c);
  digitalWrite(port4, d);
  delay(getDelay(sp));
}
