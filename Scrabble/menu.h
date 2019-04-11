#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "createoptionwindow.h"
#include "joinoptionwindow.h"
#include "Connector.h"


namespace Ui {
class Menu;
}

/**
 * @brief First menu window displayed to the user.
 *        Contains 3 options: new game, join game and exit.
 *
 */
class Menu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Menu default constructor. Initialize it's parent widget to null.
     * @param parent Parent QWidget.
     */
    explicit Menu(QWidget *parent = nullptr);

    /**
     * @brief Menu default destructor.
     */
    ~Menu();

private slots:
    /**
     * @brief Method called when the user clicks "new game" option.
     *        It pops a CreateOptionWindow instance to the user.
     */
    void on_newGameButton_clicked();

    /**
     * @brief Method called when the user clicks "new game" option.
     *        It pops a JoinOptionWindow instance to the user.
     */
    void on_joinGameButton_clicked();

    /**
     * @brief Method called when the user clicks "exit" option.
     *        It closes the application.
     */
    void on_exitButton_clicked();

private:
    Ui::Menu *ui; /**< Qt form of Menu class. Used to arrange the visual objects. */

    CreateOptionWindow *create; /**< New Game window to create in case of choosing that option. */

    JoinOptionWindow *join; /**< Join Game window to create in case of choosing that option. */

    Connector *connector; /**< Game interface used for server communication. */

};

#endif // MENU_H
