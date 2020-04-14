#ifndef LOADBOARDDIALOG_H
#define LOADBOARDDIALOG_H

#include <QObject>
#include <QWidget>
#include "logic/Board/include/cell.h"

class FileBoard : public QWidget
{
    Q_OBJECT
public:
    explicit FileBoard(QWidget *parent = nullptr);

signals:
    void setNewBoard(Cell **board, int size);
public slots:
    void loadBoardFromFile();
    void saveBoardToFile(Cell** board, int size);
};

#endif // LOADBOARDDIALOG_H
