#ifndef SENSOR_H
#define SENSOR_H

#include <QTimer>
#include "position.h"
#include "board.h"

class Sensor : public QObject
{
    Q_OBJECT
    float value;
    QTimer timer;
    Position position;
    Cell** board;
public:
    Sensor();
    void setBoard(Cell** board);
public slots:
    void measure();
    void updatePosition(Position pos);
signals:
    void newMeasure(bool[3]);
};

#endif // SENSOR_H
