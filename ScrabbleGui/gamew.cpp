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
#include <sstream>

string matriz[19][19];
vector<int> posx;
vector<int> posy;
vector<string> letras;
int tempx,firstx = -1,lastx,firsty = -1,lasty;
int tempy,numFichas = 3;
int lastL;
string palabra = "";
using namespace std;
gameW::gameW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameW)
{
    ui->setupUi(this);
    llenarX();
    llenarY();
    connect(ui->Scrabble, SIGNAL(clicked()), this, SLOT(scrabble()));
}

gameW::~gameW()
{
    delete ui;
}
void gameW::changeLabel(string name){
    ui->name->setText(QString::fromStdString(name));
}
void gameW::mousePressEvent(QMouseEvent *event){
    QMimeData *mimeData = new QMimeData;
    if(selectFicha(event, mimeData) && event->button() == Qt::LeftButton){
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
        QWidget::mousePressEvent(event);
    }else if (comp(event->pos().x(),event->pos().y()) && event->button() == Qt::RightButton) {
        int x = (tempx+40)/42;
        int y = (tempy+40)/42;
        MainWindow m;
        qDebug() << y << x << QString::fromStdString(matriz[x][y]);
        if(matriz[x][y] != ""){
            rellenarFichas(x, y);
            numFichas = numFichas + 1;
            matriz[x][y] = "";
            m.crearF(tempx,tempy,"");
        }
    }else if (comp(event->pos().x(),event->pos().y()) && event->button() == Qt::LeftButton) {
        if(firstx == -1){
           firstx = (tempx+40)/42;
           firsty = (tempy+40)/42;
        }else {
           lastx = (tempx+40)/42;
           lasty = (tempy+40)/42;
        }
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
    if(matriz[x][y] == ""){
        numFichas=numFichas-1;
        cambiaFichas();
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
                    return true;
            }else {
                j = j+1;
            }
        }else if(j == sizey) {
            i = i+1;
            j = 0;
        }
    }
    return false;
}
//
bool gameW::selectFicha(QMouseEvent *event, QMimeData *mimeData){
    if(ui->F1->geometry().contains(event->pos())){
            mimeData->setText(ui->F1->text());
            lastL = 1;
            return true;
    }if(ui->F2->geometry().contains(event->pos())){
            mimeData->setText(ui->F2->text());
            lastL = 2;
            return true;
    } if(ui->F3->geometry().contains(event->pos())){
            mimeData->setText(ui->F3->text());
            lastL = 3;
            return true;
    }if(ui->F4->geometry().contains(event->pos())){
            mimeData->setText(ui->F4->text());
            lastL = 4;
            return true;
    }if(ui->F5->geometry().contains(event->pos())){
            mimeData->setText(ui->F5->text());
            lastL = 5;
            return true;
    }if(ui->F6->geometry().contains(event->pos())){
            mimeData->setText(ui->F6->text());
            lastL = 6;
            return true;
    } if(ui->F7->geometry().contains(event->pos())){
            mimeData->setText(ui->F7->text());
            lastL = 7;
            return true;
    }
    else {
        return false;
    }
}
void gameW::cambiaFichas(){
    if(lastL == 1){
        ui->F1->setText("");
    }if(lastL == 2){
        ui->F2->setText("");
    }if(lastL == 3){
        ui->F3->setText("");
    }if(lastL == 4){
        ui->F4->setText("");
    }if(lastL == 5){
        ui->F5->setText("");
    }if(lastL == 6){
        ui->F6->setText("");
    }if(lastL == 7){
        ui->F7->setText("");
    }
}
void gameW::rellenarFichas(int x, int y){
    if(ui->F1->text()==""){
        ui->F1->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F2->text()==""){
        ui->F2->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F3->text()==""){
        ui->F3->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F4->text()==""){
        ui->F4->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F5->text()==""){
        ui->F5->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F6->text()==""){
        ui->F6->setText(QString::fromStdString(matriz[x][y]));
    }
    else if(ui->F7->text()==""){
        ui->F7->setText(QString::fromStdString(matriz[x][y]));
    }
}


void gameW::generarPalabra(){
    int fx = firstx;
    int fy = firsty;
    palabra = "";
    if(lastx==firstx){
        while (firsty<=lasty) {
          palabra = palabra + matriz[firstx][firsty];
          firsty = firsty + 1;
        }firsty = fy;
    }else if(lasty==firsty){
        while (firstx<=lastx) {
            palabra = palabra + matriz[firstx][firsty];
            firstx = firstx + 1;
        }firstx = fx;
    }
}
void gameW::scrabble(){
    //generarPalabra();
    //qDebug() << QString::fromStdString(palabra);
    //dibujar(firstx,firsty,lastx,lasty,palabra);
    vector<string> mano = {"A","B","C","U"};
    qDebug() << mano.size();
    rellenarMano(mano);
}

void gameW::dibujar(int x1,int y1,int x2,int y2,string palabra){
    MainWindow m;
    int i = 0;
    if(x1==x2){
        while (y1<=y2) {
            stringstream ss;
            string letraS;
            char letra = palabra[i];
            ss << letra;
            ss >> letraS;
            m.crearF(((x1-1)*42)+20,((y1-1)*42)+40,letraS);
            matriz[x1][y1] = letraS;
            qDebug() << QString::fromStdString(matriz[0][0]);
            i = i + 1;
            y1 = y1 + 1;
        }
    }else if(y1==y2){
        while(x1<=x2){
            stringstream ss;
            string letraS;
            char letra = palabra[i];
            ss << letra;
            ss >> letraS;
            m.crearF(((x1-1)*42)+20,((y1-1)*42)+40,letraS);
            matriz[x1][y1] = letraS;
            qDebug() << QString::fromStdString(matriz[0][0]);
            i = i + 1;
            x1 = x1 + 1;

        }
   }
}
void gameW::rellenarMano(vector<string> mano){
    for (int i = 0; i<mano.size();i++) {
        if(ui->F1->text()==""){
            ui->F1->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F2->text()==""){
            ui->F2->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F3->text()==""){
            ui->F3->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F4->text()==""){
            ui->F4->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F5->text()==""){
            ui->F5->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F6->text()==""){
            ui->F6->setText(QString::fromStdString(mano[i]));
        }
        else if(ui->F7->text()==""){
            ui->F7->setText(QString::fromStdString(mano[i]));
        }
    }

}

