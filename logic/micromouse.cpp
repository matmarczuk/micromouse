#include "micromouse.h"

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
    mainWindow(new MainWindow(0, this->gBoard, gMouse, this->gSensor))
{
    startDialog.show();
    QObject::connect(&startDialog, SIGNAL(showNewBoardDialog()), &newBoardDialog, SLOT(showNewBoardDialog()));
    QObject::connect(&startDialog, SIGNAL(showLoadBoardDialog()), loadBoardDialog, SLOT(loadBoardFromFile()));

    QObject::connect(&newBoardDialog, SIGNAL(generateNewBoard(int)), boardGenerator, SLOT(generateNewBoard(int)));
    QObject::connect(boardGenerator, SIGNAL(setNewBoard(Cell**,int)), board, SLOT(setNewBoard(Cell**,int)));
    QObject::connect(loadBoardDialog, SIGNAL(setNewBoard(Cell**,int)), board, SLOT(setNewBoard(Cell**,int)));
    QObject::connect(board, SIGNAL(sendBoardToSave(Cell**,int)), loadBoardDialog, SLOT(saveBoardToFile(Cell**,int)));
    QObject::connect(board, SIGNAL(updateBoard()), mainWindow, SLOT(drawBoard()));
}
