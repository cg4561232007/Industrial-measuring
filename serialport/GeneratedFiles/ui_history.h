/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLabel *label_10;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_18;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_21;
    QLabel *label_22;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_24;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_26;
    QLabel *label_27;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_29;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_31;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineYear;
    QLabel *label_3;
    QLineEdit *lineMonth;
    QLabel *label_4;
    QLineEdit *lineDay;
    QLabel *label_5;
    QLineEdit *lineHour;
    QLabel *label_7;
    QLineEdit *lineMinute;
    QLabel *label_33;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QPushButton *snapbt;
    QSpacerItem *verticalSpacer_6;
    QPushButton *stopbt;
    QSpacerItem *verticalSpacer_5;
    QPushButton *retbt;

    void setupUi(QWidget *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QStringLiteral("history"));
        history->resize(1135, 728);
        history->setMinimumSize(QSize(1111, 728));
        history->setMaximumSize(QSize(1135, 728));
        layoutWidget = new QWidget(history);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 10, 1091, 690));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_15->addWidget(label_6);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_9->addLayout(verticalLayout_4);


        verticalLayout_14->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_10 = new QVBoxLayout(groupBox_4);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        verticalLayout_5->addWidget(label_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_5->addWidget(label_16);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_5->addWidget(label_17);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_10->addLayout(verticalLayout_5);


        verticalLayout_14->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_2);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_11 = new QVBoxLayout(groupBox_5);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        verticalLayout_6->addWidget(label_20);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_6->addWidget(label_18);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_6->addWidget(label_19);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_7->addWidget(label_21);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_7->addWidget(label_22);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_11->addLayout(verticalLayout_6);


        verticalLayout_14->addWidget(groupBox_5);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_3);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_12 = new QVBoxLayout(groupBox_6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);

        verticalLayout_7->addWidget(label_23);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_8->addWidget(label_24);

        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_8->addWidget(label_25);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_9->addWidget(label_26);

        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_9->addWidget(label_27);


        verticalLayout_7->addLayout(horizontalLayout_9);


        verticalLayout_12->addLayout(verticalLayout_7);


        verticalLayout_14->addWidget(groupBox_6);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_4);

        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout_13 = new QVBoxLayout(groupBox_7);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);

        verticalLayout_8->addWidget(label_28);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_29 = new QLabel(groupBox_7);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_10->addWidget(label_29);

        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QStringLiteral("label_30"));

        horizontalLayout_10->addWidget(label_30);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_31 = new QLabel(groupBox_7);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_11->addWidget(label_31);

        label_32 = new QLabel(groupBox_7);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_11->addWidget(label_32);


        verticalLayout_8->addLayout(horizontalLayout_11);


        verticalLayout_13->addLayout(verticalLayout_8);


        verticalLayout_14->addWidget(groupBox_7);


        verticalLayout_15->addLayout(verticalLayout_14);


        horizontalLayout_13->addLayout(verticalLayout_15);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(188, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineYear = new QLineEdit(layoutWidget);
        lineYear->setObjectName(QStringLiteral("lineYear"));

        horizontalLayout->addWidget(lineYear);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        lineMonth = new QLineEdit(layoutWidget);
        lineMonth->setObjectName(QStringLiteral("lineMonth"));

        horizontalLayout->addWidget(lineMonth);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);

        lineDay = new QLineEdit(layoutWidget);
        lineDay->setObjectName(QStringLiteral("lineDay"));

        horizontalLayout->addWidget(lineDay);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        lineHour = new QLineEdit(layoutWidget);
        lineHour->setObjectName(QStringLiteral("lineHour"));

        horizontalLayout->addWidget(lineHour);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        lineMinute = new QLineEdit(layoutWidget);
        lineMinute->setObjectName(QStringLiteral("lineMinute"));

        horizontalLayout->addWidget(lineMinute);

        label_33 = new QLabel(layoutWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font1);

        horizontalLayout->addWidget(label_33);

        horizontalSpacer_2 = new QSpacerItem(168, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_5 = new QSpacerItem(898, 648, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_5);


        horizontalLayout_12->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        snapbt = new QPushButton(layoutWidget);
        snapbt->setObjectName(QStringLiteral("snapbt"));

        verticalLayout->addWidget(snapbt);

        verticalSpacer_6 = new QSpacerItem(20, 208, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        stopbt = new QPushButton(layoutWidget);
        stopbt->setObjectName(QStringLiteral("stopbt"));

        verticalLayout->addWidget(stopbt);

        verticalSpacer_5 = new QSpacerItem(20, 208, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        retbt = new QPushButton(layoutWidget);
        retbt->setObjectName(QStringLiteral("retbt"));

        verticalLayout->addWidget(retbt);


        horizontalLayout_12->addLayout(verticalLayout);


        horizontalLayout_13->addLayout(horizontalLayout_12);


        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QWidget *history)
    {
        history->setWindowTitle(QApplication::translate("history", "Form", 0));
        label_6->setText(QApplication::translate("history", "x\350\275\264/(10*\345\203\217\347\264\240)", 0));
        groupBox_3->setTitle(QApplication::translate("history", "\347\273\225\351\230\2731", 0));
        label_8->setText(QApplication::translate("history", "\351\200\232\351\201\2231", 0));
        label_11->setText(QApplication::translate("history", "0", 0));
        label_9->setText(QApplication::translate("history", "KHZ", 0));
        label_12->setText(QApplication::translate("history", "0.0", 0));
        label_10->setText(QApplication::translate("history", "VPP", 0));
        groupBox_4->setTitle(QApplication::translate("history", "\347\273\225\351\230\2732", 0));
        label_15->setText(QApplication::translate("history", "\351\200\232\351\201\2232", 0));
        label_13->setText(QApplication::translate("history", "0", 0));
        label_14->setText(QApplication::translate("history", "KHZ", 0));
        label_16->setText(QApplication::translate("history", "0.0", 0));
        label_17->setText(QApplication::translate("history", "VPP", 0));
        groupBox_5->setTitle(QApplication::translate("history", "\347\273\225\351\230\2733", 0));
        label_20->setText(QApplication::translate("history", "\351\200\232\351\201\2233", 0));
        label_18->setText(QApplication::translate("history", "0", 0));
        label_19->setText(QApplication::translate("history", "KHZ", 0));
        label_21->setText(QApplication::translate("history", "0.0", 0));
        label_22->setText(QApplication::translate("history", "VPP", 0));
        groupBox_6->setTitle(QApplication::translate("history", "\347\273\225\351\230\2734", 0));
        label_23->setText(QApplication::translate("history", "\351\200\232\351\201\2234", 0));
        label_24->setText(QApplication::translate("history", "0", 0));
        label_25->setText(QApplication::translate("history", "KHZ", 0));
        label_26->setText(QApplication::translate("history", "0.0", 0));
        label_27->setText(QApplication::translate("history", "VPP", 0));
        groupBox_7->setTitle(QApplication::translate("history", "\347\273\225\351\230\2735", 0));
        label_28->setText(QApplication::translate("history", "\351\200\232\351\201\2235", 0));
        label_29->setText(QApplication::translate("history", "0", 0));
        label_30->setText(QApplication::translate("history", "KHZ", 0));
        label_31->setText(QApplication::translate("history", "0.0", 0));
        label_32->setText(QApplication::translate("history", "VPP", 0));
        label->setText(QApplication::translate("history", "\350\257\267\350\276\223\345\205\245\346\265\213\351\207\217\346\227\266\351\227\264\357\274\232", 0));
        label_3->setText(QApplication::translate("history", "\345\271\264", 0));
        label_4->setText(QApplication::translate("history", "\346\234\210", 0));
        lineDay->setText(QString());
        label_5->setText(QApplication::translate("history", "\346\227\245", 0));
        label_7->setText(QApplication::translate("history", "\346\227\266", 0));
        label_33->setText(QApplication::translate("history", "\345\210\206", 0));
        snapbt->setText(QApplication::translate("history", "\346\210\252\345\233\276", 0));
        stopbt->setText(QApplication::translate("history", "\345\201\234\346\255\242", 0));
        retbt->setText(QApplication::translate("history", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
