#ifndef MICROMOUSE_H
#define MICROMOUSE_H
#include "startdialog.h"
#include "newboarddialog.h"
#include "board.h"
#include "mainwindow.h"
#include "gboard.h"
#include "gsensor.h"
#include "gmouse.h"


class Micromouse
{
    StartDialog startDialog;
    NewBoardDialog newBoardDialog;
    MainWindow *mainWindow;
    Board *board;
    Sensor *sensor;
    Mouse *mouse;
    GBoard *gBoard;
    GSensor *gSensor;
    GMouse *gMouse;

public:
    Micromouse();
};

#endif // MICROMOUSE_H
