#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent, GBoard * gboard) :
    QMainWindow(parent),
    gboard(gboard),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    gboard->drawBoard(*scene);
    ui->setupUi(this);
    ui->boardView->setScene(scene);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
