#include "micromouse.h"
#include <QAction>
#include "ui_mainwindow.h"

Micromouse::Micromouse():
    startDialog(0),
    newBoardDialog(0),
    loadBoardDialog(new FileBoard(0)),
    boardGenerator(new BoardGenerator()),
    board(new Board()),
    sensor(new Sensor(board->getBoard())),
    mouse(new Mouse(sensor)),
    gBoard(new GBoard(board)),
    gSensor(new GSensor(sensor)),
    gMouse(new GMouse(mouse)),
    mainWindow(new MainWindow(0, this->gBoard, this->gMouse, this->gSensor))
{
    startDialog.show();
    QObject::connect(&startDialog, SIGNAL(showNewBoardDialog()), &newBoardDialog, SLOT(showNewBoardDialog()));
    QObject::connect(&startDialog, SIGNAL(showLoadBoardDialog()), loadBoardDialog, SLOT(loadBoardFromFile()));

    QObject::connect(&newBoardDialog, SIGNAL(generateNewBoard(int)), boardGenerator, SLOT(generateNewBoard(int)));
    QObject::connect(boardGenerator, SIGNAL(setNewBoard(Cell**,int)), board, SLOT(setNewBoard(Cell**,int)));
    QObject::connect(loadBoardDialog, SIGNAL(setNewBoard(Cell**,int)), board, SLOT(setNewBoard(Cell**,int)));
    QObject::connect(board, SIGNAL(sendBoardToSave(Cell**,int)), loadBoardDialog, SLOT(saveBoardToFile(Cell**,int)));
    QObject::connect(board, SIGNAL(initBoard()), mainWindow, SLOT(drawBoard()));
    QObject::connect(board, SIGNAL(initMouse(int)), mouse, SLOT(init(int)));
    QObject::connect(mouse, SIGNAL(updateMouseState(QString)), mainWindow,SLOT(updateMouseStateLabel(QString)));

    QObject::connect(mainWindow->getUi()->actionLoad_board, SIGNAL(triggered(bool)),loadBoardDialog, SLOT(loadBoardFromFile()));
    QObject::connect(mainWindow->getUi()->actionGenerate_new_board, SIGNAL(triggered(bool)),&newBoardDialog, SLOT(showNewBoardDialog()));
    QObject::connect(mainWindow->getUi()->resetButton, SIGNAL(clicked(bool)), mouse, SLOT(reset()));
    QObject::connect(mainWindow->getUi()->resetButton, SIGNAL(clicked(bool)), sensor, SLOT(stopTimer()));



}
