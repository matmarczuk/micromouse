#include "GUI/objects/include/gboard.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>

GBoard::GBoard()
{

}

GBoard::GBoard(Board * _board) : board(_board)
{

}

/*!
 * \brief Connect logical board with GUI
 * \param board - logic board
 */
void GBoard::setBoard(Board *board)
{
    this->board = board;
}


/*!
 * \brief Return logic board
 * \return logic board
 */
Board* GBoard::getBoard()
{
    return board;
}

/*!
 * \brief Create graphical representation of board
 * \param scene
 */
void GBoard::drawBoard(QGraphicsScene& scene)
{
    Cell*** tmp_board = board->getBoard();
    int size = board->getSize();
    int high = CELL_SIZE;
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
}
