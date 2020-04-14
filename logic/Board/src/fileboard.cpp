#include "logic/Board/include/fileboard.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

FileBoard::FileBoard(QWidget *parent) : QWidget(parent)
{

}

void FileBoard::loadBoardFromFile()
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

        Cell** cellBoard = new Cell*[size];
        for(int i = 0; i < size; ++i)
            cellBoard[i] = new Cell[size];

        QJsonArray cells = obj.value(QString("cells")).toArray();

        for(int i = 0;i<size*size;i++)
        {
            QJsonValue cell = cells[i];
            int pos_x = cell.toObject().value("pos_x").toInt();
            int pos_y = cell.toObject().value("pos_y").toInt();
            QJsonArray walls = cell.toObject().value("walls").toArray();
            cellBoard[pos_x][pos_y].pos_x = pos_x;
            cellBoard[pos_x][pos_y].pos_y = pos_y;
            cellBoard[pos_x][pos_y].isVisited = true;

            for(int w = 0;w<4;w++)
            {
                cellBoard[pos_x][pos_y].walls[w] = walls[w].toBool();
            }
        }

        emit setNewBoard(cellBoard, size);


    }


}
void FileBoard::saveBoardToFile(Cell** board, int size)
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Board to file"), "",
        tr("JSON (*.json);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        QJsonObject raw;
        raw["size"] = size;
        QJsonArray cells;

        for(int i = 0;i<size;i++)
        {
            for(int j =0;j<size;j++)
            {
                QJsonObject cell;
                cell["pos_x"] = i;
                cell["pos_y"] = j;
                QJsonArray walls;
                for(int w = 0;w<4;w++)
                    walls.push_back(board[i][j].walls[w]);
                cell["walls"] = walls;
                cells.push_back(cell);
            }
        }
        raw["cells"] = cells;

        QJsonDocument doc;
        doc.setObject(raw);
        file.write(doc.toJson());
        file.close();
    }


}
