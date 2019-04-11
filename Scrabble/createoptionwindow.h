#ifndef CREATEOPTIONWINDOW_H
#define CREATEOPTIONWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "waitroom.h"
#include "Connector.h"

namespace Ui {
class CreateOptionWindow;
}

/**
 * @brief Create game session window. Is shown the user clicks the "new game" option in the menu.
 */
class CreateOptionWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief CreateOptionWindow default constructor.
     * @param parent QWidget parent object. Refers to the previous window.
     */
    explicit CreateOptionWindow(QWidget *parent = nullptr);

    /**
     * @brief CreateOptionWindow default destructor.
     */
    ~CreateOptionWindow();


    /**
     * @brief setParentWindow Sets a reference to the previous window.
     * @param menu Previous window.
     */
    void setParentWindow(QMainWindow* menu);

    /**
     * @brief setConnector Sets the interface used for server communication.
     * @param connector Interface used for server communication.
     */
    void setConnector(Connector *connector);

private slots:
    /**
     * @brief Method called when the user clicks "ok" option.
     *        It validates the user nickname and maximum of players, if the input is valid is sent to the server.
     */
    void on_buttonBox_accepted();

    /**
     * @brief Method called when the user clicks "cancel" option.
     *        It closes the current window.
     */
    void on_buttonBox_rejected();

private:
    Ui::CreateOptionWindow *ui; /**< Qt form of CreateOptionWindow class. Used to arrange the visual objects. */

    WaitRoom *waitRoom; /**< WaitingRoom to insert the player. When instantiated, is the next window. */

    Connector *connector; /**< Game interface used for server communication. */

    QMainWindow *menu; /**< Reference to the first menu shown. */


};

#endif // CREATEOPTIONWINDOW_H
