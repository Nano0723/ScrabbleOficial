#include "gtile.h"
#include <QString>
#include <QDebug>
#include <QColor>
#include <QPixmap>
#include <stdlib.h>
#include "slot.h"
#include <QInputDialog>

/**
 * @brief Gtile class constructor.
 * @param parent QGraphicsItem default inhereted  parameter of the constructor.
 */
Gtile::Gtile(QGraphicsItem *parent)
{
    this->letter = '-';
    this->value=0;
    pressed = false;

    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setRect(QRectF(0,0,40,40));

    //std::random_device rd;
    //std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, 7);
    //this->texture = getRandomTexture(distr(eng));

    resetGridPos();
    this->active=true;
}

/**
 * @brief Sets the tile's letter and value.
 * @param letter Tile's displayed letter.
 * @param value Tile's displayed value.
 */
void Gtile::setData(char letter, int value)
{
    this->letter=letter;
    this->value=value;
}

/**
 * @brief setParent Passes a reference of the GameWindow being used for display purposes.
 * @param parent Reference to the current GameWindow instance being used.
 */
void Gtile::setParent(QMainWindow *parent)
{
    this->parent=parent;
}

/**
 * @brief Overwritten method inherited from the QGraphicsRectItem class.
 *        Used for giving style to the tile object.
 */
void Gtile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = QRectF(0,0,40,40);
    QBrush brush(Qt::white);
    QPen pen(Qt::black);
    //pen.setWidth(2);

    if(pressed){
        pen.setWidth(5);
    }else{
        pen.setWidth(2);
        brush.setTexture(this->texture);
    }

    painter->setPen(pen);
    painter->fillRect(rec,brush);

    painter->drawText((int)(rec.x()+(rec.width()*0.35)),(int)(rec.y()+(rec.height()/2)+3),QChar(this->letter));
    painter->drawText((int)(rec.x()+(rec.width()*0.5)),(int)(rec.y()+(rec.height()*0.8)),QString::number(this->value));

    //rec.setPos();
    //printing
    //qDebug() << this->pos();
    painter->drawRect(rec);
}

/**
 * @brief Sets the tile's anchor point. The anchor point determines the
 *        location in the window in terms of real coordinates.
 * @param anchorPoint Updated tile real position.
 */
void Gtile::setAnchorPoint(const QPointF anchorPoint)
{
    this->anchorPoint = anchorPoint;
}

/**
 * @brief Set the tile's anchor point. It's used at the begging of
 *        the turn to determine the tile initial position.
 * @param initialPos Tile position at the begging of the turn.
 */
void Gtile::setInitialAnchorPoint(QPointF initialPos)
{
    this->initialAnchorPoint = initialPos;
}

/**
 * @brief Returns the tile's initial anchor point of the current turn.
 * @return QPointF Tile's initial anchor point.
 */
QPointF Gtile::getInitialAnchorPoint()
{
    return this->initialAnchorPoint;
}

/**
 * @brief Returns the letter displayed in the tile.
 * @return char Tile's letter.
 */
char Gtile::getLetter()
{
    return this->letter;
}

/**
 * @brief Returns the value displayed in the tile.
 * @return int Tile's value.
 */
int Gtile::getValue()
{
    return this->value;
}

/**
 * @brief Returns the tile's grid position in the Y axis.
 * @return int Tile's grid position in the Y axis.
 */
int Gtile::gridY()
{
    return this->gridPos[0];
}

/**
 * @brief Returns the tile's grid position in the X axis.
 * @return int Grid position in the X axis.
 */
int Gtile::gridX()
{
    return this->gridPos[1];
}

/**
 * @brief Sets the tile's position in the gameboard in terms of XY axis.
 * @param gridY Grid position in the Y axis.
 * @param gridX Grid position in the X axis.
 */
void Gtile::setGridPos(int gridY, int gridX)
{
    this->gridPos[0]=gridY;
    this->gridPos[1]=gridX;
}

