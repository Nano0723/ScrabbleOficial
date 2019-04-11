#include "waitroom.h"
#include "ui_waitroom.h"

/**
 * @brief WaitRoom class constructor.
 * @param parent QWidget setted to null as default. Necessary for the inheritance.
 */
WaitRoom::WaitRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitRoom)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("QLabel {background-color : white;color:#333333;}");
    ui->label1->setStyleSheet("QLabel {color:white;}");
    ui->label2->setStyleSheet("QLabel {color:white;}");
    ui->label3->setStyleSheet("QLabel {color:white;}");
    ui->label4->setStyleSheet("QLabel {color:white;}");
    ui->textBottomLabel->setStyleSheet("QLabel {color:white;}");
    ui->p1Label->setStyleSheet("QLabel {color:white;}");
    ui->p2Label->setStyleSheet("QLabel {color:white;}");
    ui->p3Label->setStyleSheet("QLabel {color:white;}");
    ui->p4Label->setStyleSheet("QLabel {color:white;}");
    ui->titleLabel->setStyleSheet("QLabel {background-color : #990000;color:white;}");
    ui->codeLabel->setStyleSheet("QLabel {background-color : white;color:#333333;}");

}

/**
 * @brief WaitRoom class destructor.
 */
WaitRoom::~WaitRoom()
{
    delete ui;
}

//WaitRoom* WaitRoom::instance = 0;

/**
 * @brief Adds the nickname of a new player to the window.
 * @param nickname Nickname of a player.
 */
void WaitRoom::addPlayer(std::string nickname)
{
    if(ui->p1Label->text() == ""){
        ui->p1Label->setText(QString::fromStdString(nickname));
    }else if(ui->p2Label->text() == ""){
        ui->p2Label->setText(QString::fromStdString(nickname));
    }else if(ui->p3Label->text() == ""){
        ui->p3Label->setText(QString::fromStdString(nickname));
    }
}

/**
 * @brief setUserNickname Sets the nickname of the user.
 * @param nickname User's nickname.
 */
void WaitRoom::setUserNickname(std::string nickname)
{
    this->userNickname=nickname;
}

/**
 * @brief setCode Sets the code for displaying it on the window.
 * @param code String of the game access code.
 */
void WaitRoom::setCode(std::string code)
{
    ui->codeLabel->setText(QString::fromStdString(code));
}
/*
WaitRoom *WaitRoom::getInstance()
{
    if (instance == 0)
        {
            instance = new WaitRoom();
        }

        return instance;
}
*/

/**
 * @brief Method called when the user clicks "ready" option.
 *        It informs to the server that the player is ready.
 */
void WaitRoom::on_readyButton_clicked()
{
    // Mock
    addPlayer("Viviana");
    addPlayer("Steven");
    // Mock

    this->connector->readyUp();

    ui->textBottomLabel->setText(QString::fromStdString("Waiting for the other players to be ready..."));

    std::this_thread::sleep_for(std::chrono::seconds(3));

    ui->textBottomLabel->setText(QString::fromStdString("All players ready."));

    std::this_thread::sleep_for(std::chrono::seconds(3));

    this->hide();

    std::string nicknames[4];
    nicknames[0] = ui->p1Label->text().toUtf8().constData();
    nicknames[1] = ui->p2Label->text().toUtf8().constData();
    nicknames[2] = ui->p3Label->text().toUtf8().constData();
    nicknames[3] = ui->p4Label->text().toUtf8().constData();

    gameWindow = new GameWindow();
    gameWindow->setConnector(connector);
    gameWindow->initializeRack(nicknames, userNickname);
    gameWindow->show();

}
