#ifndef GBOARD_H
#define GBOARD_H
#include <board.h>
#include <QGraphicsScene>

class GBoard
{
    Board * board;
public:
    GBoard();
    GBoard(Board * _board);
    void setBoard(Board *board);
    void drawBoard(QGraphicsScene& scene);    

};

#endif // GBOARD_H
