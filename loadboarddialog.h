#ifndef LOADBOARDDIALOG_H
#define LOADBOARDDIALOG_H

#include <QObject>
#include <QWidget>
#include <cell.h>

class LoadBoardDialog : public QWidget
{
    Q_OBJECT
public:
    explicit LoadBoardDialog(QWidget *parent = nullptr);

signals:
    void setNewBoard(Cell **board, int size);
public slots:
    void loadBoardFromFile();
    void saveBoardToFile(Cell** board, int size);
};

#endif // LOADBOARDDIALOG_H
