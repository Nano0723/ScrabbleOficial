#ifndef JOINOPTIONWINDOW_H
#define JOINOPTIONWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "waitroom.h"
#include "Connector.h"

namespace Ui {
class JoinOptionWindow;
}

/**
 * @brief Join game session window. Is shown the user clicks the "join game" option in the menu.
 */
class JoinOptionWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief JoinOptionWindow default constructor.
     * @param parent QWidget parent object. Refers to the previous window.
     */
    explicit JoinOptionWindow(QWidget *parent = nullptr);

    /**
     * @brief JoinOptionWindow default destructor.
     */
    ~JoinOptionWindow();

    /**
     * @brief setConnector Sets the interface used for server communication.
     * @param connector Interface used for server communication.
     */
    void setConnector(Connector *connector);

    /**
     * @brief setConnector Sets the interface used for server communication.
     * @param connector Interface used for server communication.
     */
    void setParentWindow(QMainWindow* menu);

private slots:
    /**
     * @brief Method called when the user clicks "ok" option.
     *        It validates the user nickname and access code, if the input is valid is sent to the server.
     */
    void on_buttonBox_accepted();

    /**
     * @brief Method called when the user clicks "cancel" option.
     *        It closes the current window.
     */
    void on_buttonBox_rejected();

private:
    Ui::JoinOptionWindow *ui; /**< Qt form of JoinOptionWindow class. Used to arrange the visual objects. */

    WaitRoom *waitRoom; /**< WaitingRoom to insert the player. When instantiated, is the next window. */

    Connector *connector; /**< Game interface used for server communication. */

    QMainWindow *menu; /**< Reference to the first menu shown. */

    QWidget *parent; /**< Previous window. */

};

#endif // JOINOPTIONWINDOW_H
