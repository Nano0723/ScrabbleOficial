/********************************************************************************
** Form generated from reading UI file 'createoptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEOPTIONWINDOW_H
#define UI_CREATEOPTIONWINDOW_H

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

class Ui_CreateOptionWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *nicknameLine;
    QLineEdit *playerMaxLine;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *CreateOptionWindow)
    {
        if (CreateOptionWindow->objectName().isEmpty())
            CreateOptionWindow->setObjectName(QStringLiteral("CreateOptionWindow"));
        CreateOptionWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateOptionWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 220, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        nicknameLine = new QLineEdit(CreateOptionWindow);
        nicknameLine->setObjectName(QStringLiteral("nicknameLine"));
        nicknameLine->setGeometry(QRect(200, 70, 113, 25));
        playerMaxLine = new QLineEdit(CreateOptionWindow);
        playerMaxLine->setObjectName(QStringLiteral("playerMaxLine"));
        playerMaxLine->setGeometry(QRect(200, 150, 113, 25));
        label = new QLabel(CreateOptionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 70, 111, 17));
        label_2 = new QLabel(CreateOptionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 150, 151, 20));

        retranslateUi(CreateOptionWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateOptionWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateOptionWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateOptionWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateOptionWindow)
    {
        CreateOptionWindow->setWindowTitle(QApplication::translate("CreateOptionWindow", "New Game", 0));
        label->setText(QApplication::translate("CreateOptionWindow", "Your Nickname", 0));
        label_2->setText(QApplication::translate("CreateOptionWindow", "Maximum Of Players", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOptionWindow: public Ui_CreateOptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEOPTIONWINDOW_H
