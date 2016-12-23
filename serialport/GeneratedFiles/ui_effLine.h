/********************************************************************************
** Form generated from reading UI file 'effLine.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFLINE_H
#define UI_EFFLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_effLine
{
public:
    QPushButton *retbt;
    QPushButton *settingbt;
    QPushButton *snapbt;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QTableWidget *tb_Param;
    QTableWidget *tb_datas;

    void setupUi(QWidget *effLine)
    {
        if (effLine->objectName().isEmpty())
            effLine->setObjectName(QStringLiteral("effLine"));
        effLine->resize(1277, 850);
        retbt = new QPushButton(effLine);
        retbt->setObjectName(QStringLiteral("retbt"));
        retbt->setGeometry(QRect(974, 600, 61, 23));
        settingbt = new QPushButton(effLine);
        settingbt->setObjectName(QStringLiteral("settingbt"));
        settingbt->setGeometry(QRect(981, 20, 75, 23));
        snapbt = new QPushButton(effLine);
        snapbt->setObjectName(QStringLiteral("snapbt"));
        snapbt->setGeometry(QRect(981, 50, 75, 23));
        label = new QLabel(effLine);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 610, 111, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(effLine);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 91, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setWordWrap(false);
        line = new QFrame(effLine);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(180, 20, 20, 811));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(effLine);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 10, 1591, 16));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(effLine);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(-7, 20, 20, 811));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(effLine);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 825, 1601, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(effLine);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(0, 820, 1601, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        tb_Param = new QTableWidget(effLine);
        tb_Param->setObjectName(QStringLiteral("tb_Param"));
        tb_Param->setGeometry(QRect(13, 24, 171, 211));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_Param->sizePolicy().hasHeightForWidth());
        tb_Param->setSizePolicy(sizePolicy1);
        tb_Param->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(9);
        tb_Param->setFont(font1);
        tb_Param->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tb_datas = new QTableWidget(effLine);
        tb_datas->setObjectName(QStringLiteral("tb_datas"));
        tb_datas->setGeometry(QRect(13, 242, 171, 581));
        sizePolicy1.setHeightForWidth(tb_datas->sizePolicy().hasHeightForWidth());
        tb_datas->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(8);
        tb_datas->setFont(font2);
        tb_datas->setTabKeyNavigation(true);
        tb_datas->setDragEnabled(true);

        retranslateUi(effLine);

        QMetaObject::connectSlotsByName(effLine);
    } // setupUi

    void retranslateUi(QWidget *effLine)
    {
        effLine->setWindowTitle(QApplication::translate("effLine", "Form", 0));
        retbt->setText(QApplication::translate("effLine", "\350\277\224\345\233\236", 0));
        settingbt->setText(QApplication::translate("effLine", "\350\256\276\347\275\256", 0));
        snapbt->setText(QApplication::translate("effLine", "\346\210\252\345\233\276", 0));
        label->setText(QApplication::translate("effLine", "Frenquency(KHZ)", 0));
        label_2->setText(QApplication::translate("effLine", "Amplitude(dB)", 0));
    } // retranslateUi

};

namespace Ui {
    class effLine: public Ui_effLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFLINE_H
