#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <gamew.h>
#include <QDebug>
#include <thread>
#include "Client.h"

using namespace std;

int main(int argc, char *argv[])
{
    Client* c = Client::getIntance();
    c->connect1();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
