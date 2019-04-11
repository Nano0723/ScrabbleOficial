#include "menu.h"
#include "ui_menu.h"

/**
 * @brief Menu default constructor. Initialize it's parent widget to null.
 * @param parent Parent QWidget.
 */
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Scrabble");

    QPixmap bkgnd(":/images/images/bk2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    QPixmap titleImage(":/images/images/title3.png");
    ui->titleLabel->setPixmap(titleImage);

    ui->newGameButton->setStyleSheet("QPushButton {background-color: #990000; color: white;}");
    ui->joinGameButton->setStyleSheet("QPushButton {background-color: #00802b; color: white;}");
    ui->exitButton->setStyleSheet("QPushButton {background-color: #404040; color: white;}");

    this->connector = new Connector();
}

/**
 * @brief Menu default destructor.
 */
Menu::~Menu()
{
    delete ui;
}

/**
 * @brief Method called when the user clicks "new game" option.
 *        It pops a CreateOptionWindow instance to the user.
 */
void Menu::on_newGameButton_clicked()
{
    create = new CreateOptionWindow(this);
    create->setParentWindow(this);
    create->setConnector(this->connector);
    create->show();
}

/**
 * @brief Method called when the user clicks "new game" option.
 *        It pops a JoinOptionWindow instance to the user.
 */
void Menu::on_joinGameButton_clicked()
{
    join = new JoinOptionWindow(this);
    join->setParentWindow(this);
    join->setConnector(this->connector);
    join->show();
}

/**
 * @brief Method called when the user clicks "exit" option.
 *        It closes the application.
 */
void Menu::on_exitButton_clicked()
{
    this->close();
}
