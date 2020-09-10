#include "GUI/dialogs/include/newboarddialog.h"
#include "ui_newboarddialog.h"
NewBoardDialog::NewBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBoardDialog)
{
    ui->setupUi(this);
    sliderPosition=ui->boardSizeSlider->minimum();
    ui->lcdNumber->display(this->ui->boardSizeSlider->sliderPosition());
    ui->lcdNumber_2->display(this->ui->boardSizeSlider->sliderPosition());
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

void NewBoardDialog::on_boardSizeSlider_sliderMoved(int position)
{
    ui->lcdNumber->display(position);
    ui->lcdNumber_2->display(position);
}
