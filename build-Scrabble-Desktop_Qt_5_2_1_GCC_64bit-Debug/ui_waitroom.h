/********************************************************************************
** Form generated from reading UI file 'waitroom.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITROOM_H
#define UI_WAITROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WaitRoom
{
public:
    QPushButton *readyButton;
    QLabel *label1;
    QLabel *label4;
    QLabel *label2;
    QLabel *label3;
    QLabel *p1Label;
    QLabel *p2Label;
    QLabel *p3Label;
    QLabel *p4Label;
    QLabel *textBottomLabel;
    QLabel *titleLabel;
    QLabel *label;
    QLabel *codeLabel;

    void setupUi(QDialog *WaitRoom)
    {
        if (WaitRoom->objectName().isEmpty())
            WaitRoom->setObjectName(QStringLiteral("WaitRoom"));
        WaitRoom->resize(400, 300);
        readyButton = new QPushButton(WaitRoom);
        readyButton->setObjectName(QStringLiteral("readyButton"));
        readyButton->setGeometry(QRect(130, 250, 121, 31));
        label1 = new QLabel(WaitRoom);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(90, 80, 67, 17));
        label4 = new QLabel(WaitRoom);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(90, 170, 67, 17));
        label2 = new QLabel(WaitRoom);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(90, 110, 67, 17));
        label3 = new QLabel(WaitRoom);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(90, 140, 67, 17));
        p1Label = new QLabel(WaitRoom);
        p1Label->setObjectName(QStringLiteral("p1Label"));
        p1Label->setGeometry(QRect(180, 80, 67, 17));
        p2Label = new QLabel(WaitRoom);
        p2Label->setObjectName(QStringLiteral("p2Label"));
        p2Label->setGeometry(QRect(180, 110, 67, 17));
        p3Label = new QLabel(WaitRoom);
        p3Label->setObjectName(QStringLiteral("p3Label"));
        p3Label->setGeometry(QRect(180, 140, 67, 17));
        p4Label = new QLabel(WaitRoom);
        p4Label->setObjectName(QStringLiteral("p4Label"));
        p4Label->setGeometry(QRect(180, 170, 67, 17));
        textBottomLabel = new QLabel(WaitRoom);
        textBottomLabel->setObjectName(QStringLiteral("textBottomLabel"));
        textBottomLabel->setGeometry(QRect(40, 210, 301, 41));
        titleLabel = new QLabel(WaitRoom);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(0, 0, 401, 31));
        titleLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(WaitRoom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 91, 20));
        label->setAlignment(Qt::AlignCenter);
        codeLabel = new QLabel(WaitRoom);
        codeLabel->setObjectName(QStringLiteral("codeLabel"));
        codeLabel->setGeometry(QRect(190, 40, 91, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy);
        codeLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(WaitRoom);

        QMetaObject::connectSlotsByName(WaitRoom);
    } // setupUi

    void retranslateUi(QDialog *WaitRoom)
    {
        WaitRoom->setWindowTitle(QApplication::translate("WaitRoom", "Waiting Room", 0));
        readyButton->setText(QApplication::translate("WaitRoom", "Ready", 0));
        label1->setText(QApplication::translate("WaitRoom", "Player 1: ", 0));
        label4->setText(QApplication::translate("WaitRoom", "Player 4:", 0));
        label2->setText(QApplication::translate("WaitRoom", "Player 2 :", 0));
        label3->setText(QApplication::translate("WaitRoom", "Player 3:", 0));
        p1Label->setText(QString());
        p2Label->setText(QString());
        p3Label->setText(QString());
        p4Label->setText(QString());
        textBottomLabel->setText(QString());
        titleLabel->setText(QApplication::translate("WaitRoom", "Waiting Room", 0));
        label->setText(QApplication::translate("WaitRoom", "Access Code:", 0));
        codeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaitRoom: public Ui_WaitRoom {};

} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITROOM_H
