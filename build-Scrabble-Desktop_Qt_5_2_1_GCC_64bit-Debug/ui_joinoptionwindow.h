/********************************************************************************
** Form generated from reading UI file 'joinoptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINOPTIONWINDOW_H
#define UI_JOINOPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_JoinOptionWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *nicknameLine;
    QLineEdit *codeLine;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *JoinOptionWindow)
    {
        if (JoinOptionWindow->objectName().isEmpty())
            JoinOptionWindow->setObjectName(QStringLiteral("JoinOptionWindow"));
        JoinOptionWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(JoinOptionWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        nicknameLine = new QLineEdit(JoinOptionWindow);
        nicknameLine->setObjectName(QStringLiteral("nicknameLine"));
        nicknameLine->setGeometry(QRect(210, 70, 111, 25));
        codeLine = new QLineEdit(JoinOptionWindow);
        codeLine->setObjectName(QStringLiteral("codeLine"));
        codeLine->setGeometry(QRect(210, 150, 113, 25));
        label = new QLabel(JoinOptionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 70, 121, 17));
        label_2 = new QLabel(JoinOptionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 150, 141, 20));

        retranslateUi(JoinOptionWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), JoinOptionWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), JoinOptionWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(JoinOptionWindow);
    } // setupUi

    void retranslateUi(QDialog *JoinOptionWindow)
    {
        JoinOptionWindow->setWindowTitle(QApplication::translate("JoinOptionWindow", "Join Game", 0));
        label->setText(QApplication::translate("JoinOptionWindow", "Your Nickname", 0));
        label_2->setText(QApplication::translate("JoinOptionWindow", "Game Acces Code", 0));
    } // retranslateUi

};

namespace Ui {
    class JoinOptionWindow: public Ui_JoinOptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINOPTIONWINDOW_H
