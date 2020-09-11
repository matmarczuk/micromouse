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

    connect(ui->scanButton, SIGNAL(clicked()), gsensor->getSensorInst(), SLOT(startTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), gsensor->getSensorInst(), SLOT(stopTimer()));
    connect(ui->actionSave_board, SIGNAL(triggered(bool)),gboard->getBoard(), SLOT(saveBoardRequest()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

Ui::MainWindow* MainWindow::getUi()
{
    return ui;
}

/*!
 * \brief Draw board and mouse graphic
 */
void MainWindow::drawBoard()
{
    scene->clear();
    scene->update();
    gboard->drawBoard(*scene);
    gmouse->draw(*scene);
    this->show();
}

/*!
 * \brief Close button callback
 */
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

/*!
 * \brief Updates mouse state label displayed on main screen
 * \param state - new state
 */
void MainWindow::updateMouseStateLabel(QString state)
{
    ui->state_label->setText(state);

    if(state == QString("READY FOR SOLVE"))
    {
        ui->scanButton->setDisabled(true);
        ui->stopButton->setDisabled(true);
        ui->solve_button->setEnabled(true);
    }
    else if(state == QString("READY"))
    {
        ui->solve_button->setDisabled(true);
        ui->scanButton->setEnabled(true);
        ui->stopButton->setEnabled(true);
    }
}

/*!
 * \brief Emit solve board requsest with selected algorithm
 */
void MainWindow::on_solve_button_clicked()
{
    switch(ui->comboBox->currentIndex())
    {
        case 0:
            emit solve_with_algorithm(WAVE_PROPAGATION);
            break;
        case 1:
            emit solve_with_algorithm(TIME_TABLE);
            break;
    }
}
