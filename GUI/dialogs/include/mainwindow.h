#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsScene>
#include "GUI/objects/include/gboard.h"
#include "GUI/objects/include/gmouse.h"
#include "GUI/objects/include/gsensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, GBoard * gboard = 0, GMouse * gmouse = 0, GSensor * gsensor = 0);
    ~MainWindow();
    Ui::MainWindow* getUi();
public slots:
    void drawBoard();
private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    GBoard * gboard;
    GMouse * gmouse;
    GSensor * gsensor;
};

#endif // MAINWINDOW_H
