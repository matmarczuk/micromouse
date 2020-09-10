#include "GUI/objects/include/gsensor.h"

GSensor::GSensor(Sensor * _sensor):sensor(_sensor)
{
}

/*!
 * \brief Returns logical representation of sensor
 * \return
 */
Sensor* GSensor::getSensorInst()
{
    return sensor;
}
