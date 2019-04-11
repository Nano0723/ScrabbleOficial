#ifndef RACK_H
#define RACK_H

#include "gtile.h"
#include <QGraphicsScene>
#include "gameboard.h"
#include "slot.h"
#include <QMainWindow>
#include "PackTile.h"
#include <QLabel>
#include "Connector.h"
#include "PackTile.h"

/**
 * @brief Player's tile rack. Manages all the interactions between the player and the tiles,
 *        as well as triggering the interaction between the server and the player.
 */
class Rack
{
public:
    /**
     * @brief Rack class constructor.
     * @param scene Graphic Scene where the rack will be displayed.
     * @param window Reference to the current GameWindow window.
     */
    Rack(QGraphicsScene* scene, QMainWindow* window);

    /**
     * @brief setNicknames Sets the nicknames of the players in the window.
     * @param nicknames Nicknames of all players.
     */
    void setNicknames(std::string nicknames[4]);

    /**
     * @brief Verifies that the positioning of the tiles in the game board is valid,
     *        if it is, sends the move's tiles to the server for logic processing.
     */
    void scrabble();

    /**
     * @brief Moves all the tiles that where position in the game board in the
     *        current turn back to their initial position in the rack.
     *
     */
    void clear();

    /**
     * @brief Changes all the current tiles in the rack for others. It gets them
     *        by making a request to the server.
     */
    void swapp();

    /**
     * @brief Informs to the server that the player
     *        wants to skip his turn.
     */
    void pass();

    /**
     * @brief Checks the data of all placed tiles to verify if there
     *        is any kind of tile overlapping in the game board. Returns
     *        a empty string if there is no overlaping.
     * @return std::string Type of overlaped detected.
     */
    std::string verifyMove();

    /**
     * @brief Sets if the player is on turn or not.
     * @param inTurn New state of player's turn.
     */
    void setTurn(bool inTurn);

    /**
     * @brief Returns if the player is on turn or not.
     * @return bool State of player's turn.
     */
    bool inTurn();

    /**
     * @brief Registers and draws a move constisting in a group
     *        of tiles to the gameboard.
     * @param move[] Array of tiles.
     */
    void registerMove(PackTile move[7]);

    /**
     * @brief Registers and draws the current word in the gameboard.
     */
    void registerMove();

    /**
     * @brief setConnector Sets the interface used for server communication.
     * @param connector Interface used for server communication.
     */
    void setConnector(Connector *connector);

    /**
     * @brief setUserNickname Sets the nickname of the user.
     * @param nickname User's nickname.
     */
    void setUserNickname(std::string nickname);

    QGraphicsScene* scene; /**< QGraphicsScene object being used for display. */

    QMainWindow* window; /**< Reference to the current GameWindow instance being used */

private:

    /**
     * @brief Updates all the tiles in the stack.
     * Used after a move is done and tiles are lock
     * into the gameboard
     */
    void updateTiles();

    /**
     * @brief Sets all the tiles placed in the grid
     *        into the class member tempPackage.
     */
    void setPackedRack();

    /**
     * @brief Transform a PackTile into Gtile.
     *        Used for server communication.
     * @param packTile An instance of PackTile.
     * @param placed Indicates if the PackTile has registered grid coordinates.
     * @return Gtile A Gtile version of the PackTile.
     */
    Gtile *getGtile(PackTile packTile, bool placed);

    /**
     * @brief Transform a Gtile into a PackTile.
     *        Used for server communication.
     *        This transformation doesn't manages the grid position.
     * @param gtile An instance of GTile.
     * @return PackTile A PackTile version of the Gtile.
     */
    PackTile *getPackTile(Gtile *gtile);

    /**
     * @brief Transform a Gtile into a PackTile.
     *        Used for server communication.
     *        This transformation manages the grid position.
     * @param gtile An instance of GTile.
     * @param gridY Tile's Y grid position.
     * @param gridX Tile's X grid position.
     * @return PackTile A PackTile version of the Gtile.
     */
    PackTile *getPackTile(Gtile *gtile, int gridY, int gridX);

    /**
     * @brief requestTiles Ask to the server for tiles. Used when restocking or swapping happens.
     * @param option Option used to ask tiles. Swapping or restock are expected.
     */
    void requestTiles(std::string option);

    /**
     * @brief setRackTiles Sets a group of PackTiles to the tiles of the rack.
     * @param rackTiles Group of PackTiles.
     */
    void setRackTiles(PackTile *rackTiles);

    QPointF rackPositions[7]; /**< Array of coordinates used for placing tiles into the rack. */

    PackTile packedRack[7]; /**< Array of PackTile used for sending a move to the server. */

    Connector *connector; /**< Game interface used for server communication. */

    QLabel *user_score[4][2]; /**< Array of QLabel used to display the nicknames and their scores. */

    Gtile *rackTiles[7]; /**< Array of interactive tiles handled in the stack. */

    int playerScore; /**< Game score of the user running the client. */

    int rackSize; /**< Number of tiles in the rack. */

    bool inturn = true; /**< Boolean state that describes if the user is on turn. */

    bool lockedGridSlots[15][15]; /**< Array used to register the locked tiles when a valid move is done. */

    std::string userNickname; /** < User's nickname. */

};

#endif // RACK_H

