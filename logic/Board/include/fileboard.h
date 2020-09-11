#ifndef LOADBOARDDIALOG_H
#define LOADBOARDDIALOG_H

#include <QObject>
#include <QWidget>
#include "logic/Board/include/cell.h"

/*!
 * \brief The FileBoard class is resposnsible for saving and loading from file
 */
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
