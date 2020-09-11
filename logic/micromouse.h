#ifndef MICROMOUSE_H
#define MICROMOUSE_H
#include "GUI/dialogs/include/startdialog.h"
#include "GUI/dialogs/include/newboarddialog.h"
#include "Board/include/fileboard.h"

#include "Board/include/board.h"
#include "GUI/dialogs/include/mainwindow.h"
#include "GUI/objects/include/gboard.h"
#include "GUI/objects/include/gsensor.h"
#include "GUI/objects/include/gmouse.h"

/*!
 * \brief The Micromouse is main class of application
 * it binds with Qt signals logic of the app
 */
class Micromouse
{
    StartDialog startDialog;
    NewBoardDialog newBoardDialog;
    FileBoard* loadBoardDialog;

    BoardGenerator *boardGenerator;
    Board *board;
    Sensor *sensor;
    Mouse *mouse;
    GBoard *gBoard;
    GSensor *gSensor;
    GMouse *gMouse;
    MainWindow *mainWindow;

public:
    Micromouse();
};

#endif // MICROMOUSE_H
