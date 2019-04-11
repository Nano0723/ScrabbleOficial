#include "joinoptionwindow.h"
#include "ui_joinoptionwindow.h"
#include <QMessageBox>
#include <QDebug>

/**
 * @brief JoinOptionWindow default constructor.
 * @param parent QWidget parent object. Refers to the previous window.
 */
JoinOptionWindow::JoinOptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinOptionWindow)
{
    ui->setupUi(this);
    setStyleSheet("QDialog {background: #00802b;}");

    QFont font;
    font.setWeight(QFont::Bold);
    font.setPixelSize(15);

    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label->setStyleSheet("QLabel {color:white;}");
    ui->label_2->setStyleSheet("QLabel {color:white;}");
}

/**
 * @brief JoinOptionWindow default destructor.
 *
 */
JoinOptionWindow::~JoinOptionWindow()
{
    delete ui;
}

/**
 * @brief setConnector Sets the interface used for server communication.
 * @param connector Interface used for server communication.
 */
void JoinOptionWindow::setConnector(Connector *connector)
{
    this->connector = connector;
}

/**
 * @brief setParentWindow Sets a reference to the previous window.
 * @param menu Previous window.
 */
void JoinOptionWindow::setParentWindow(QMainWindow* menu)
{
 this->menu=menu;
}

/**
 * @brief Method called when the user clicks "ok" option.
 *        It validates the user nickname and access code, if the input is valid is sent to the server.
 */
void JoinOptionWindow::on_buttonBox_accepted()
{
    QString qStringNickname = ui->nicknameLine->text();
    std::string nickname = qStringNickname.toUtf8().constData();
    QString qcode = ui->codeLine->text();
    std::string code = qcode.toUtf8().constData();


    if(code==""){
        QMessageBox::information(this,"No code was specified.","Please enter a code.");

    }else if(!connector->requestGame(code)){
        QMessageBox::information(this,"Code not registered.","The code given doesn't correspond to any current game session.");

    }else if(nickname==""){
        QMessageBox::information(this,"No nickname was specified.","Please enter a nickname.");

    }else if(nickname.size() > 12){
        QMessageBox::information(this,"Nickname too large.","Nickname can't be larger than 12.");

    }else{

        this->setStyleSheet("QDialog {background: #F2F2F2;}");

        this->connector->registerNickname(nickname);

        QMessageBox::information(this,"Accesing Session.","Accessing to session "+QString::fromStdString(code));

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
void JoinOptionWindow::on_buttonBox_rejected()
{
    this->close();
}


