#ifndef GTILE_H
#define GTILE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QMainWindow>

/**
 * @brief Player tile's class. Corresponds to the draggable tiles with which the player interacts.
 */
class Gtile: public QGraphicsRectItem{
public:
    /**
     * @brief Gtile class constructor.
     * @param parent QGraphicsItem default inhereted  parameter of the constructor.
     */
    Gtile(QGraphicsItem* parent = nullptr);

    /**
     * @brief Sets the tile's letter and value.
     * @param letter Tile's displayed letter.
     * @param value Tile's displayed value.
     */
    void setData(char letter, int value);

    /**
     * @brief setParent Passes a reference of the GameWindow being used for display purposes.
     * @param parent Reference to the current GameWindow instance being used.
     */
    void setParent(QMainWindow *parent);

    /**
     * @brief Overwritten method inherited from the QGraphicsRectItem class.
     *        Used for giving style to the tile object.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Update the tile's grid position (each dimension can go from 0 to 14).
     * @param position[] Updated tile's grid position.
     */
    void updatePos(int position[2]);

    /**
     * @brief Sets the tile's anchor point. The anchor point determines the
     *        location in the window in terms of real coordinates.
     * @param anchorPoint Updated tile real position.
     */
    void setAnchorPoint(const QPointF anchorPoint);

    /**
     * @brief Set the tile's anchor point. It's used at the begging of
     *        the turn to determine the tile initial position.
     * @param initialPos Tile position at the begging of the turn.
     */
    void setInitialAnchorPoint(QPointF initialPos);

    /**
     * @brief Returns the tile's initial anchor point of the current turn.
     * @return QPointF Tile's initial anchor point.
     */
    QPointF getInitialAnchorPoint();

    /**
     * @brief Returns the letter displayed in the tile.
     * @return char Tile's letter.
     */
    char getLetter();

    /**
     * @brief Returns the value displayed in the tile.
     * @return int Tile's value.
     */
    int getValue();

    /**
     * @brief Returns the tile's grid position in the Y axis.
     * @return int Tile's grid position in the Y axis.
     */
    int gridY();

    /**
     * @brief Returns the tile's grid position in the X axis.
     * @return int Grid position in the X axis.
     */
    int gridX();

    /**
     * @brief Sets the tile's position in the gameboard in terms of XY axis.
     * @param gridY Grid position in the Y axis.
     * @param gridX Grid position in the X axis.
     */
    void setGridPos(int gridY, int gridX);

    /**
     * @brief Sets the tile's grid position to (-1,-1).
     *        Used to detect when a tile isn't placed.
     */
    void resetGridPos();

    /**
     * @brief Disable the interactivity of the tile.
     *        Causes that nothing happens when the tile is clicked.
     */
    void deactivate();

protected:
    /**
     * @brief Overwritten method inhereted from QGraphicsItem.
     *        Used to make possible the dragging of the tile when pressed.
     * @param event Event occurring on the window.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief Overwritten method inhereted from QGraphicsItem.
     *        Used to detect item collisions and determine the final
     *        position of the tile when dropped.
     * @param event Event occurring on the window.
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool active; /**< Boolean state that determines if the tile is interactive or not. */

    bool pressed; /**< Boolean state that informs if the tile is being dragged. */

    char letter; /**< Tile's displayed letter. */

    int value; /**< Tile's displayed value. */

    int gridPos[2]; /**< Tile's grid position.*/

    QMainWindow *parent; /**< Reference to the current GameWindow instance being used */

    QPointF anchorPoint; /**< Tile's current anchor point, used for window placement. */

    QPointF initialAnchorPoint; /**< Tile's anchor point at the begging of the turn. */

    QPixmap texture; /**< Tile's visual texture. */

    /**
     * @brief Method used to assign the tile texture.
     * @param option Random number that can go from 1 to 7.
     * @return QPixmap A QPixmap object that corresponds to the given option.
     */
    QPixmap getRandomTexture(int option);
    

    /**
     * @brief Determines if the given real position if in the allowed range
     *        of coordinates for interactive objects.
     * @param QPointF Real position of an object.
     * @return bool Validity of the option.
     */
    bool validatePosition(QPointF realPosition);

};

#endif // GTILE_H
