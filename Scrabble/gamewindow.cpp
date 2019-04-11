
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGraphicsView>
#include "gtile.h"
#include "gameboard.h"
#include "rack.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QFont>

/**
 * @brief GameWindow class constructor.
 * @param parent Previous window.
 */
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setFixedSize(900,700);
    setWindowTitle("Scrabble");

    view = new QGraphicsView(this);
    scene = new QGraphicsScene(0,0,800,750,this);
    scene->setBackgroundBrush(QColor(0,0,0));

    QGraphicsPixmapItem *backgroundImage = scene->addPixmap( QPixmap(":/images/images/bk2.jpg") );
    backgroundImage->setPos(-65,-50);

    QGraphicsPixmapItem *square = scene->addPixmap( QPixmap(":/images/images/square1.png") );
    square->setPos(625,-50);

    view->setScene(scene);
    setCentralWidget(view);

    this->clearButton= new QPushButton;
    clearButton->setGeometry(QRect(359,679,120,40));
    clearButton->setText("Clear");
    QObject::connect(clearButton, SIGNAL(clicked()), this, SLOT(clear_clicked()));
    clearButton->setStyleSheet("QPushButton {background-color: #00802b; color: white;}");
    scene->addWidget(clearButton);

    this->scrabbleButton= new QPushButton;
    scrabbleButton->setGeometry(QRect(359,639,120,40));
    scrabbleButton->setText("Scrabble");
    QObject::connect(scrabbleButton, SIGNAL(clicked()), this, SLOT(scrabble_clicked()));
    scrabbleButton->setStyleSheet("QPushButton {background-color: #990000; color: white;}");
    scene->addWidget(scrabbleButton);

    this->swappButton= new QPushButton;
    swappButton->setGeometry(QRect(479,639,120,40));
    swappButton->setText("Swapp");
    QObject::connect(swappButton, SIGNAL(clicked()), this, SLOT(swapp_clicked()));
    swappButton->setStyleSheet("QPushButton {background-color: #cc9900; color: white;}");
    scene->addWidget(swappButton);

    this->passButton= new QPushButton;
    passButton->setGeometry(QRect(479,679,120,40));
    passButton->setText("Pass");
    QObject::connect(passButton, SIGNAL(clicked()), this, SLOT(pass_clicked()));
    passButton->setStyleSheet("QPushButton {background-color: #003399; color: white;}");
    scene->addWidget(passButton);

    board =  new GameBoard(scene);
    QGraphicsPixmapItem *rackImage = scene->addPixmap( QPixmap(":/images/images/rack2.jpeg") );
    rackImage->setPos(0,680);
}

/**
 * @brief setConnector Sets the interface used for server communication.
 * @param connector Interface used for server communication.
 */
void GameWindow::setConnector(Connector *connector)
{
    this->connector = connector;
}

void GameWindow::initializeRack(std::string nicknames[4], std::string userNickname)
{
    rack = new Rack(scene,this);
    rack->setConnector(connector);
    rack->setTurn(connector->onTurn());
    rack->setNicknames(nicknames);
    rack->setUserNickname(userNickname);
}


/**
 * @brief GameWindow class destructor.
 */
GameWindow::~GameWindow()
{
    delete ui;
}

/**
 * @brief Executes when the player clicks the scrabble option. Calls rack's scrabble method.
 */
void GameWindow::scrabble_clicked()
{
    if(rack->inTurn()){
        if(rack->verifyMove() == "overlaping"){
            QMessageBox::information(this, "Tile overlap.", "There are tiles overlaping each other. Please position just one tile per grid slot.");
        }else if(rack->verifyMove() == "inLockedSlot"){
            QMessageBox::information(this, "On locked Slot.", "There are tiles in slots already occupied.");
            this->rack->clear();
        }else{
            this->rack->scrabble();
        }
    }else{
        QMessageBox::information(this, "User is not in turn.", "It's not your turn. Please wait for the other players to finish their move.");
        this->rack->clear();
    }

}

/**
 * @brief Executes when the player clicks the clear option. Calls rack's clear method.
 */
void GameWindow::clear_clicked()
{
    this->rack->clear();
}

/**
 * @brief Executes when the player clicks the swapp option. Calls rack's swapp method.
 */
void GameWindow::swapp_clicked()
{

    if(rack->inTurn()){
        this->rack->swapp();
    }else{
        QMessageBox::information(this, "User is not in turn.", "It's not your turn. Please wait for the other players to finish their move.");
        this->rack->clear();
    }



}

/**
 * @brief Executes when the player clicks the pass option. Calls rack's pass method.
 */
void GameWindow::pass_clicked()
{
    if(rack->inTurn()){
        this->rack->pass();
    }else{
        QMessageBox::information(this, "User is not in turn.", "It's not your turn. Please wait for the other players to finish their move.");
        this->rack->clear();
    }
}
