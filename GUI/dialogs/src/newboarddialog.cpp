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

/*!
 * \brief Emit signal to generate new board at given size
 */
void NewBoardDialog::on_generateBoardButton_clicked()
{
    this->close();
    emit generateNewBoard(this->ui->boardSizeSlider->sliderPosition());
}

/*!
 * \brief Displays board size slider
 */
void NewBoardDialog::showNewBoardDialog()
{
    this->show();
}

/*!
 * \brief Display size of board to generate
 * \param position - slider position
 */
void NewBoardDialog::on_boardSizeSlider_sliderMoved(int position)
{
    ui->lcdNumber->display(position);
    ui->lcdNumber_2->display(position);
}

void NewBoardDialog::on_boardSizeSlider_valueChanged(int value)
{
    on_boardSizeSlider_sliderMoved(value);
}
