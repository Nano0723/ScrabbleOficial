#ifndef GAMEW_H
#define GAMEW_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
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
public:
    Ui::gameW *ui;
    vector<espacios> list;
};

#endif // GAMEW_H
