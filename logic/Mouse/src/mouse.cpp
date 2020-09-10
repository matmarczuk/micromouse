#include "logic/Mouse/include/mouse.h"
#include "logic/Board/include/cell.h"
#include <iostream>

Mouse::Mouse(Sensor *sensor): sensor1(sensor), boardMap(new Boardmap), phase(READY_FOR_SCANNING)
{
    QObject::connect(this->sensor1,&Sensor::newMeasure,this,&Mouse::readSensor);
    QObject::connect(this,&Mouse::setNewPosition,sensor1,&Sensor::updatePosition);
    init(0);
}

void Mouse::init(int boardSize)
{
    position.x = 0;
    position.y = 0;
    position.direction = 1;
    boardMap->init(boardSize);
    this->boardSize = boardSize;
    this->phase = READY_FOR_SCANNING;
    emit updateMouseState("READY");
    emit setNewPosition(position);
}
void Mouse::reset()
{
    init(this->boardSize);
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



    switch(phase)
    {
        case READY_FOR_SCANNING:
        {
            phase = SCANNING;
            emit updateMouseState("SCANNING");
            break;
        }
        case SCANNING:
        {
            if(checkIfScanningCompleted())
            {
                phase = GOING_BACK;
                emit updateMouseState("SCANNING COMPLETED");
             }
            break;
        }
        case GOING_BACK:
        {
            if(checkIfMouseOnStart())
            {
                phase = READY_FOR_SOLVE;
                emit updateMouseState("READY FOR SOLVE");
                emit stopSimulation();
            }
            break;
        }


    }
}

bool Mouse::checkIfScanningCompleted()
{
    if(boardMap->getVisitCounter() > boardSize*boardSize -1)
        return true;
    return false;
}
bool Mouse::checkIfMouseOnStart()
{
    int x_cell = this->position.x/CELL_SIZE;
    int y_cell = this->position.y/CELL_SIZE;

    if(!x_cell && !y_cell)
        return true;
    return false;
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

void Mouse::solve_algorithm(algorithm_enum algorithm)
{

}
