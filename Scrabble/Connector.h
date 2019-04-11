#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include "PackTile.h"

/**
 * @brief
 *
 */
class Connector{
public:
    /**
     * @brief Default constructor
     */
    Connector();

    /**
     * @brief Query server is a game exists
     *
     * @param code
     * @return bool
     */
    bool requestGame(std::string code);
    /**
     * @brief Creates a game within server with n players in it
     *
     * @param maximumPlayers
     * @return std::string
     */
    std::string createGame(int maximumPlayers);

    /**
     * @brief Returns n tiles via a user request to the server
     *
     * @param size
     * @param givenTiles[]
     * @return PackTile
     */
    PackTile *getTiles(int size, PackTile givenTiles[7]);

    /**
     * @brief Tells the server one's ready to play
     *
     * @return bool
     */
    bool readyUp();
    /**
     * @brief Query the server whether the game is ready
     *
     * @return bool
     */
    bool isGameReady();
    /**
     * @brief Informes the server of the move and waits for it's response
     *
     * @param tiles[]
     * @return int
     */
    int verifyMove(PackTile tiles[7]);
    std::string updateBoard; /**< TODO: describe */
    /**
     * @brief Starts the game from the GUI prespective
     *
     * @return bool
     */
    bool startGame();
    /**
     * @brief Register user on the server
     *
     * @param nickname
     * @return bool
     */
    bool registerNickname(std::string nickname);
    /**
     * @brief Whether or not is the players turn
     *
     * @return bool
     */
    bool onTurn();
		
private:
    std::string hostIP; /**< describe */
    int port; /**< describe */
    std::string gameCodes[3] = {"aaa", "bbb", "ccc"}; /**< describe */
};

#endif // CONNECTOR_H
