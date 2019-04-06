#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <gamew.h>
#include <espacios.h>
#include <lista.h>
#include <nodo.h>
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

void MainWindow::crearF(int a,int b, string dato){
    QLabel *temp = new QLabel(QString::fromStdString(dato),game);
    temp->move(a+17,b+17);
    temp->show();

}