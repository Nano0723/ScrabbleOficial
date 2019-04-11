#include "createoptionwindow.h"
#include "ui_createoptionwindow.h"
#include <QMessageBox>
#include <QDebug>

/**
 * @brief CreateOptionWindow default constructor.
 * @param parent QWidget parent object. Refers to the previous window.
 */
CreateOptionWindow::CreateOptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateOptionWindow)
{
    ui->setupUi(this);

    setStyleSheet("QDialog {background: #990000;}");

    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(15);

    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label->setStyleSheet("QLabel {color:white;}");
    ui->label_2->setStyleSheet("QLabel {color:white;}");
}

/**
 * @brief setConnector Sets the interface used for server communication.
 * @param connector Interface used for server communication.
 */
void CreateOptionWindow::setConnector(Connector *connector)
{
    this->connector = connector;
}

/**
 * @brief CreateOptionWindow default destructor.
 */
CreateOptionWindow::~CreateOptionWindow()
{
    delete ui;
}

/**
 * @brief setParentWindow Sets a reference to the previous window.
 * @param menu Previous window.
 */
void CreateOptionWindow::setParentWindow(QMainWindow* menu)
{
 this->menu=menu;
}

/**
 * @brief Method called when the user clicks "ok" option.
 *        It validates the user nickname and maximum of players, if the input is valid is sent to the server.
 */
void CreateOptionWindow::on_buttonBox_accepted()
{
    QString qStringNickname = ui->nicknameLine->text();
    std::string nickname = qStringNickname.toUtf8().constData();
    int max = ui->playerMaxLine->text().toInt();

    if(max < 2 || max > 4){
        QMessageBox::information(this,"Maximun not valid.","Number of players can go from 2 to 4.");

    }else if(max==0){
        QMessageBox::information(this,"No maximum was specified.","Please enter a maximum number of players (2-4).");

    }else if(nickname==""){
        QMessageBox::information(this,"No nickname was specified.","Please enter a nickname.");

    }else if(nickname.size() > 12){
        QMessageBox::information(this,"Nickname too large.","Nickname can't be larger than 12.");

    }else{
        this->hide();

        this->setStyleSheet("QDialog {background: #F2F2F2;}");

        this->connector->registerNickname(nickname);

        std::string code = this->connector->createGame(max);
        QMessageBox::information(this,"Access Code.","The access code of your session is: "+ QString::fromStdString(code));

        menu->hide();

        setStyleSheet("QDialog {background: #333333;}");
        waitRoom = new WaitRoom(this);
        waitRoom->setCode(code);
        waitRoom->addPlayer(nickname);
        waitRoom->setUserNickname(nickname);
        waitRoom->show();

    }
}

/**
 * @brief Method called when the user clicks "cancel" option.
 *        It closes the current window.
 */
void CreateOptionWindow::on_buttonBox_rejected()
{
    this->close();
}
