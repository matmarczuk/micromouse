#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include "sensor.h"
#include "position.h"

class Mouse : public QObject
{
    Q_OBJECT
private:
    Position position;
    Sensor *sensor1;

public:
    Mouse();
    void move();
signals:
    void setNewPosition(Position pos);
public slots:
    void readSensor(float read);
};

#endif // MOUSE_H
