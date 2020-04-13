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
