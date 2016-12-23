/********************************************************************************
** Form generated from reading UI file 'connectTcp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTTCP_H
#define UI_CONNECTTCP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connectTcp_class
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *sendBt;
    QLabel *label_8;
    QGroupBox *groupBox;
    QPushButton *sendFileBt;
    QPushButton *sendImgBt;
    QPushButton *sendMp3Bt;
    QListWidget *socketWd;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *ipGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *stateLabel;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *IPline;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Portline;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *linkButton;
    QPushButton *cancelbt;
    QWidget *page_2;
    QProgressBar *progressBar;
    QPushButton *pushButton_5;
    QLabel *label_6;
    QLabel *serverlabel;
    QListWidget *usrList;
    QLabel *labelImg;
    QLabel *filelabel;
    QLabel *fstatelabel;
    QProgressBar *sendfilebar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *connectTcp_class)
    {
        if (connectTcp_class->objectName().isEmpty())
            connectTcp_class->setObjectName(QStringLiteral("connectTcp_class"));
        connectTcp_class->resize(853, 677);
        centralwidget = new QWidget(connectTcp_class);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 10, 111, 16));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 190, 91, 16));
        label_5->setFont(font);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 30, 511, 141));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 210, 511, 61));
        sendBt = new QPushButton(centralwidget);
        sendBt->setObjectName(QStringLiteral("sendBt"));
        sendBt->setGeometry(QRect(30, 280, 61, 23));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 280, 91, 21));
        label_8->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 320, 261, 211));
        sendFileBt = new QPushButton(groupBox);
        sendFileBt->setObjectName(QStringLiteral("sendFileBt"));
        sendFileBt->setGeometry(QRect(30, 70, 75, 23));
        sendImgBt = new QPushButton(groupBox);
        sendImgBt->setObjectName(QStringLiteral("sendImgBt"));
        sendImgBt->setGeometry(QRect(150, 70, 75, 23));
        sendMp3Bt = new QPushButton(groupBox);
        sendMp3Bt->setObjectName(QStringLiteral("sendMp3Bt"));
        sendMp3Bt->setGeometry(QRect(30, 110, 75, 23));
        socketWd = new QListWidget(centralwidget);
        socketWd->setObjectName(QStringLiteral("socketWd"));
        socketWd->setGeometry(QRect(650, 10, 191, 51));
        socketWd->setMovement(QListView::Static);
        socketWd->setFlow(QListView::LeftToRight);
        socketWd->setProperty("isWrapping", QVariant(false));
        socketWd->setResizeMode(QListView::Adjust);
        socketWd->setViewMode(QListView::ListMode);
        socketWd->setWordWrap(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(650, 70, 201, 201));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        ipGroup = new QGroupBox(page);
        ipGroup->setObjectName(QStringLiteral("ipGroup"));
        ipGroup->setGeometry(QRect(0, 0, 181, 161));
        verticalLayout = new QVBoxLayout(ipGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(ipGroup);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        stateLabel = new QLabel(ipGroup);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));

        horizontalLayout_4->addWidget(stateLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(ipGroup);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        IPline = new QLineEdit(ipGroup);
        IPline->setObjectName(QStringLiteral("IPline"));

        horizontalLayout->addWidget(IPline);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(ipGroup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        label_7 = new QLabel(ipGroup);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_2->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Portline = new QLineEdit(ipGroup);
        Portline->setObjectName(QStringLiteral("Portline"));

        horizontalLayout_5->addWidget(Portline);

        lineEdit = new QLineEdit(ipGroup);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        linkButton = new QPushButton(ipGroup);
        linkButton->setObjectName(QStringLiteral("linkButton"));

        horizontalLayout_3->addWidget(linkButton);

        cancelbt = new QPushButton(ipGroup);
        cancelbt->setObjectName(QStringLiteral("cancelbt"));

        horizontalLayout_3->addWidget(cancelbt);


        verticalLayout->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        progressBar = new QProgressBar(page_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 60, 121, 23));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 120, 61, 21));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 90, 151, 21));
        label_6->setFont(font);
        serverlabel = new QLabel(page_2);
        serverlabel->setObjectName(QStringLiteral("serverlabel"));
        serverlabel->setGeometry(QRect(10, 30, 171, 20));
        stackedWidget->addWidget(page_2);
        usrList = new QListWidget(centralwidget);
        usrList->setObjectName(QStringLiteral("usrList"));
        usrList->setGeometry(QRect(550, 30, 91, 181));
        labelImg = new QLabel(centralwidget);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setGeometry(QRect(420, 310, 411, 331));
        filelabel = new QLabel(centralwidget);
        filelabel->setObjectName(QStringLiteral("filelabel"));
        filelabel->setGeometry(QRect(530, 280, 131, 16));
        fstatelabel = new QLabel(centralwidget);
        fstatelabel->setObjectName(QStringLiteral("fstatelabel"));
        fstatelabel->setGeometry(QRect(20, 570, 261, 21));
        sendfilebar = new QProgressBar(centralwidget);
        sendfilebar->setObjectName(QStringLiteral("sendfilebar"));
        sendfilebar->setGeometry(QRect(290, 570, 118, 23));
        sendfilebar->setValue(24);
        connectTcp_class->setCentralWidget(centralwidget);
        menubar = new QMenuBar(connectTcp_class);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 23));
        connectTcp_class->setMenuBar(menubar);
        statusbar = new QStatusBar(connectTcp_class);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        connectTcp_class->setStatusBar(statusbar);

        retranslateUi(connectTcp_class);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(connectTcp_class);
    } // setupUi

    void retranslateUi(QMainWindow *connectTcp_class)
    {
        connectTcp_class->setWindowTitle(QApplication::translate("connectTcp_class", "MainWindow", 0));
        label_4->setText(QApplication::translate("connectTcp_class", "Acccept message:", 0));
        label_5->setText(QApplication::translate("connectTcp_class", "Send message:", 0));
        sendBt->setText(QApplication::translate("connectTcp_class", "Send", 0));
        label_8->setText(QApplication::translate("connectTcp_class", "Receive info:", 0));
        groupBox->setTitle(QString());
        sendFileBt->setText(QApplication::translate("connectTcp_class", "Send File", 0));
        sendImgBt->setText(QApplication::translate("connectTcp_class", "Send Image", 0));
        sendMp3Bt->setText(QApplication::translate("connectTcp_class", "Send MP3", 0));
        ipGroup->setTitle(QString());
        label_3->setText(QApplication::translate("connectTcp_class", "state:", 0));
        stateLabel->setText(QApplication::translate("connectTcp_class", "disconnect", 0));
        label->setText(QApplication::translate("connectTcp_class", "Host IP:", 0));
        label_2->setText(QApplication::translate("connectTcp_class", "Port:", 0));
        label_7->setText(QApplication::translate("connectTcp_class", "UserName:", 0));
        linkButton->setText(QApplication::translate("connectTcp_class", "link", 0));
        cancelbt->setText(QApplication::translate("connectTcp_class", "cancel", 0));
        pushButton_5->setText(QApplication::translate("connectTcp_class", "Open", 0));
        label_6->setText(QString());
        serverlabel->setText(QString());
        labelImg->setText(QString());
        filelabel->setText(QString());
        fstatelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class connectTcp_class: public Ui_connectTcp_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTTCP_H
