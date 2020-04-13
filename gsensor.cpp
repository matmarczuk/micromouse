#include "gsensor.h"
#include <qdebug.h>

GSensor::GSensor(Sensor * _sensor):sensor(_sensor)
{
    qDebug("sensor initializer");
}
Sensor* GSensor::getSensorInst()
{
    return sensor;
}
