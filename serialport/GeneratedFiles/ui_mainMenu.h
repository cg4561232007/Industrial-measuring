/********************************************************************************
** Form generated from reading UI file 'mainMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QPushButton *autocheckbt;
    QPushButton *fixcheckbt;
    QPushButton *plotbt;
    QPushButton *showhisbt;
    QPushButton *commbt;
    QPushButton *returnbt;
    QFrame *line_2;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QRadioButton *wirelessbt;
    QRadioButton *wiredbt;
    QPushButton *setButton;

    void setupUi(QWidget *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName(QStringLiteral("mainMenu"));
        mainMenu->resize(720, 451);
        mainMenu->setMinimumSize(QSize(720, 451));
        mainMenu->setMaximumSize(QSize(720, 451));
        autocheckbt = new QPushButton(mainMenu);
        autocheckbt->setObjectName(QStringLiteral("autocheckbt"));
        autocheckbt->setGeometry(QRect(240, 170, 241, 31));
        fixcheckbt = new QPushButton(mainMenu);
        fixcheckbt->setObjectName(QStringLiteral("fixcheckbt"));
        fixcheckbt->setGeometry(QRect(240, 120, 241, 31));
        plotbt = new QPushButton(mainMenu);
        plotbt->setObjectName(QStringLiteral("plotbt"));
        plotbt->setGeometry(QRect(240, 220, 241, 31));
        showhisbt = new QPushButton(mainMenu);
        showhisbt->setObjectName(QStringLiteral("showhisbt"));
        showhisbt->setGeometry(QRect(240, 270, 241, 31));
        commbt = new QPushButton(mainMenu);
        commbt->setObjectName(QStringLiteral("commbt"));
        commbt->setGeometry(QRect(240, 60, 241, 31));
        returnbt = new QPushButton(mainMenu);
        returnbt->setObjectName(QStringLiteral("returnbt"));
        returnbt->setGeometry(QRect(20, 400, 51, 23));
        line_2 = new QFrame(mainMenu);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(150, 130, 91, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(mainMenu);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(170, 180, 71, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(mainMenu);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(170, 230, 71, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(mainMenu);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(160, 190, 16, 51));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(mainMenu);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(148, 210, 20, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        wirelessbt = new QRadioButton(mainMenu);
        wirelessbt->setObjectName(QStringLiteral("wirelessbt"));
        wirelessbt->setGeometry(QRect(100, 130, 51, 21));
        wiredbt = new QRadioButton(mainMenu);
        wiredbt->setObjectName(QStringLiteral("wiredbt"));
        wiredbt->setGeometry(QRect(100, 210, 51, 21));
        setButton = new QPushButton(mainMenu);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(640, 20, 61, 23));

        retranslateUi(mainMenu);

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QWidget *mainMenu)
    {
        mainMenu->setWindowTitle(QApplication::translate("mainMenu", "\344\270\273\350\217\234\345\215\225", 0));
        autocheckbt->setText(QApplication::translate("mainMenu", "1KHZ-1MHZ \350\207\252\345\212\250\345\267\241\346\243\200", 0));
        fixcheckbt->setText(QApplication::translate("mainMenu", "\345\256\232\347\202\271\346\243\200\346\237\245", 0));
        plotbt->setText(QApplication::translate("mainMenu", "\346\265\213\351\207\217\346\233\262\347\272\277\347\273\230\345\210\266", 0));
        showhisbt->setText(QApplication::translate("mainMenu", "\346\225\260\346\215\256\345\233\236\346\224\276", 0));
        commbt->setText(QApplication::translate("mainMenu", "\344\270\262\345\217\243\346\216\245\346\224\266\346\225\260\346\215\256", 0));
        returnbt->setText(QApplication::translate("mainMenu", "\350\277\224\345\233\236", 0));
        wirelessbt->setText(QApplication::translate("mainMenu", "\346\227\240\347\272\277", 0));
        wiredbt->setText(QApplication::translate("mainMenu", "\346\234\211\347\272\277", 0));
        setButton->setText(QApplication::translate("mainMenu", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
