#include "GUI/dialogs/include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent, GBoard * gboard, GMouse * gmouse, GSensor * gsensor) :
    QMainWindow(parent),
    gboard(gboard),
    gmouse(gmouse),
    gsensor(gsensor),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->boardView->setScene(scene);

    connect(ui->startButton, SIGNAL(clicked()), gsensor->getSensorInst(), SLOT(startTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), gsensor->getSensorInst(), SLOT(stopTimer()));
    connect(ui->actionSave_board, SIGNAL(triggered(bool)),gboard->getBoard(), SLOT(saveBoardRequest()));

}

void MainWindow::drawBoard()
{
    gboard->drawBoard(*scene);
    gmouse->draw(*scene);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
