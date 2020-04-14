#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H
#include "cell.h"
#include <QObject>

class BoardGenerator : public QObject
{
    Q_OBJECT
public:
    BoardGenerator();
signals:
    void setNewBoard(Cell **board, int size);
public slots:
    void generateNewBoard(int size);
};

#endif // BOARDGENERATOR_H
