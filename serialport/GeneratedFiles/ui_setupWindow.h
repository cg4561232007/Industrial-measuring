/********************************************************************************
** Form generated from reading UI file 'setupWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPWINDOW_H
#define UI_SETUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setupWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *enterBt;

    void setupUi(QWidget *setupWindow)
    {
        if (setupWindow->objectName().isEmpty())
            setupWindow->setObjectName(QStringLiteral("setupWindow"));
        setupWindow->resize(738, 486);
        label = new QLabel(setupWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 70, 401, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label_2 = new QLabel(setupWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 190, 311, 31));
        QFont font1;
        font1.setPointSize(21);
        label_2->setFont(font1);
        enterBt = new QPushButton(setupWindow);
        enterBt->setObjectName(QStringLiteral("enterBt"));
        enterBt->setGeometry(QRect(610, 400, 61, 31));
        QFont font2;
        font2.setPointSize(10);
        enterBt->setFont(font2);

        retranslateUi(setupWindow);

        QMetaObject::connectSlotsByName(setupWindow);
    } // setupUi

    void retranslateUi(QWidget *setupWindow)
    {
        setupWindow->setWindowTitle(QApplication::translate("setupWindow", "\345\234\250\347\272\277\347\233\221\346\265\213\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("setupWindow", "\345\217\230\345\216\213\345\231\250\347\273\225\351\230\273\345\234\250\347\272\277\347\233\221\346\265\213\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("setupWindow", "\350\245\277\345\256\211\344\272\244\351\200\232\345\244\247\345\255\246\345\276\256\347\224\265\345\255\220\345\255\246\351\231\242", 0));
        enterBt->setText(QApplication::translate("setupWindow", "Ener", 0));
    } // retranslateUi

};

namespace Ui {
    class setupWindow: public Ui_setupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWINDOW_H
