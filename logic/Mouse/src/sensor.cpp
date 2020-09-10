#include "logic/Mouse/include/sensor.h"

Sensor::Sensor(Cell*** _board):board(_board)
{

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(measure()));
    //timer.start(100);
}

/*!
 * \brief Simulates sensor readings
 */
void Sensor::measure()
{
    //find in which cell are you
    int cell_pos_x = position.x/30;
    int cell_pos_y = position.y/30;

    bool walls[3];
    switch(position.direction)
    {
        case 0:
            walls[0] = (*board)[cell_pos_x][cell_pos_y].walls[3];
            walls[1] = (*board)[cell_pos_x][cell_pos_y].walls[0];
            walls[2] = (*board)[cell_pos_x][cell_pos_y].walls[1];
            emit newMeasure(walls);
        break;
        case 1:
            walls[0] = (*board)[cell_pos_x][cell_pos_y].walls[0];
            walls[1] = (*board)[cell_pos_x][cell_pos_y].walls[1];
            walls[2] = (*board)[cell_pos_x][cell_pos_y].walls[2];
            emit newMeasure(walls);
        break;
        case 2:
            walls[0] = (*board)[cell_pos_x][cell_pos_y].walls[1];
            walls[1] = (*board)[cell_pos_x][cell_pos_y].walls[2];
            walls[2] = (*board)[cell_pos_x][cell_pos_y].walls[3];
            emit newMeasure(walls);
        break;
        case 3:
            walls[0] = (*board)[cell_pos_x][cell_pos_y].walls[2];
            walls[1] = (*board)[cell_pos_x][cell_pos_y].walls[3];
            walls[2] = (*board)[cell_pos_x][cell_pos_y].walls[0];
            emit newMeasure(walls);
        break;
    }
}

/*!
 * \brief Update sensor position (according to mouse position and orientation)
 * \param pos - new position
 */
void Sensor::updatePosition(Position pos)
{
    position = pos;
}

/*!
 * \brief Sets generated board for sensor use (readings)
 * \param board - Cell table
 */
void Sensor::setBoard(Cell ***board)
{
    this->board = board;
}

/*!
 * \brief Stops simulation timer
 */
void Sensor::stopTimer()
{
    timer.stop();
}

/*!
 * \brief Start simulaton timer with hardcoded timestamp
 */
void Sensor::startTimer()
{
    timer.start(100);
}
