#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include "boardgenerator.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board * board = new Board();
    board->newBoard(16);
    GBoard * gboard = new GBoard(board);
    MainWindow w(0, gboard);

    w.show();
    return a.exec();
}
