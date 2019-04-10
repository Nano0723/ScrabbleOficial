#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamew.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearF(int,int,string);
    vector<string> info0;
    void setVector(vector<string>);
    int getCount();
    void setCount();

private slots:
    void jugar();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
