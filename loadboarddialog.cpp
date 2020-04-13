#include "loadboarddialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

LoadBoardDialog::LoadBoardDialog(QWidget *parent) : QWidget(parent)
{

}

void LoadBoardDialog::loadBoardFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Board file"), "",
          tr("JSON (*.json);;All Files (*)"));

    if (fileName.isEmpty())
          return;
    else
    {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
          QMessageBox::information(this, tr("Unable to open file"),
              file.errorString());
          return;
        }

        QString json_raw = file.readAll();
        file.close();

        QJsonDocument json_doc = QJsonDocument::fromJson(json_raw.toUtf8());
        QJsonObject obj = json_doc.object();

        int size = obj.value(QString("size")).toInt();
        QJsonArray cells = obj.value(QString("cells")).toArray();

        for(int i = 0;i<size*size;i++)
        {
            QJsonValue cell = cells[i];
            QJsonValue pos_x = cell.toObject().value("pos_x");
            QJsonValue pos_y = cell.toObject().value("pos_y");
            QJsonArray walls = cell.toObject().value("cells").toArray();
        }

        Cell** cellBoard = new Cell*[size];
        for(int i = 0; i < size; ++i)
            cellBoard[i] = new Cell[size];

        for(int i = 0;i<size;i++)
        {
            for(int j = 0;j<size;j++)
            {
                cellBoard[i][j].pos_x = i;
                cellBoard[i][j].pos_y = j;
                cellBoard[i][j].walls[0] = false;
            }
        }
        emit setNewBoard(cellBoard, size);


    }


}
