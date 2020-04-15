#include "logic/Board/include/board.h"
#include <qdebug.h>
Board::Board()
{
    board = nullptr;
    size = 0;
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
    //dealocate previous
    if(size != 0)
    {
        for(int i = 0; i < this->size; ++i) {
            delete[] this->board[i];
        }
     //Free the array of pointers
         delete[] this->board;
    qDebug("dealocagte");
    }

    this->board = board;
    this->size = size;
    emit initBoard();
    emit initMouse(size);
}

void Board::saveBoardRequest()
{
    emit sendBoardToSave(board,size);
}
