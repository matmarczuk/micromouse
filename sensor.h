#ifndef SENSOR_H
#define SENSOR_H

#include <QTimer>
#include "position.h"

class Sensor : public QObject
{
    Q_OBJECT
    float value;
    QTimer timer;
    Position position;
public:
    Sensor();
public slots:
    void measure();
    void updatePosition(Position pos);
signals:
    void newMeasure(float);
};

#endif // SENSOR_H
