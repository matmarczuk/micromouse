#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include "boardgenerator.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "mouse.h"
#include "sensor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Board * board = new Board();
    board->newBoard(16);
    GBoard * gboard = new GBoard(board);

    Sensor* sensor = new Sensor();
    sensor->setBoard(board->getBoard());

    Mouse *mouse = new Mouse(sensor);
    GMouse *gmouse = new GMouse(mouse);

    MainWindow w(0, gboard, gmouse);

    w.show();

    return a.exec();

    delete gmouse;
    delete mouse;
    delete sensor;
    delete gboard;
    delete board;
}
