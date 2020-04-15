#include "GUI/dialogs/include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

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
Ui::MainWindow* MainWindow::getUi()
{
    return ui;
}

void MainWindow::drawBoard()
{
    scene->clear();
    scene->update();
    gboard->drawBoard(*scene);
    gmouse->draw(*scene);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
void MainWindow::updateMouseStateLabel(QString state)
{
    ui->state_label->setText(state);
}
