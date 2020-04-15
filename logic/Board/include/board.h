#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include "boardgenerator.h"
#include "cell.h"

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
    void update();
    void sendBoardToSave(Cell **board, int size);
public slots:
    void setNewBoard(Cell **board, int size);
    void saveBoardRequest();
};

#endif // BOARD_H
