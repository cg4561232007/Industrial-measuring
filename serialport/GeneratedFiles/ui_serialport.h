/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial_port
{
public:
    QAction *actionConnect;
    QAction *actionFFT_transform;
    QAction *actionSave_as;
    QAction *actionSave;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *cbPortName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cbBaudRate;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_15;
    QComboBox *cbdata;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QComboBox *cbPairty;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QComboBox *cbStop;
    QFrame *line_2;
    QFrame *line_3;
    QCheckBox *hexLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbstate;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QTextEdit *editData;
    QTextBrowser *ascdata;
    QTextBrowser *outRangeEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *saveLocal;
    QPushButton *saveAdditon;
    QPushButton *sendData;
    QVBoxLayout *verticalLayout_5;
    QPushButton *clearWindow;
    QPushButton *clearFile;
    QPushButton *sendFile;
    QFrame *line;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *hexSend;
    QCheckBox *showAscii;
    QCheckBox *enterSend;
    QPushButton *autosend;
    QPushButton *clearsend;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openbutton;
    QPushButton *stopShow;
    QTextBrowser *textBrowser;
    QPushButton *retbt;
    QMenuBar *menuBar;
    QMenu *menuQt;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serial_port)
    {
        if (serial_port->objectName().isEmpty())
            serial_port->setObjectName(QStringLiteral("serial_port"));
        serial_port->resize(803, 659);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serial_port->sizePolicy().hasHeightForWidth());
        serial_port->setSizePolicy(sizePolicy);
        serial_port->setMinimumSize(QSize(803, 659));
        serial_port->setMaximumSize(QSize(803, 659));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        serial_port->setFont(font);
        actionConnect = new QAction(serial_port);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionFFT_transform = new QAction(serial_port);
        actionFFT_transform->setObjectName(QStringLiteral("actionFFT_transform"));
        actionSave_as = new QAction(serial_port);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave = new QAction(serial_port);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(serial_port);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 133, 166));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(9);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        cbPortName = new QComboBox(groupBox);
        cbPortName->setObjectName(QStringLiteral("cbPortName"));

        horizontalLayout->addWidget(cbPortName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        cbBaudRate = new QComboBox(groupBox);
        cbBaudRate->setObjectName(QStringLiteral("cbBaudRate"));

        horizontalLayout_2->addWidget(cbBaudRate);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_7->addWidget(label_15);

        cbdata = new QComboBox(groupBox);
        cbdata->setObjectName(QStringLiteral("cbdata"));

        horizontalLayout_7->addWidget(cbdata);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        cbPairty = new QComboBox(groupBox);
        cbPairty->setObjectName(QStringLiteral("cbPairty"));

        horizontalLayout_8->addWidget(cbPairty);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        cbStop = new QComboBox(groupBox);
        cbStop->setObjectName(QStringLiteral("cbStop"));

        horizontalLayout_9->addWidget(cbStop);


        verticalLayout->addLayout(horizontalLayout_9);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 570, 791, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(150, 440, 641, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        hexLabel = new QCheckBox(centralWidget);
        hexLabel->setObjectName(QStringLiteral("hexLabel"));
        hexLabel->setEnabled(true);
        hexLabel->setGeometry(QRect(10, 290, 91, 16));
        hexLabel->setChecked(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(14, 582, 522, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lbstate = new QLabel(layoutWidget);
        lbstate->setObjectName(QStringLiteral("lbstate"));

        horizontalLayout_3->addWidget(lbstate);

        horizontalSpacer_3 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 450, 641, 121));
        editData = new QTextEdit(groupBox_2);
        editData->setObjectName(QStringLiteral("editData"));
        editData->setGeometry(QRect(0, 30, 641, 71));
        ascdata = new QTextBrowser(groupBox_2);
        ascdata->setObjectName(QStringLiteral("ascdata"));
        ascdata->setGeometry(QRect(0, 10, 661, 21));
        outRangeEdit = new QTextBrowser(groupBox_2);
        outRangeEdit->setObjectName(QStringLiteral("outRangeEdit"));
        outRangeEdit->setGeometry(QRect(0, 100, 661, 21));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 320, 121, 82));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        saveLocal = new QPushButton(layoutWidget1);
        saveLocal->setObjectName(QStringLiteral("saveLocal"));
        saveLocal->setMinimumSize(QSize(54, 22));
        saveLocal->setMaximumSize(QSize(54, 22));

        verticalLayout_4->addWidget(saveLocal);

        saveAdditon = new QPushButton(layoutWidget1);
        saveAdditon->setObjectName(QStringLiteral("saveAdditon"));
        saveAdditon->setMinimumSize(QSize(54, 22));
        saveAdditon->setMaximumSize(QSize(54, 22));

        verticalLayout_4->addWidget(saveAdditon);

        sendData = new QPushButton(layoutWidget1);
        sendData->setObjectName(QStringLiteral("sendData"));
        sendData->setMinimumSize(QSize(54, 22));
        sendData->setMaximumSize(QSize(54, 22));

        verticalLayout_4->addWidget(sendData);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        clearWindow = new QPushButton(layoutWidget1);
        clearWindow->setObjectName(QStringLiteral("clearWindow"));
        clearWindow->setMinimumSize(QSize(54, 22));
        clearWindow->setMaximumSize(QSize(54, 22));

        verticalLayout_5->addWidget(clearWindow);

        clearFile = new QPushButton(layoutWidget1);
        clearFile->setObjectName(QStringLiteral("clearFile"));
        clearFile->setMinimumSize(QSize(54, 22));
        clearFile->setMaximumSize(QSize(54, 22));

        verticalLayout_5->addWidget(clearFile);

        sendFile = new QPushButton(layoutWidget1);
        sendFile->setObjectName(QStringLiteral("sendFile"));
        sendFile->setMinimumSize(QSize(54, 22));
        sendFile->setMaximumSize(QSize(54, 22));

        verticalLayout_5->addWidget(sendFile);


        horizontalLayout_4->addLayout(verticalLayout_5);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(780, 450, 20, 131));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 420, 131, 151));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 91, 120));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        hexSend = new QCheckBox(layoutWidget2);
        hexSend->setObjectName(QStringLiteral("hexSend"));
        hexSend->setChecked(true);

        verticalLayout_3->addWidget(hexSend);

        showAscii = new QCheckBox(layoutWidget2);
        showAscii->setObjectName(QStringLiteral("showAscii"));

        verticalLayout_3->addWidget(showAscii);

        enterSend = new QCheckBox(layoutWidget2);
        enterSend->setObjectName(QStringLiteral("enterSend"));

        verticalLayout_3->addWidget(enterSend);

        autosend = new QPushButton(layoutWidget2);
        autosend->setObjectName(QStringLiteral("autosend"));
        autosend->setMaximumSize(QSize(70, 23));

        verticalLayout_3->addWidget(autosend);

        clearsend = new QPushButton(layoutWidget2);
        clearsend->setObjectName(QStringLiteral("clearsend"));
        clearsend->setMaximumSize(QSize(70, 23));

        verticalLayout_3->addWidget(clearsend);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(60, 191, 77, 54));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openbutton = new QPushButton(layoutWidget3);
        openbutton->setObjectName(QStringLiteral("openbutton"));
        openbutton->setMinimumSize(QSize(61, 0));
        openbutton->setFont(font1);
        openbutton->setIconSize(QSize(12, 12));

        verticalLayout_2->addWidget(openbutton);

        stopShow = new QPushButton(layoutWidget3);
        stopShow->setObjectName(QStringLiteral("stopShow"));

        verticalLayout_2->addWidget(stopShow);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(150, 10, 631, 431));
        retbt = new QPushButton(centralWidget);
        retbt->setObjectName(QStringLiteral("retbt"));
        retbt->setGeometry(QRect(704, 580, 51, 23));
        serial_port->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox->raise();
        line_2->raise();
        line_3->raise();
        hexLabel->raise();
        groupBox_2->raise();
        line->raise();
        groupBox_3->raise();
        textBrowser->raise();
        retbt->raise();
        menuBar = new QMenuBar(serial_port);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 23));
        menuQt = new QMenu(menuBar);
        menuQt->setObjectName(QStringLiteral("menuQt"));
        serial_port->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serial_port);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serial_port->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serial_port);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serial_port->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(cbPortName);
        label_2->setBuddy(cbBaudRate);
        label_15->setBuddy(cbdata);
        label->setBuddy(cbPairty);
        label_4->setBuddy(cbStop);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuQt->menuAction());

        retranslateUi(serial_port);

        QMetaObject::connectSlotsByName(serial_port);
    } // setupUi

    void retranslateUi(QMainWindow *serial_port)
    {
        serial_port->setWindowTitle(QApplication::translate("serial_port", "Qt\344\277\241\345\217\267\350\260\203\350\257\225\345\244\204\347\220\206\347\250\213\345\272\217", 0));
        actionConnect->setText(QApplication::translate("serial_port", "connect", 0));
        actionFFT_transform->setText(QApplication::translate("serial_port", "FFT transform", 0));
        actionSave_as->setText(QApplication::translate("serial_port", "save as", 0));
        actionSave->setText(QApplication::translate("serial_port", "save", 0));
        groupBox->setTitle(QApplication::translate("serial_port", "\345\237\272\346\234\254\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("serial_port", "\344\270\262\345\217\243", 0));
        label_2->setText(QApplication::translate("serial_port", "\346\263\242\347\211\271\347\216\207", 0));
        label_15->setText(QApplication::translate("serial_port", "\346\225\260\346\215\256\344\275\215", 0));
        label->setText(QApplication::translate("serial_port", "\346\240\241\351\252\214\344\275\215", 0));
        label_4->setText(QApplication::translate("serial_port", "\345\201\234\346\255\242\344\275\215", 0));
        hexLabel->setText(QApplication::translate("serial_port", "16\350\277\233\345\210\266\346\230\276\347\244\272", 0));
        label_5->setText(QApplication::translate("serial_port", "com\345\217\243\347\212\266\346\200\201\357\274\232", 0));
        lbstate->setText(QApplication::translate("serial_port", "com1\345\267\262\345\205\263\351\227\255", 0));
        label_10->setText(QApplication::translate("serial_port", "\345\217\221\351\200\201\357\274\232", 0));
        label_9->setText(QApplication::translate("serial_port", "0", 0));
        label_7->setText(QApplication::translate("serial_port", "\346\216\245\346\224\266\357\274\232", 0));
        label_8->setText(QApplication::translate("serial_port", "0", 0));
        groupBox_2->setTitle(QString());
        saveLocal->setText(QApplication::translate("serial_port", "\344\277\235\345\255\230", 0));
        saveAdditon->setText(QApplication::translate("serial_port", "\345\217\246\345\255\230\344\270\272", 0));
        sendData->setText(QApplication::translate("serial_port", "\345\217\221\351\200\201", 0));
        clearWindow->setText(QApplication::translate("serial_port", "\346\270\205\347\251\272\346\230\276\347\244\272", 0));
        clearFile->setText(QApplication::translate("serial_port", "\346\270\205\351\231\244", 0));
        sendFile->setText(QApplication::translate("serial_port", "\345\217\221\351\200\201\346\226\207\344\273\266", 0));
        groupBox_3->setTitle(QApplication::translate("serial_port", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        hexSend->setText(QApplication::translate("serial_port", "16\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        showAscii->setText(QApplication::translate("serial_port", "\346\230\276\347\244\272ASCII\347\240\201", 0));
        enterSend->setText(QApplication::translate("serial_port", "\345\212\240\345\233\236\350\275\246\345\217\221\351\200\201", 0));
        autosend->setText(QApplication::translate("serial_port", "\350\207\252\345\212\250\345\217\221\351\200\201", 0));
        clearsend->setText(QApplication::translate("serial_port", "\346\270\205\351\231\244\345\217\221\351\200\201 ", 0));
        openbutton->setText(QApplication::translate("serial_port", "open", 0));
        stopShow->setText(QApplication::translate("serial_port", "\345\201\234\346\255\242", 0));
        retbt->setText(QApplication::translate("serial_port", "\350\277\224\345\233\236", 0));
        menuQt->setTitle(QApplication::translate("serial_port", "Base", 0));
    } // retranslateUi

};

namespace Ui {
    class serial_port: public Ui_serial_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
