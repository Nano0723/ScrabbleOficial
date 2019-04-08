#ifndef GAMEW_H
#define GAMEW_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMimeData>
#include <espacios.h>

using namespace std;

namespace Ui {
class gameW;
}

class gameW : public QWidget
{
    Q_OBJECT

public:
    explicit gameW(QWidget *parent = nullptr);
    ~gameW();
public slots:
    void llenarX();
    void llenarY();
    bool comp(int,int);
    void changeLabel(string name);
    void mousePressEvent(QMouseEvent *event);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    bool selectFicha(QMouseEvent *event, QMimeData *mimeData);
    void cambiaFichas();
    void rellenarFichas(int, int);
    void generarPalabra();
    void scrabble();
    void rellenarMano(vector<string>);
    void dibujar(int, int, int, int, string);
public:
    Ui::gameW *ui;
    vector<espacios> list;
};

#endif // GAMEW_H
