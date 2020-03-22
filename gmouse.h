#ifndef GMOUSE_H
#define GMOUSE_H
#include <mouse.h>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>

class GMouse : public QObject
{
    Q_OBJECT
private:
    Mouse * mouse;
    QGraphicsItem* item;
public:
    GMouse(Mouse *mouse);
    void draw(QGraphicsScene& scene);
public slots:
    void setPos(Position pos);
};

#endif // GMOUSE_H
