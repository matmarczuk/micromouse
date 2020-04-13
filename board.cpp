#include "board.h"
#include <iostream>

Board::Board()
{
    board = nullptr;
}
Cell*** Board::getBoard()
{
    return &board;
}

int Board::getSize()
{
    return size;
}

void Board::setNewBoard(Cell **board, int size)
{
    std::cout<<"new board setted"<<std::endl;
    this->board = board;
    this->size = size;
    emit updateBoard();
}
