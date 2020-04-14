#include "mouse.h"
#include <iostream>
#include "cell.h"

Mouse::Mouse(Sensor *sensor): sensor1(sensor), boardMap(new Boardmap)
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
    bool board_wall[4];
    int x_cell = this->position.x/CELL_SIZE;
    int y_cell = this->position.y/CELL_SIZE;
    if(!boardMap->checkIsCellVisited(x_cell,y_cell))
    {
        convertWallCoordinates(walls,board_wall);
        boardMap->addCell(x_cell,y_cell, board_wall);
    }



    Position posi;
    if(!walls[2]) //turn right
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
    else if(!walls[0]) //turn left
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
            this->position.x-=CELL_SIZE;
        break;
        case 1:
            this->position.y-=CELL_SIZE;
        break;
        case 2:
            this->position.x+=CELL_SIZE;
        break;
        case 3:
            this->position.y+=CELL_SIZE;
        break;

    }
        posi.x = this->position.x;
        posi.y = this->position.y;
        posi.direction = this->position.direction;




    emit setNewPosition(posi);
}
void Mouse::convertWallCoordinates(bool robot_sensor_walls[3], bool *board_walls)
{
    switch (this->position.direction) {
        case 0:
            board_walls[0]=robot_sensor_walls[1];
            board_walls[1]=robot_sensor_walls[2];
            board_walls[2]=false;
            board_walls[3]=robot_sensor_walls[0];
            break;
        case 1:
            board_walls[0]=robot_sensor_walls[0];
            board_walls[1]=robot_sensor_walls[1];
            board_walls[2]=robot_sensor_walls[2];
            board_walls[3]=false;
            break;
        case 2:
            board_walls[0]=false;
            board_walls[1]=robot_sensor_walls[0];
            board_walls[2]=robot_sensor_walls[1];
            board_walls[3]=robot_sensor_walls[2];
            break;
        case 3:
            board_walls[0]=robot_sensor_walls[2];
            board_walls[1]=false;
            board_walls[2]=robot_sensor_walls[0];
            board_walls[3]=robot_sensor_walls[1];
            break;
    default:
        break;
    }
}
