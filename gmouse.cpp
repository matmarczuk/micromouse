#include "gmouse.h"
#include <QImage>

GMouse::GMouse(Mouse *mouse)
{
    this->mouse=mouse;
    QImage image(":/mouse.png");
    image = image.scaled(20,20,Qt::KeepAspectRatio);
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item->setPos(0,0);
    QObject::connect(mouse, SIGNAL(setNewPosition(Position)), this, SLOT(setPos(Position)));
}

void GMouse::draw(QGraphicsScene& scene)
{
    scene.addItem(this->item);
}

void GMouse::setPos(Position pos)
{
    item->setPos(pos.x,pos.y);
    item->setRotation(pos.direction);
}

