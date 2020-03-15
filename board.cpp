#include "board.h"

Board::Board()
{
    board_generator = new BoardGenerator();
}

void Board::newBoard(int size)
{
    board = board_generator->generate(size);
    this->size = size;
}

Cell** Board::getBoard()
{
    return board;
}

int Board::getSize()
{
    return size;
}
