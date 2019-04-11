#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gameboard.h"
#include "rack.h"
#include <QPushButton>
#include <QLabel>
#include "Connector.h"

namespace Ui {
class GameWindow;
}

/**
 * @brief Game's main window. The gameboard, player's rack and scores are displayed here.
 */

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief GameWindow class constructor.
     * @param parent Previous window.
     */
    explicit GameWindow(QWidget *parent = nullptr);

    /**
     * @brief setConnector Sets the interface used for server communication.
     * @param connector Interface used for server communication.
     */
    void setConnector(Connector *connector);

    /**
     * @brief initializeRack Initializes the player's rack.
     * @param nicknames Nicknames of the players.
     */
    void initializeRack(std::string nicknames[4], std::string userNickname);

    /**
     * @brief GameWindow class destructor.
     */
    ~GameWindow();

    QGraphicsScene *scene; /**< Window QGraphicsScene. All the visual elements are added inside this scene for display. */

private:
    Ui::GameWindow *ui; /**< Previous window. */
    QGraphicsView *view; /**< Class QGraphicsView widget. The scene is added to it for display  purposes. */
    GameBoard *board; /**< Window's gameboard. Used for grid slots display and tile-slot collisions. */
    Rack *rack; /**< Player's rack. Manages all situations around player tile interaction and collisions. */

    QPushButton *scrabbleButton; /**< Button for the game option scrabble. Calls the rack's function with the same name. */
    QPushButton *clearButton; /**< Button for the game option clear. Calls the rack's function with the same name. */
    QPushButton *swappButton; /**< Button for the game option swapp. Calls the rack's function with the same name. */
    QPushButton *passButton; /**< Button for the game option pass. Calls the rack's function with the same name. */

    QLabel *nameAndScore[4][2]; /**< Array containing all current players nicknames and scores. */

    Connector *connector; /**< Game interface used for server communication. */

public slots:

    /**
     * @brief Executes when the player clicks the scrabble option. Calls rack's scrabble method.
     */
    void scrabble_clicked();

    /**
     * @brief Executes when the player clicks the clear option. Calls rack's clear method.
     */
    void clear_clicked();

    /**
     * @brief Executes when the player clicks the swapp option. Calls rack's swapp method.
     */
    void swapp_clicked();

    /**
     * @brief Executes when the player clicks the pass option. Calls rack's pass method.
     */
    void pass_clicked();
};

#endif // MAINWINDOW_H
