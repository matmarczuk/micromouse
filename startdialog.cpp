#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_pushButton_clicked()
{
    QApplication::quit();
}

void StartDialog::on_newBoardButton_clicked()
{
    this->close();
    emit showNewBoardDialog();
}
