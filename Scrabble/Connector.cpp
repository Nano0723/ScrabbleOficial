#include "Connector.h"
#include <string>
#include "PackTile.h"

/**
 * @brief Default constructor
 *
 */
Connector::Connector()
{
}

/**
 * @brief Query server is a game exists
 *
 * @param code
 * @return bool
 */
bool Connector::requestGame(std::string code)
{
	for(int i = 0;  i < 4; i++){
        if(this->gameCodes[i] == code){
			return true;
        }
    }
    return false;
}

/**
 * @brief Register user on the server
 *
 * @param nickname
 * @return bool
 */
bool Connector::registerNickname(std::string nickname){
    return true;
}

/**
 * @brief Whether or not is the players turn
 *
 * @return bool
 */
bool Connector::onTurn()
{
    return true;
}

/**
 * @brief Tells the server one's ready to play
 *
 * @return bool
 */
bool Connector::readyUp()
{
	return true;
}

/**
 * @brief Creates a game within server with n players in it
 *
 * @param maximumPlayers
 * @return std::string
 */
std::string Connector::createGame(int maximumPlayers)
{
    int number = 2;
    return this->gameCodes[number];
}

/**
 * @brief Returns n tiles via a user request to the server
 *
 * @param size
 * @param givenTiles[]
 * @return PackTile
 */
PackTile *Connector::getTiles(int size, PackTile givenTiles[7]){
    static PackTile tiles[7];
    char alphabet[26] = {'!','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < 7; i++){
		if( i < size){
			int index = ( std::rand() % ( 26 + 1 ) );
			int number = 1 + ( std::rand() % ( 10 ) );
            tiles[i] = PackTile(alphabet[index], number);
		}else{
            tiles[i] = PackTile();
		}	
	}
    return tiles;
}

/**
 * @brief Query the server whether the game is ready
 *
 * @return bool
 */
bool Connector::isGameReady(){
    return true;
}

/**
 * @brief Informes the server of the move and waits for it's response
 *
 * @param tiles[]
 * @return int
 */
int Connector::verifyMove(PackTile tiles[7])
{
    return 15;
}

/**
 * @brief Starts the game from the GUI prespective
 *
 * @return bool
 */
bool Connector::startGame(){
	return true;
}
