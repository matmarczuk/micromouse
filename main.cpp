#include "mainwindow.h"
#include "startdialog.h"
#include "newboarddialog.h"
#include <QApplication>
#include <QPainter>
#include "boardgenerator.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "mouse.h"
#include "sensor.h"
#include "loadboarddialog.h"
#include "micromouse.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Micromouse micromouse;

//    Board * board = new Board();
//    GBoard * gboard = new GBoard(board);

//    Sensor* sensor = new Sensor();
//    GSensor * gsensor = new GSensor(sensor);
//    sensor->setBoard(board->getBoard());


//    Mouse *mouse = new Mouse(sensor);
//    GMouse *gmouse = new GMouse(mouse);

    return a.exec();

//    delete gmouse;
//    delete mouse;
//    delete sensor;
//    delete gboard;
//    delete board;
}
