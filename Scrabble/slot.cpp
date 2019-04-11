#include "slot.h"
#include <QString>


/**
 * @brief Slot class constructor.
 * @param parent QGraphicsItem default inhereted  parameter of the constructor.
 */
Slot::Slot(QGraphicsItem *parent)
{
 this->multiplier = 1;
 setRect(QRectF(0,0,40,40));
}

/**
 * @brief Sets the coordinates to display the slot.
 * @param x Real x coordinate.
 * @param y Real y coordinate.
 */
void Slot::registerPos(int x, int y)
{
    this->x = x;
    this->y = y;
    if(x==7 & y==7) this->color= QColor(0,0,0);
}

/**
 * @brief Sets the value of multiplier related to the letter hold.
 * @param multiplier Value of multiplier.
 */
void Slot::setMultiplier(int multiplier)
{
    this->multiplier = multiplier;
    switch(multiplier){
        case 2:
            this->color = QColor(210, 210, 210);
            break;
        case 3:
            this->color = QColor(204, 153, 0);
            break;
        case 4:
            this->color = QColor(204, 102, 0);
            break;
        case 5:
            this->color = QColor(153, 0, 0);
            break;
        default:
            this->color = QColor(250, 250, 250);
    }
    if(x==7 & y==7) this->color= QColor(0, 26, 51);
}

/**
 * @brief Overwritten method inherited from the QGraphicsRectItem class.
 *        Used for giving style to the tile object.
 */
void Slot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = QRectF(0,0,40,40);
    QBrush brush(Qt::white);
    painter->fillRect(rec,brush);
    brush.setColor(this->color);
    painter->fillRect(rec,brush);
    if(this->multiplier!=1)
        painter->drawText((int)(rec.x()+(rec.width()*0.4)),(int)(rec.y()+(rec.height()*0.6)),QString::number(this->multiplier));
    painter->drawRect(rec);
}
