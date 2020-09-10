#include "logic/Mouse/include/mouse.h"
#include "logic/Board/include/cell.h"
#include "logic/Mouse/include/wavepropagation.h"
#include "logic/Mouse/include/timetable.h"
#include <iostream>

Mouse::Mouse(Sensor *sensor): sensor1(sensor), boardMap(new Boardmap), phase(READY_FOR_SCANNING)
{
    QObject::connect(this->sensor1,&Sensor::newMeasure,this,&Mouse::readSensor);
    QObject::connect(this,&Mouse::setNewPosition,sensor1,&Sensor::updatePosition);
    QObject::connect(&ride_timer, SIGNAL(timeout()), this, SLOT(ridePath()));
    init(0);
}

/*!
 * \brief Initialize new mouse object
 * \param boardSize - generated board size
 */
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

/*!
 * \brief Reset recorded board and position
 */
void Mouse::reset()
{
    init(this->boardSize);
}

/*!
 * \brief Interpret sensor read
 * \param walls - binary sensor readings (left, front, right)
 */
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

/*!
 * \brief Check if scanning of board is completed
 * \return boolean
 */
bool Mouse::checkIfScanningCompleted()
{
    if(boardMap->getVisitCounter() > boardSize*boardSize -1)
        return true;
    return false;
}

/*!
 * \brief Check if mouse came back to start position
 * \return boolean
 */
bool Mouse::checkIfMouseOnStart()
{
    int x_cell = this->position.x/CELL_SIZE;
    int y_cell = this->position.y/CELL_SIZE;

    if(!x_cell && !y_cell)
        return true;
    return false;
}

/*!
 * \brief Converts sensor readings to global coordinates
 * \param robot_sensor_walls - readings in mouse coordinates
 * \param board_walls - table of cell walls
 */
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

/*!
 * \brief Solve maze within choosen algorithm
 * \param chosen_algorithm
 */
void Mouse::solveBoard(algorithm_enum chosen_algorithm)
{
    if(solveAlgorithm)
        delete solveAlgorithm;

    switch(chosen_algorithm)
    {
        case WAVE_PROPAGATION:
            solveAlgorithm = new WavePropagation();
            break;
        case TIME_TABLE:
            solveAlgorithm = new TimeTable();
            break;
    }
    path = solveAlgorithm->calculate(boardMap);
    emit updateMouseState("BOARD SOLVED. READY TO RIDE");
    ride_timer.start(100);
}

/*!
 * \brief Move mouse within calculated path
 */
void Mouse::ridePath()
{
    if(!path.empty())
    {
        emit updateMouseState("RIDE");

        Cell next_cell = path.back();
        path.pop_back();
        this->position.x = next_cell.pos_x*CELL_SIZE;
        this->position.y = next_cell.pos_y*CELL_SIZE;

        Cell next_neighbour_cell = path.back();
        if(next_neighbour_cell.pos_x>next_cell.pos_x)
            this->position.direction=2;
        else if(next_neighbour_cell.pos_x<next_cell.pos_x)
            this->position.direction=0;
        else if(next_neighbour_cell.pos_y>next_cell.pos_y)
            this->position.direction=3;
        else if(next_neighbour_cell.pos_y<next_cell.pos_y)
            this->position.direction=1;
        emit setNewPosition(this->position);
    }
    else
    {
        emit updateMouseState("RIDE COMPLETED");
        ride_timer.stop();
    }
}
