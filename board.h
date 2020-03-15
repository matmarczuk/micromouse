#ifndef BOARD_H
#define BOARD_H
#include "boardgenerator.h"

class Board
{
    int size;
    BoardGenerator * board_generator;
    Cell** board;
public:
    Board();
    void newBoard(int size);
    Cell** getBoard();
    int getSize();
};

#endif // BOARD_H
