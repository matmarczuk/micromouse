#include "mouse.h"
#include <iostream>
Mouse::Mouse()
{
    sensor1 = new Sensor();
    QObject::connect(this->sensor1,&Sensor::newMeasure,this,&Mouse::readSensor);
    QObject::connect(this,&Mouse::setNewPosition,sensor1,&Sensor::updatePosition);

}
void Mouse::readSensor(float read)
{
    std::cout<<"Read sensor is "<<read<<std::endl;
    Position posi;
    posi.x = 2;
    posi.x =5;
    posi.direction = 30;
    emit setNewPosition(posi);
}
