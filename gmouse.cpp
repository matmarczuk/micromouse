#include "gmouse.h"
#include <QImage>

GMouse::GMouse(Mouse *mouse)
{
    this->mouse=mouse;
    QImage image(":/mouse.png");
    image = image.scaled(20,20,Qt::KeepAspectRatio);
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item->setPos(0,0);
}

void GMouse::draw(QGraphicsScene& scene)
{
    scene.addItem(this->item);
}
