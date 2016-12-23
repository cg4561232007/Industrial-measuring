/********************************************************************************
** Form generated from reading UI file 'fftwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFTWINDOW_H
#define UI_FFTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fftwindowUi
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fftwindowUi)
    {
        if (fftwindowUi->objectName().isEmpty())
            fftwindowUi->setObjectName(QStringLiteral("fftwindowUi"));
        fftwindowUi->resize(965, 538);
        centralwidget = new QWidget(fftwindowUi);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        fftwindowUi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(fftwindowUi);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 965, 23));
        fftwindowUi->setMenuBar(menubar);
        statusbar = new QStatusBar(fftwindowUi);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fftwindowUi->setStatusBar(statusbar);

        retranslateUi(fftwindowUi);

        QMetaObject::connectSlotsByName(fftwindowUi);
    } // setupUi

    void retranslateUi(QMainWindow *fftwindowUi)
    {
        fftwindowUi->setWindowTitle(QApplication::translate("fftwindowUi", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class fftwindowUi: public Ui_fftwindowUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFTWINDOW_H
