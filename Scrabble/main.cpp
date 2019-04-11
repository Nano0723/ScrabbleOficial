
#include "gamewindow.h"
#include <QApplication>
#include <thread>
#include <iostream>
#include <QDebug>
#include "menu.h"
#include "Connector.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    Menu *menu = new Menu();
    menu->show();

    return a.exec();
}


