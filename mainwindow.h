#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsScene>
#include "gboard.h"
#include "gmouse.h"
#include "gsensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, GBoard * gboard = 0, GMouse * gmouse = 0, GSensor * gsensor = 0);
    ~MainWindow();
public slots:
    void drawBoard();
private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    GBoard * gboard;
    GMouse * gmouse;
    GSensor * gsensor;
};

#endif // MAINWINDOW_H
