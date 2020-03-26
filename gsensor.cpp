#include "gsensor.h"

GSensor::GSensor(Sensor * _sensor):sensor(_sensor)
{

}
Sensor* GSensor::getSensorInst()
{
    return sensor;
}
