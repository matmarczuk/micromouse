#include "sensor.h"
#include <iostream>

Sensor::Sensor()
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(measure()));
    timer.start(100);
}
void Sensor::measure()
{
    //find in which cell are you
    int cell_pos_x = position.x/30;
    int cell_pos_y = position.y/30;

//    std::cout<<"I am in cell "<<cell_pos_x<<" "<<cell_pos_y<<"walls"<< \
//               board[cell_pos_x][cell_pos_y].walls[0]<< board[cell_pos_x][cell_pos_y].walls[1]<< \
//                board[cell_pos_x][cell_pos_y].walls[2]<< board[cell_pos_x][cell_pos_y].walls[3]<<std::endl;
    bool walls[3];
    switch(position.direction)
    {
        case 0:
            walls[0] = board[cell_pos_x][cell_pos_y].walls[3];
            walls[1] = board[cell_pos_x][cell_pos_y].walls[0];
            walls[2] = board[cell_pos_x][cell_pos_y].walls[1];
            emit newMeasure(walls);
        break;
        case 1:
            walls[0] = board[cell_pos_x][cell_pos_y].walls[0];
            walls[1] = board[cell_pos_x][cell_pos_y].walls[1];
            walls[2] = board[cell_pos_x][cell_pos_y].walls[2];
            emit newMeasure(walls);
        break;
        case 2:
            walls[0] = board[cell_pos_x][cell_pos_y].walls[1];
            walls[1] = board[cell_pos_x][cell_pos_y].walls[2];
            walls[2] = board[cell_pos_x][cell_pos_y].walls[3];
            emit newMeasure(walls);
        break;
        case 3:
            walls[0] = board[cell_pos_x][cell_pos_y].walls[2];
            walls[1] = board[cell_pos_x][cell_pos_y].walls[3];
            walls[2] = board[cell_pos_x][cell_pos_y].walls[0];
            emit newMeasure(walls);
        break;
    }
}
void Sensor::updatePosition(Position pos)
{
    position = pos;
}
void Sensor::setBoard(Cell **board)
{
    this->board = board;
}
