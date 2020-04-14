#include "gboard.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>

GBoard::GBoard()
{

}

void GBoard::setBoard(Board *board)
{
    this->board = board;
}
GBoard::GBoard(Board * _board) : board(_board)
{

}
Board* GBoard::getBoard()
{
    return board;
}
void GBoard::drawBoard(QGraphicsScene& scene)
{
    Cell*** tmp_board = board->getBoard();
    int size = board->getSize();
    int high = 30;
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int s = 0; s<4;s++)
            {
                if((*tmp_board)[i][j].walls[s])
                {
                    QGraphicsLineItem * line = new QGraphicsLineItem();
                    switch(s)
                    {
                        case 0:
                            line->setLine(i*high,j*high,i*high,j*high+high);
                            scene.addItem(line);
                            break;
                        case 1:
                            line->setLine(i*high,j*high,i*high+high,j*high);
                            scene.addItem(line);
                            break;
                        case 2:
                            line->setLine(i*high+high,j*high,i*high+high,j*high+high);
                            scene.addItem(line);
                            break;
                        case 3:
                            line->setLine(i*high,j*high+high,i*high+high,j*high+high);
                            scene.addItem(line);
                            break;
                    }
                }
            }
        }
    }


    //scene.addItem();
}
