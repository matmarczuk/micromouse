#include "logic/Board/include/board.h"

Board::Board()
{
    board = nullptr;
    size = 0;
}

/*!
 * \brief Return cell table
 * \return
 */
Cell*** Board::getBoard()
{
    return &board;
}

/*!
 * \brief Return size of the board
 * \return
 */
int Board::getSize()
{
    return size;
}

/*!
 * \brief Set up new board (memory de/allocation)
 * \param board
 * \param size
 */
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
    }

    this->board = board;
    this->size = size;
    emit initBoard();
    emit initMouse(size);
}

/*!
 * \brief Callback of save board request
 */
void Board::saveBoardRequest()
{
    emit sendBoardToSave(board,size);
}
