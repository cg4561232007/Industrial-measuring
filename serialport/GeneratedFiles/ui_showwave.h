/********************************************************************************
** Form generated from reading UI file 'showwave.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWAVE_H
#define UI_SHOWWAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showwaveUi
{
public:
    QFrame *line_2;
    QWidget *layoutWidget;
    QVBoxLayout *mainlayout;
    QHBoxLayout *mainhorizonLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ch0_fre;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ch0_vpp;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_14;
    QLabel *ch0_ef;
    QLabel *label_11;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ch1_fre;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QLabel *ch1_vpp;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_16;
    QLabel *ch1_ef;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ch2_fre;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ch2_vpp;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_17;
    QLabel *ch2_ef;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_8;
    QLabel *ch3_fre;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_9;
    QLabel *ch3_vpp;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_18;
    QLabel *ch3_ef;
    QLabel *label_16;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_10;
    QLabel *ch4_fre;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_11;
    QLabel *ch4_vpp;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_19;
    QLabel *ch4_ef;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_16;
    QListWidget *listwd;
    QStackedWidget *stackedwd;
    QWidget *page;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *showbt;
    QPushButton *stopbt;
    QPushButton *saveEffbt;
    QPushButton *savebt;
    QPushButton *saveasbt;
    QPushButton *showgrid;
    QPushButton *snapbt;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_17;
    QSpacerItem *verticalSpacer_6;
    QPushButton *retbt;
    QWidget *page_2;
    QGroupBox *algroribox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *avgfilterbt;
    QPushButton *slidefilterbt;
    QPushButton *midfilterbt;
    QPushButton *weightfilterbt;
    QWidget *page_5;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_4;
    QSpinBox *gridNum;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *interalPixelsSpin;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *penwidth_spin;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *otherPenSpin;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *showwaveUi)
    {
        if (showwaveUi->objectName().isEmpty())
            showwaveUi->setObjectName(QStringLiteral("showwaveUi"));
        showwaveUi->setEnabled(true);
        showwaveUi->resize(1315, 759);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showwaveUi->sizePolicy().hasHeightForWidth());
        showwaveUi->setSizePolicy(sizePolicy);
        showwaveUi->setMinimumSize(QSize(1315, 759));
        showwaveUi->setMaximumSize(QSize(1315, 759));
        line_2 = new QFrame(showwaveUi);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(630, 0, 20, 721));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(showwaveUi);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 34, 1291, 708));
        mainlayout = new QVBoxLayout(layoutWidget);
        mainlayout->setObjectName(QStringLiteral("mainlayout"));
        mainlayout->setContentsMargins(0, 0, 0, 0);
        mainhorizonLayout = new QHBoxLayout();
        mainhorizonLayout->setObjectName(QStringLiteral("mainhorizonLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_8->addWidget(label_6);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);

        verticalLayout_2->addWidget(label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ch0_fre = new QLabel(groupBox_3);
        ch0_fre->setObjectName(QStringLiteral("ch0_fre"));

        horizontalLayout_2->addWidget(ch0_fre);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ch0_vpp = new QLabel(groupBox_3);
        ch0_vpp->setObjectName(QStringLiteral("ch0_vpp"));

        horizontalLayout_3->addWidget(ch0_vpp);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        ch0_ef = new QLabel(groupBox_3);
        ch0_ef->setObjectName(QStringLiteral("ch0_ef"));

        horizontalLayout_14->addWidget(ch0_ef);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_14->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_14);


        verticalLayout_8->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        verticalLayout_4->addWidget(label_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ch1_fre = new QLabel(groupBox_4);
        ch1_fre->setObjectName(QStringLiteral("ch1_fre"));

        horizontalLayout_4->addWidget(ch1_fre);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ch1_vpp = new QLabel(groupBox_4);
        ch1_vpp->setObjectName(QStringLiteral("ch1_vpp"));

        horizontalLayout_5->addWidget(ch1_vpp);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_5->addWidget(label_17);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        ch1_ef = new QLabel(groupBox_4);
        ch1_ef->setObjectName(QStringLiteral("ch1_ef"));

        horizontalLayout_16->addWidget(ch1_ef);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_16->addWidget(label_12);


        verticalLayout_4->addLayout(horizontalLayout_16);


        verticalLayout_8->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        verticalLayout_5->addWidget(label_20);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ch2_fre = new QLabel(groupBox_5);
        ch2_fre->setObjectName(QStringLiteral("ch2_fre"));

        horizontalLayout_6->addWidget(ch2_fre);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_6->addWidget(label_19);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ch2_vpp = new QLabel(groupBox_5);
        ch2_vpp->setObjectName(QStringLiteral("ch2_vpp"));

        horizontalLayout_7->addWidget(ch2_vpp);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_7->addWidget(label_22);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        ch2_ef = new QLabel(groupBox_5);
        ch2_ef->setObjectName(QStringLiteral("ch2_ef"));

        horizontalLayout_17->addWidget(ch2_ef);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_17->addWidget(label_13);


        verticalLayout_5->addLayout(horizontalLayout_17);


        verticalLayout_8->addWidget(groupBox_5);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);

        verticalLayout_6->addWidget(label_23);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ch3_fre = new QLabel(groupBox_6);
        ch3_fre->setObjectName(QStringLiteral("ch3_fre"));

        horizontalLayout_8->addWidget(ch3_fre);

        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_8->addWidget(label_25);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ch3_vpp = new QLabel(groupBox_6);
        ch3_vpp->setObjectName(QStringLiteral("ch3_vpp"));

        horizontalLayout_9->addWidget(ch3_vpp);

        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_9->addWidget(label_27);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        ch3_ef = new QLabel(groupBox_6);
        ch3_ef->setObjectName(QStringLiteral("ch3_ef"));

        horizontalLayout_18->addWidget(ch3_ef);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_18->addWidget(label_16);


        verticalLayout_6->addLayout(horizontalLayout_18);


        verticalLayout_8->addWidget(groupBox_6);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);

        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout_7 = new QVBoxLayout(groupBox_7);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);

        verticalLayout_7->addWidget(label_28);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        ch4_fre = new QLabel(groupBox_7);
        ch4_fre->setObjectName(QStringLiteral("ch4_fre"));

        horizontalLayout_10->addWidget(ch4_fre);

        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QStringLiteral("label_30"));

        horizontalLayout_10->addWidget(label_30);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        ch4_vpp = new QLabel(groupBox_7);
        ch4_vpp->setObjectName(QStringLiteral("ch4_vpp"));

        horizontalLayout_11->addWidget(ch4_vpp);

        label_32 = new QLabel(groupBox_7);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_11->addWidget(label_32);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        ch4_ef = new QLabel(groupBox_7);
        ch4_ef->setObjectName(QStringLiteral("ch4_ef"));

        horizontalLayout_19->addWidget(ch4_ef);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_19->addWidget(label_18);


        verticalLayout_7->addLayout(horizontalLayout_19);


        verticalLayout_8->addWidget(groupBox_7);


        mainhorizonLayout->addLayout(verticalLayout_8);

        horizontalSpacer_5 = new QSpacerItem(528, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mainhorizonLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(558, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mainhorizonLayout->addItem(horizontalSpacer_6);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        listwd = new QListWidget(layoutWidget);
        listwd->setObjectName(QStringLiteral("listwd"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listwd->sizePolicy().hasHeightForWidth());
        listwd->setSizePolicy(sizePolicy1);
        listwd->setMinimumSize(QSize(91, 131));
        listwd->setMaximumSize(QSize(91, 131));
        listwd->setAutoFillBackground(true);
        listwd->setAutoScroll(true);
        listwd->setProperty("isWrapping", QVariant(false));
        listwd->setResizeMode(QListView::Fixed);
        listwd->setSpacing(1);
        listwd->setViewMode(QListView::ListMode);
        listwd->setSelectionRectVisible(false);

        verticalLayout_16->addWidget(listwd);

        stackedwd = new QStackedWidget(layoutWidget);
        stackedwd->setObjectName(QStringLiteral("stackedwd"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedwd->sizePolicy().hasHeightForWidth());
        stackedwd->setSizePolicy(sizePolicy2);
        stackedwd->setMinimumSize(QSize(101, 293));
        stackedwd->setMaximumSize(QSize(101, 16777215));
        stackedwd->setFrameShadow(QFrame::Raised);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 20, 95, 271));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        showbt = new QPushButton(groupBox);
        showbt->setObjectName(QStringLiteral("showbt"));

        verticalLayout->addWidget(showbt);

        stopbt = new QPushButton(groupBox);
        stopbt->setObjectName(QStringLiteral("stopbt"));

        verticalLayout->addWidget(stopbt);

        saveEffbt = new QPushButton(groupBox);
        saveEffbt->setObjectName(QStringLiteral("saveEffbt"));

        verticalLayout->addWidget(saveEffbt);

        savebt = new QPushButton(groupBox);
        savebt->setObjectName(QStringLiteral("savebt"));

        verticalLayout->addWidget(savebt);

        saveasbt = new QPushButton(groupBox);
        saveasbt->setObjectName(QStringLiteral("saveasbt"));

        verticalLayout->addWidget(saveasbt);

        showgrid = new QPushButton(groupBox);
        showgrid->setObjectName(QStringLiteral("showgrid"));

        verticalLayout->addWidget(showgrid);

        snapbt = new QPushButton(groupBox);
        snapbt->setObjectName(QStringLiteral("snapbt"));

        verticalLayout->addWidget(snapbt);

        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 330, 77, 119));
        verticalLayout_17 = new QVBoxLayout(layoutWidget1);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_6);

        retbt = new QPushButton(layoutWidget1);
        retbt->setObjectName(QStringLiteral("retbt"));

        verticalLayout_17->addWidget(retbt);

        stackedwd->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        algroribox = new QGroupBox(page_2);
        algroribox->setObjectName(QStringLiteral("algroribox"));
        algroribox->setEnabled(true);
        algroribox->setGeometry(QRect(10, 20, 95, 168));
        algroribox->setCheckable(false);
        algroribox->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(algroribox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        avgfilterbt = new QPushButton(algroribox);
        avgfilterbt->setObjectName(QStringLiteral("avgfilterbt"));

        verticalLayout_3->addWidget(avgfilterbt);

        slidefilterbt = new QPushButton(algroribox);
        slidefilterbt->setObjectName(QStringLiteral("slidefilterbt"));

        verticalLayout_3->addWidget(slidefilterbt);

        midfilterbt = new QPushButton(algroribox);
        midfilterbt->setObjectName(QStringLiteral("midfilterbt"));

        verticalLayout_3->addWidget(midfilterbt);

        weightfilterbt = new QPushButton(algroribox);
        weightfilterbt->setObjectName(QStringLiteral("weightfilterbt"));

        verticalLayout_3->addWidget(weightfilterbt);

        stackedwd->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedwd->addWidget(page_5);

        verticalLayout_16->addWidget(stackedwd);


        mainhorizonLayout->addLayout(verticalLayout_16);


        mainlayout->addLayout(mainhorizonLayout);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_7 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_13->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_12->addWidget(label_4);

        gridNum = new QSpinBox(layoutWidget);
        gridNum->setObjectName(QStringLiteral("gridNum"));

        horizontalLayout_12->addWidget(gridNum);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_12->addWidget(label_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_12->addWidget(label_3);

        interalPixelsSpin = new QSpinBox(layoutWidget);
        interalPixelsSpin->setObjectName(QStringLiteral("interalPixelsSpin"));

        horizontalLayout_12->addWidget(interalPixelsSpin);


        horizontalLayout_13->addLayout(horizontalLayout_12);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        penwidth_spin = new QSpinBox(layoutWidget);
        penwidth_spin->setObjectName(QStringLiteral("penwidth_spin"));

        horizontalLayout->addWidget(penwidth_spin);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        otherPenSpin = new QSpinBox(layoutWidget);
        otherPenSpin->setObjectName(QStringLiteral("otherPenSpin"));

        horizontalLayout->addWidget(otherPenSpin);


        horizontalLayout_13->addLayout(horizontalLayout);


        horizontalLayout_15->addLayout(horizontalLayout_13);

        horizontalSpacer_8 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_8);


        mainlayout->addLayout(horizontalLayout_15);


        retranslateUi(showwaveUi);

        listwd->setCurrentRow(-1);
        stackedwd->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(showwaveUi);
    } // setupUi

    void retranslateUi(QWidget *showwaveUi)
    {
        showwaveUi->setWindowTitle(QApplication::translate("showwaveUi", "Form", 0));
        label_6->setText(QApplication::translate("showwaveUi", "x\350\275\264/(10*\345\203\217\347\264\240)", 0));
        groupBox_3->setTitle(QApplication::translate("showwaveUi", "\347\273\225\351\230\2731", 0));
        label_8->setText(QApplication::translate("showwaveUi", "\351\200\232\351\201\2231", 0));
        ch0_fre->setText(QApplication::translate("showwaveUi", "0", 0));
        label_9->setText(QApplication::translate("showwaveUi", "KHZ", 0));
        ch0_vpp->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_10->setText(QApplication::translate("showwaveUi", "VPP", 0));
        ch0_ef->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_11->setText(QApplication::translate("showwaveUi", "VEF", 0));
        groupBox_4->setTitle(QApplication::translate("showwaveUi", "\347\273\225\351\230\2732", 0));
        label_15->setText(QApplication::translate("showwaveUi", "\351\200\232\351\201\2232", 0));
        ch1_fre->setText(QApplication::translate("showwaveUi", "0", 0));
        label_14->setText(QApplication::translate("showwaveUi", "KHZ", 0));
        ch1_vpp->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_17->setText(QApplication::translate("showwaveUi", "VPP", 0));
        ch1_ef->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_12->setText(QApplication::translate("showwaveUi", "VEF", 0));
        groupBox_5->setTitle(QApplication::translate("showwaveUi", "\347\273\225\351\230\2733", 0));
        label_20->setText(QApplication::translate("showwaveUi", "\351\200\232\351\201\2233", 0));
        ch2_fre->setText(QApplication::translate("showwaveUi", "0", 0));
        label_19->setText(QApplication::translate("showwaveUi", "KHZ", 0));
        ch2_vpp->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_22->setText(QApplication::translate("showwaveUi", "VPP", 0));
        ch2_ef->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_13->setText(QApplication::translate("showwaveUi", "VEF", 0));
        groupBox_6->setTitle(QApplication::translate("showwaveUi", "\347\273\225\351\230\2734", 0));
        label_23->setText(QApplication::translate("showwaveUi", "\351\200\232\351\201\2234", 0));
        ch3_fre->setText(QApplication::translate("showwaveUi", "0", 0));
        label_25->setText(QApplication::translate("showwaveUi", "KHZ", 0));
        ch3_vpp->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_27->setText(QApplication::translate("showwaveUi", "VPP", 0));
        ch3_ef->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_16->setText(QApplication::translate("showwaveUi", "VEF", 0));
        groupBox_7->setTitle(QApplication::translate("showwaveUi", "\347\273\225\351\230\2735", 0));
        label_28->setText(QApplication::translate("showwaveUi", "\351\200\232\351\201\2235", 0));
        ch4_fre->setText(QApplication::translate("showwaveUi", "0", 0));
        label_30->setText(QApplication::translate("showwaveUi", "KHZ", 0));
        ch4_vpp->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_32->setText(QApplication::translate("showwaveUi", "VPP", 0));
        ch4_ef->setText(QApplication::translate("showwaveUi", "0.0", 0));
        label_18->setText(QApplication::translate("showwaveUi", "VEF", 0));
        groupBox->setTitle(QApplication::translate("showwaveUi", "\346\263\242\345\275\242\350\256\276\347\275\256", 0));
        showbt->setText(QApplication::translate("showwaveUi", "\346\255\243\345\270\270\346\230\276\347\244\272", 0));
        stopbt->setText(QApplication::translate("showwaveUi", "\346\232\202\345\201\234\346\230\276\347\244\272", 0));
        saveEffbt->setText(QApplication::translate("showwaveUi", "\346\234\211\346\225\210\345\200\274", 0));
        savebt->setText(QApplication::translate("showwaveUi", "\344\277\235\345\255\230", 0));
        saveasbt->setText(QApplication::translate("showwaveUi", "\345\217\246\345\255\230\344\270\272", 0));
        showgrid->setText(QApplication::translate("showwaveUi", "\351\232\220\350\227\217\347\275\221\346\240\274", 0));
        snapbt->setText(QApplication::translate("showwaveUi", "\346\210\252\345\233\276", 0));
        retbt->setText(QApplication::translate("showwaveUi", "\350\277\224\345\233\236", 0));
        algroribox->setTitle(QApplication::translate("showwaveUi", "\347\256\227\346\263\225", 0));
        avgfilterbt->setText(QApplication::translate("showwaveUi", "\345\235\207\345\200\274\346\273\244\346\263\242", 0));
        slidefilterbt->setText(QApplication::translate("showwaveUi", "\346\273\221\345\212\250\345\235\207\345\200\274", 0));
        midfilterbt->setText(QApplication::translate("showwaveUi", "\344\270\255\344\275\215\345\200\274\345\235\207\345\200\274", 0));
        weightfilterbt->setText(QApplication::translate("showwaveUi", "\345\212\240\346\235\203\345\235\207\345\200\274", 0));
        label_7->setText(QApplication::translate("showwaveUi", "y\350\275\264/(10*\345\203\217\347\264\240)", 0));
        label_4->setText(QApplication::translate("showwaveUi", "\345\235\220\346\240\207\347\262\276\345\272\246\357\274\232", 0));
        label_5->setText(QApplication::translate("showwaveUi", "\345\203\217\347\264\240\357\274\232", 0));
        label_3->setText(QApplication::translate("showwaveUi", "\346\257\217N\344\270\252\345\203\217\347\264\240\346\230\276\347\244\272\344\270\200\344\270\252\347\202\271\357\274\232", 0));
        label->setText(QApplication::translate("showwaveUi", "\350\256\276\347\275\256\346\233\262\347\272\277\345\256\275\345\272\246", 0));
        label_2->setText(QApplication::translate("showwaveUi", "\350\256\276\347\275\256\346\273\244\346\263\242\346\233\262\347\272\277\345\256\275\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class showwaveUi: public Ui_showwaveUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWAVE_H
