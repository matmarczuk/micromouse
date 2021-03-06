#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include "boardgenerator.h"
#include "cell.h"

/*!
 * \brief Class responsible for storing board data
 */
class Board : public QObject
{
    Q_OBJECT
private:
    int size;
    Cell** board;
public:
    Board();
    Cell*** getBoard();
    int getSize();
signals:
    void initBoard();
    void initMouse(int);
    void sendBoardToSave(Cell **board, int size);
public slots:
    void setNewBoard(Cell **board, int size);
    void saveBoardRequest();
};

#endif // BOARD_H
