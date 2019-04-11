#ifndef SLOT_H
#define SLOT_H

#include <QPainter>
#include <QGraphicsItem>

/**
 * @brief Gameboard's slot class. Corresponds to the squares that conforms the gameboard.
 */
class Slot: public QGraphicsRectItem{

public:
    /**
     * @brief Slot class constructor.
     * @param parent QGraphicsItem default inhereted  parameter of the constructor.
     */
    Slot(QGraphicsItem* parent = nullptr);

    /**
     * @brief Sets the coordinates to display the slot.
     * @param x Real x coordinate.
     * @param y Real y coordinate.
     */
    void registerPos(int x, int y);

    /**
     * @brief Sets the value of multiplier related to the letter hold.
     * @param multiplier Value of multiplier.
     */
    void setMultiplier(int multiplier);

    /**
     * @brief Overwritten method inherited from the QGraphicsRectItem class.
     *        Used for giving style to the tile object.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int x; /**< Real x coordinate. */

    int y; /**< Real Y coordinate. */

    int multiplier; /**< Slot's multiplier value. */

    QColor color; /**< Tile's RGB color. Is determined by the value of multiplier. */

};

#endif // SLOT_H
