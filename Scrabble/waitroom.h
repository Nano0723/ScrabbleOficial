#ifndef WAITROOM_H
#define WAITROOM_H

#include <QDialog>
#include <thread>
#include "Connector.h"
#include "gamewindow.h"

namespace Ui {
class WaitRoom;
}

/**
 * @brief Window where the players wait for the game session to begin.
 *        Displays the nicknames of all users waiting.
 */
class WaitRoom : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief WaitRoom class constructor.
     * @param parent QWidget setted to null as default. Necessary for the inheritance.
     */
    explicit WaitRoom(QWidget *parent = nullptr);

    /**
     * @brief WaitRoom class destructor.
     */
    ~WaitRoom();

    /**
     * @brief Adds the nickname of a new player to the window.
     * @param nickname Nickname of a player.
     */
    void addPlayer(std::string nickname);

    /**
     * @brief setUserNickname Sets the nickname of the user.
     * @param nickname User's nickname.
     */
    void setUserNickname(std::string nickname);

    /**
     * @brief setCode Sets the code for displaying it on the window.
     * @param code String of the game access code.
     */
    void setCode(std::string code);

    static WaitRoom* getInstance();

private slots:
    /**
     * @brief Method called when the user clicks "ready" option.
     *        It informs to the server that the player is ready.
     */
    void on_readyButton_clicked();



private:

   // WaitRoom();
    //static WaitRoom* instance;
    Ui::WaitRoom *ui; /**< Qt form of WaitRoom class. Used to arrange the visual objects. */

    Connector *connector; /**< Game interface used for server communication. */

    GameWindow *gameWindow; /**< Instance of GameWindow to create when the session has to start. */

    std::string userNickname; /** < User's nickname. */

};

#endif // WAITROOM_H
