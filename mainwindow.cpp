#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent, GBoard * gboard, GMouse * gmouse) :
    QMainWindow(parent),
    gboard(gboard),
    gmouse(gmouse),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    gboard->drawBoard(*scene);
    gmouse->draw(*scene);
    ui->setupUi(this);
    ui->boardView->setScene(scene);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
