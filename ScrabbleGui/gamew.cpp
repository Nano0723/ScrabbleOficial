#include "gamew.h"
#include "ui_gamew.h"
#include <iostream>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <math.h>
#include <vector>
#include <espacios.h>
#include <mainwindow.h>

string matriz[19][19];
vector<int> posx;
vector<int> posy;
int tempx;
int tempy;
using namespace std;

gameW::gameW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameW)
{
    ui->setupUi(this);
    llenarX();
    llenarY();
}

gameW::~gameW()
{
    delete ui;
}
void gameW::changeLabel(string name){
    ui->name->setText(QString::fromStdString(name));
}
void gameW::mousePressEvent(QMouseEvent *event){
    if(ui->ficha->geometry().contains(event->pos()) && event->button() == Qt::LeftButton){
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText(ui->ficha->objectName());
        drag->setMimeData(mimeData);
        Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
        QWidget::mousePressEvent(event);
    }
}


void gameW::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasFormat("text/plain")){
        event->acceptProposedAction();
    }
}
void gameW::dropEvent(QDropEvent *event){
    if(comp(event->pos().x(),event->pos().y())){
    string dato = (event->mimeData()->text()).toStdString();
    MainWindow m;
    int x = (tempx+40)/42;
    int y = (tempy+40)/42;
    qDebug() << QString::fromStdString(matriz[x][y]);
    if(matriz[x][y] == ""){
        m.crearF(tempx,tempy,dato);
        matriz[x][y] = dato;
    }
    }
}
void gameW::llenarX(){
    int x = 20;
    for (int i = 0; i<18 ;i++) {
        posx.push_back(x);
        x = x + 42;
    }
}

void gameW::llenarY(){
    int y = 40;
    for (int i = 0; i<18 ;i++) {
        posy.push_back(y);
        y = y + 42;
    }
}

bool gameW::comp(int pos_x, int pos_y){
    int i = 0;
    int j = 0;
    int sizex = 18;
    int sizey = 18;
    while(i<posx.size()){
        if(j<posy.size()){
            if((pos_x>=posx[i] && pos_x<=posx[i]+42) && (pos_y>=posy[j] && pos_y<=posy[j]+42)){
                    tempx = posx[i];
                    tempy = posy[j];
                    qDebug() << "end";
                    return true;
            }else {
                j = j+1;
            }
        }else if(j == sizey) {
            i = i+1;
            j = 0;
        }
    }
    qDebug() << "nada de nada";
    return false;
}




