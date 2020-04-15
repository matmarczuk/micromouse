#ifndef GMOUSE_H
#define GMOUSE_H
#include "logic/Mouse/include/mouse.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>

class GMouse : public QObject
{
    Q_OBJECT
private:
    Mouse * mouse;
    QGraphicsItem *item;
    QImage image;
public:
    GMouse(Mouse *mouse);
    ~GMouse();
    void draw(QGraphicsScene& scene);
public slots:
    void setPos(Position pos);
};

#endif // GMOUSE_H
