#ifndef NEWBOARDDIALOG_H
#define NEWBOARDDIALOG_H
#include "logic/Board/include/board.h"

#include <QDialog>

namespace Ui {
class NewBoardDialog;
}

class NewBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBoardDialog(QWidget *parent = 0);
    ~NewBoardDialog();

private slots:
    void on_generateBoardButton_clicked();
    void on_boardSizeSlider_sliderMoved(int position);

    void on_boardSizeSlider_valueChanged(int value);

public slots:
    void showNewBoardDialog();
signals:
    void generateNewBoard(int size);
private:
    Ui::NewBoardDialog *ui;
    int sliderPosition;
};

#endif // NEWBOARDDIALOG_H
