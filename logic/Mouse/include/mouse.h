#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include "sensor.h"
#include "position.h"
#include "boardmap.h"
#include "algorithm.h"

/*!
 * \brief The mouse_phase enum store possible mouse states
 */
enum mouse_phase
{
    READY_FOR_SCANNING,
    SCANNING,
    GOING_BACK
};

/*!
 * \brief The Mouse class is resposible for logic of mouse
 */
class Mouse : public QObject
{
    Q_OBJECT
private:
    Position position;
    Sensor *sensor1;
    Boardmap * boardMap;
    int boardSize;
    mouse_phase phase;
    Algorithm * solveAlgorithm = NULL;
    std::vector<Cell> path;
    QTimer ride_timer;

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
    void solveBoard(algorithm_enum algorithm);
    void ridePath();
private:
    void convertWallCoordinates(bool robot_sensor_walls[3], bool *board_walls);
    bool checkIfScanningCompleted();
    bool checkIfMouseOnStart();
};

#endif // MOUSE_H
