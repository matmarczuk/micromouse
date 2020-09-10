#include "GUI/objects/include/gmouse.h"
#include <QImage>
#include <QGraphicsPixmapItem>
GMouse::GMouse(Mouse *mouse)
{
    this->mouse=mouse;
    image = QImage(":/mouse.png");
    image = image.scaled(20,20,Qt::KeepAspectRatio);
    QObject::connect(mouse, SIGNAL(setNewPosition(Position)), this, SLOT(setPos(Position)));
}

GMouse::~GMouse()
{
    delete item;
}

/*!
 * \brief Set mouse graphic
 * \param scene
 */
void GMouse::draw(QGraphicsScene& scene)
{
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item->setTransformOriginPoint(15,15);
    dynamic_cast<QGraphicsPixmapItem*>(item)->setOffset(5,5);
    scene.addItem(this->item);
}

/*!
 * \brief Set new position of mouse
 * \param pos
 */
void GMouse::setPos(Position pos)
{
    item->setPos(pos.x,pos.y);

    switch (pos.direction) {
        case 0:
            item->setRotation(90);
            break;
        case 1:
            item->setRotation(180);
            break;
        case 2:
            item->setRotation(270);
            break;
        case 3:
            item->setRotation(0);
            break;
        default:
            break;
    }
}
