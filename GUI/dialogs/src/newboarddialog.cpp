#include "newboarddialog.h"
#include "ui_newboarddialog.h"
#include <QDebug>
NewBoardDialog::NewBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBoardDialog)
{
    ui->setupUi(this);
    sliderPosition=ui->boardSizeSlider->minimum();
}

NewBoardDialog::~NewBoardDialog()
{
    delete ui;
}

void NewBoardDialog::on_generateBoardButton_clicked()
{
    this->close();
    emit generateNewBoard(this->ui->boardSizeSlider->sliderPosition());
}
void NewBoardDialog::showNewBoardDialog()
{
    this->show();
}
