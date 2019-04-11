#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsRectItem>
#include "slot.h"

/**
 * @brief Scrabble's gameboard class. It manages the creation and display of the grid's slots.
 */
class GameBoard{

public:    
    /**
     * @brief Default constructor of GameBoard class.
     * @param scene Reference to the QGraphicsScene object used for visual display.
     */
    GameBoard(QGraphicsScene* scene);

    Slot *grid[15][15]; /**< Group of slots objects which constitute the graphical grid. */

private:    

    QGraphicsScene* scene; /**< QGraphicsScene object used for grid visual display. */

    /**
     * @brief Returns the word multiplier of a specific grid slot.
     * @param x Slot's x coordinate.
     * @param y Slot's y coordinate.
     * @return int Slot's multiplier.
     */
    int getMultiplier(int x, int y);
};

#endif // GAMEBOARD_H
