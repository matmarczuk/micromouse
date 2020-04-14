#include "logic/Board/include/board.h"

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
    this->board = board;
    this->size = size;
    emit updateBoard();
}

void Board::saveBoardRequest()
{
    emit sendBoardToSave(board,size);
}
