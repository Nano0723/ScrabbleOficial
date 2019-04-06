#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamew.h>

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
private slots:
    void jugar();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
