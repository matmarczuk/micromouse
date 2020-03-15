#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsScene>
#include "gboard.h"
#include "gmouse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, GBoard * gboard = 0, GMouse * gmouse = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    GBoard * gboard;
    GMouse * gmouse;
};

#endif // MAINWINDOW_H
