#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include "sensor.h"
#include "position.h"
#include "boardmap.h"

class Mouse : public QObject
{
    Q_OBJECT
private:
    Position position;
    Sensor *sensor1;
    Boardmap * boardMap;

public:
    Mouse(Sensor *sensor);
    void move();
signals:
    void setNewPosition(Position pos);
public slots:
    void readSensor(bool walls[3]);
private:
    void convertWallCoordinates(bool robot_sensor_walls[3], bool *board_walls);
};

#endif // MOUSE_H
