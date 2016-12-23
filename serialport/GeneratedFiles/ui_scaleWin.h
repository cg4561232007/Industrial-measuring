/********************************************************************************
** Form generated from reading UI file 'scaleWin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEWIN_H
#define UI_SCALEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scaleWin
{
public:
    QPushButton *retbt;
    QPushButton *stopbt;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *snapbt;

    void setupUi(QWidget *scaleWin)
    {
        if (scaleWin->objectName().isEmpty())
            scaleWin->setObjectName(QStringLiteral("scaleWin"));
        scaleWin->resize(1171, 594);
        scaleWin->setMinimumSize(QSize(1171, 594));
        scaleWin->setMaximumSize(QSize(1171, 594));
        retbt = new QPushButton(scaleWin);
        retbt->setObjectName(QStringLiteral("retbt"));
        retbt->setGeometry(QRect(1110, 550, 51, 23));
        stopbt = new QPushButton(scaleWin);
        stopbt->setObjectName(QStringLiteral("stopbt"));
        stopbt->setGeometry(QRect(1110, 290, 51, 23));
        label_6 = new QLabel(scaleWin);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 10, 78, 12));
        label_7 = new QLabel(scaleWin);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(990, 560, 78, 22));
        snapbt = new QPushButton(scaleWin);
        snapbt->setObjectName(QStringLiteral("snapbt"));
        snapbt->setGeometry(QRect(1110, 70, 51, 23));

        retranslateUi(scaleWin);

        QMetaObject::connectSlotsByName(scaleWin);
    } // setupUi

    void retranslateUi(QWidget *scaleWin)
    {
        scaleWin->setWindowTitle(QApplication::translate("scaleWin", "Form", 0));
        retbt->setText(QApplication::translate("scaleWin", "\350\277\224\345\233\236", 0));
        stopbt->setText(QApplication::translate("scaleWin", "\345\201\234\346\255\242", 0));
        label_6->setText(QApplication::translate("scaleWin", "y\350\275\264/(10*\345\203\217\347\264\240)", 0));
        label_7->setText(QApplication::translate("scaleWin", "x\350\275\264/(10*\345\203\217\347\264\240)", 0));
        snapbt->setText(QApplication::translate("scaleWin", "\346\210\252\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class scaleWin: public Ui_scaleWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEWIN_H
