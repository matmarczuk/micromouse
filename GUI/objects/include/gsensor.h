#ifndef GSENSOR_H
#define GSENSOR_H
#include "logic/Mouse/include/sensor.h"

/*!
 * \brief The GSensor class is graphic representation of sensor
 */
class GSensor
{
    Sensor *sensor;
public:
    GSensor(Sensor * _sensor);
    Sensor *getSensorInst();
};

#endif // GSENSOR_H
