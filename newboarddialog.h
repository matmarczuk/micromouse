#ifndef NEWBOARDDIALOG_H
#define NEWBOARDDIALOG_H
#include "board.h"

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
public slots:
    void showNewBoardDialog();
signals:
    void generateNewBoard(int size);
private:
    Ui::NewBoardDialog *ui;
    int sliderPosition;
};

#endif // NEWBOARDDIALOG_H