/**
 * @brief Sets the tile's grid position to (-1,-1).
 *        Used to detect when a tile isn't placed.
 */
void Gtile::resetGridPos()
{
    gridPos[0]=-1;
    gridPos[1]=-1;
}

/**
 * @brief Disable the interactivity of the tile.
 *        Causes that nothing happens when the tile is clicked.
 */
void Gtile::deactivate()
{
    this->active=false;
    this->setFlag(QGraphicsItem::ItemIsMovable, false);
}

/**
 * @brief Overwritten method inhereted from QGraphicsItem.
 *        Used to make possible the dragging of the tile when pressed.
 * @param event Event occurring on the window.
 */
void Gtile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(active){
        pressed = true;
        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

/**
 * @brief Overwritten method inhereted from QGraphicsItem.
 *        Used to detect item collisions and determine the final
 *        position of the tile when dropped.
 * @param event Event occurring on the window.
 */
void Gtile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->letter == '!'){
        bool blankSetted = false;
        std::string answer = "";

        while(!blankSetted){
            answer = QInputDialog::getText(
                     parent,"Blank Tile",
                     "Choose the letter for this special black tile.",
                      QLineEdit::Normal, "", &blankSetted)
                      .toUtf8().constData();
            if(answer=="")blankSetted=false;
        }
        this->letter = answer.at(0);
    }

    if(pressed & active){
        QList<QGraphicsItem*> colItems = collidingItems();

        if(colItems.isEmpty()){
            this->setPos(initialAnchorPoint);

        }else{
            QGraphicsItem* closestItem = colItems.at(0);

            //qDebug() << closestItem->x() << "," << closestItem->y();

            qreal shortestDist = 100000;
            foreach(QGraphicsItem* item, colItems){
                QLineF line(item->sceneBoundingRect().center(),
                            this->sceneBoundingRect().center());

                if(line.length() < shortestDist){
                    shortestDist = line.length();
                    closestItem = item;
                }
            }

            //qDebug() << closestItem->scenePos();
            if(validatePosition(closestItem->scenePos())){
                this->setPos(closestItem->scenePos());
                this->gridPos[0] = (int)(closestItem->scenePos().y()/40);
                this->gridPos[1] = (int)(closestItem->scenePos().x()/40);
                //qDebug() << gridPos[0] << "," << gridPos[1];
            }else{
                this->setPos(initialAnchorPoint);
            }
        }
        pressed = false;
    }

    if(this->y() > 560) resetGridPos();

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

/**
 * @brief Method used to assign the tile texture.
 * @param option Random number that can go from 1 to 7.
 * @return QPixmap A QPixmap object that corresponds to the given option.
 */
QPixmap Gtile::getRandomTexture(int option)
{
    QPixmap texture;
    switch(option){
        case 1:
            texture= QPixmap(":/images/images/wood1.jpg");
            break;
        case 2:
            texture= QPixmap(":/images/images/wood2.jpg");
            break;
        case 3:
            texture= QPixmap(":/images/images/wood3.jpg");
            break;
        case 4:
            texture= QPixmap(":/images/images/wood4.jpg");
            break;
        case 5:
            texture= QPixmap(":/images/images/wood5.jpg");
            break;
        case 6:
            texture= QPixmap(":/images/images/wood6.jpg");
            break;
        case 7:
            texture= QPixmap(":/images/images/wood7.jpg");
            break;
    }
    return texture;
}

/**
 * @brief Determines if the given real position if in the allowed range
 *        of coordinates for interactive objects.
 * @param QPointF Real position of an object.
 * @return bool Validity of the option.
 */
bool Gtile::validatePosition(QPointF realPosition)
{
    return ((((int)realPosition.x())%40==0 & ((int)realPosition.y())%40==0) & realPosition.x() < 561 & realPosition.y() < 561);
}
