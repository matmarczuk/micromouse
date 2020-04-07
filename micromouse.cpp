#include "micromouse.h"

Micromouse::Micromouse():
    startDialog(0),
    newBoardDialog(0),
    board(new Board()),
    sensor(new Sensor()),
    mouse(new Mouse(sensor)),
    gBoard(new GBoard(board)),
    gSensor(new GSensor(sensor)),
    gMouse(new GMouse(mouse)),
    mainWindow(new MainWindow(0, gBoard, gMouse, gSensor))
{
    startDialog.show();
    QObject::connect(&startDialog, SIGNAL(showNewBoardDialog()), &newBoardDialog, SLOT(showNewBoardDialog()));
    QObject::connect(&newBoardDialog, SIGNAL(generateNewBoard(int)), board, SLOT(newBoard(int)));
}
