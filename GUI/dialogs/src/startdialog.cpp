#include "GUI/dialogs/include/startdialog.h"
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

/*!
 * \brief Quit application button callback
 */
void StartDialog::on_pushButton_clicked()
{
    QApplication::quit();
}

/*!
 * \brief New board button callback
 */
void StartDialog::on_newBoardButton_clicked()
{
    this->close();
    emit showNewBoardDialog();
}

/*!
 * \brief Load board button callback
 */
void StartDialog::on_loadBoardButton_clicked()
{
    this->close();
    emit showLoadBoardDialog();
}
