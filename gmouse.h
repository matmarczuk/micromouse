#ifndef GMOUSE_H
#define GMOUSE_H
#include <mouse.h>
#include <QGraphicsItem>
#include <QGraphicsScene>

class GMouse
{
    Mouse * mouse;
    QGraphicsItem* item;
public:
    GMouse(Mouse *mouse);
    void draw(QGraphicsScene& scene);
};

#endif // GMOUSE_H
