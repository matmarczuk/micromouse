#ifndef GBOARD_H
#define GBOARD_H
#include "logic/Board/include/board.h"
#include <QGraphicsScene>

/*!
 * \brief The GBoard class is graphic representation of board
 */
class GBoard
{
    Board * board;
public:
    GBoard();
    GBoard(Board * _board);
    void setBoard(Board *board);
    void drawBoard(QGraphicsScene& scene);    
    Board* getBoard();
};

#endif // GBOARD_H
