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
    BoardGenerator * board_generator;
    Cell** board;
public:
    Board();
    Cell** getBoard();
    int getSize();
public slots:
    void newBoard(int size);

};

#endif // BOARD_H
