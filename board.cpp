#include "board.h"
#include <iostream>

Board::Board()
{
    board_generator = new BoardGenerator();
    board = nullptr;
}

void Board::newBoard(int size)
{
    board = board_generator->generate(size);
    this->size = size;
    emit updateBoard();
    std::cout<<"new board created size "<<size<<std::endl;
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
