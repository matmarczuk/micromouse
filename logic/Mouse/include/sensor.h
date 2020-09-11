#ifndef SENSOR_H
#define SENSOR_H

#include <QTimer>
#include "position.h"
#include "logic/Board/include/board.h"

/*!
 * \brief The Sensor class responsible for providing sensor reads to mouse
 */
class Sensor : public QObject
{
    Q_OBJECT
    float value;
    QTimer timer;
    Position position;
    Cell*** board;
public:
    Sensor(Cell*** _board);
    void setBoard(Cell*** _board);
public slots:
    void measure();
    void updatePosition(Position pos);
    void stopTimer();
    void startTimer();
signals:
    void newMeasure(bool[3]);
};

#endif // SENSOR_H
