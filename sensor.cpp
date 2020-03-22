#include "sensor.h"
#include <iostream>

Sensor::Sensor()
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(measure()));
    //QObject::connect(&timer, &QTimer::timeout, this, QOverload<>::of(&Sensor::measure));
    timer.start(10);
}
void Sensor::measure()
{

    std::cout<<"measue"<<std::endl;
    emit newMeasure(3.45);
}
void Sensor::updatePosition(Position pos)
{
    position = pos;
}
