#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <gamew.h>
#include <espacios.h>
#include <lista.h>
#include <nodo.h>
#include <vector>

using namespace std;

string name;
gameW *game;
espacios *esp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnJugar, SIGNAL(clicked()), this, SLOT(jugar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::jugar(){
    name = ui->lineEdit->text().toStdString();
    game = new gameW();
    game->changeLabel("Jugador: " + name);
    this->hide();

    game->show();

}
void MainWindow:: setVector(vector<string> x){
    info0 = x;
}

int MainWindow:: getCount(){
    return game->count;
}
void MainWindow::setCount(){
    game->count = 0;

}

void MainWindow::crearF(int a,int b, string dato){
    if(dato != ""){
        QLabel *temp = new QLabel(QString::fromStdString(dato),game);
        temp->move(a+17,b+17);
        temp->show();
    }else {
        QLabel *temp = new QLabel(game);;
        temp->move(a,b);
        QPixmap *pixmap = new QPixmap(":/Images/Cuadro.jpeg");
        temp->setPixmap(*pixmap);
        temp->show();
    }

}





