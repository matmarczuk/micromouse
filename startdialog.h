#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();

private slots:
    void on_pushButton_clicked();

    void on_newBoardButton_clicked();
    void on_loadBoardButton_clicked();

signals:
    void showNewBoardDialog();
    void showLoadBoardDialog();

private:
    Ui::StartDialog *ui;
};

#endif // STARTDIALOG_H
