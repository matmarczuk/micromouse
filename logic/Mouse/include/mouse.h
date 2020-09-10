#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include "sensor.h"
#include "position.h"
#include "boardmap.h"
#include "algorithm.h"

enum mouse_phase
{
    READY_FOR_SCANNING,
    SCANNING,
    GOING_BACK,
    READY_FOR_SOLVE,
    RIDE,
    REACHED_FINISH
};
class Mouse : public QObject
{
    Q_OBJECT
private:
    Position position;
    Sensor *sensor1;
    Boardmap * boardMap;
    int boardSize;
    mouse_phase phase;

public:
    Mouse(Sensor *sensor);
    void move();
signals:
    void setNewPosition(Position pos);
    void updateMouseState(QString state);
    void stopSimulation();
public slots:
    void readSensor(bool walls[3]);
    void init(int boardSize);
    void reset();
    void solve_algorithm(algorithm_enum algorithm);
private:
    void convertWallCoordinates(bool robot_sensor_walls[3], bool *board_walls);
    bool checkIfScanningCompleted();
    bool checkIfMouseOnStart();
};

#endif // MOUSE_H
