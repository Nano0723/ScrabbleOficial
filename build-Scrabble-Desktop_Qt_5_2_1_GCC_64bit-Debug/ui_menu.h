/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *newGameButton;
    QPushButton *joinGameButton;
    QPushButton *exitButton;
    QLabel *titleLabel;
    QLabel *label;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(802, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        newGameButton->setGeometry(QRect(350, 310, 120, 60));
        newGameButton->setCursor(QCursor(Qt::ArrowCursor));
        newGameButton->setStyleSheet(QStringLiteral(""));
        joinGameButton = new QPushButton(centralwidget);
        joinGameButton->setObjectName(QStringLiteral("joinGameButton"));
        joinGameButton->setGeometry(QRect(350, 470, 120, 60));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(joinGameButton->sizePolicy().hasHeightForWidth());
        joinGameButton->setSizePolicy(sizePolicy1);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(350, 620, 120, 60));
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(45, 35, 700, 200));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-50, -40, 901, 941));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/wood3.jpg")));
        label->setScaledContents(true);
        Menu->setCentralWidget(centralwidget);
        label->raise();
        newGameButton->raise();
        joinGameButton->raise();
        exitButton->raise();
        titleLabel->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", 0));
        newGameButton->setText(QApplication::translate("Menu", "New Game", 0));
        joinGameButton->setText(QApplication::translate("Menu", "Join Game", 0));
        exitButton->setText(QApplication::translate("Menu", "Exit", 0));
        titleLabel->setText(QApplication::translate("Menu", "TextLabel", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
