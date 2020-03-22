#include "mouse.h"
#include <iostream>

Mouse::Mouse(Sensor *sensor): sensor1(sensor)
{
    QObject::connect(this->sensor1,&Sensor::newMeasure,this,&Mouse::readSensor);
    QObject::connect(this,&Mouse::setNewPosition,sensor1,&Sensor::updatePosition);
    position.x = 0;
    position.y = 0;
    position.direction = 1;
    emit setNewPosition(position);

}
void Mouse::readSensor(bool walls[3])
{
    Position posi;
    if(!walls[2])
    {
        if(this->position.direction==3)
            this->position.direction=0;
        else
            this->position.direction++;
    }
    else if(!walls[1])
    {
        //go ahead
    }
    else if(!walls[0])
    {
        if(this->position.direction==0)
            this->position.direction=3;
        else
            this->position.direction--;
    }
    else //turn around
    {
        switch(this->position.direction)
        {
            case 0:
                this->position.direction=2;
            break;
            case 1:
                this->position.direction=3;
            break;
            case 2:
                this->position.direction=0;
            break;
            case 3:
                this->position.direction=1;
            break;
        }

    }

    switch(this->position.direction)
    {
        case 0:
            this->position.x-=30;
        break;
        case 1:
            this->position.y-=30;
        break;
        case 2:
            this->position.x+=30;
        break;
        case 3:
            this->position.y+=30;
        break;

    }
        posi.x = this->position.x;
        posi.y = this->position.y;
        posi.direction = this->position.direction;

//    else //turn right
//    {
//        if(this->position.direction==3)
//            this->position.direction=0;
//        else
//            this->position.direction++;

//        posi.direction = this->position.direction;
//        posi.x = this->position.x;
//        posi.y = this->position.y;


//    }

   // std::cout<<"new position x: "<<posi.x<<" y: "<<posi.y<<" dir: "<<posi.direction<<std::endl;
    emit setNewPosition(posi);
}
