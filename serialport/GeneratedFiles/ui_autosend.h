/********************************************************************************
** Form generated from reading UI file 'autosend.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOSEND_H
#define UI_AUTOSEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_autosend_ui
{
public:
    QGroupBox *groupBox;
    QPlainTextEdit *autosendtxt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *autoset;

    void setupUi(QWidget *autosend_ui)
    {
        if (autosend_ui->objectName().isEmpty())
            autosend_ui->setObjectName(QStringLiteral("autosend_ui"));
        autosend_ui->resize(407, 306);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(autosend_ui->sizePolicy().hasHeightForWidth());
        autosend_ui->setSizePolicy(sizePolicy);
        autosend_ui->setMinimumSize(QSize(407, 306));
        autosend_ui->setMaximumSize(QSize(407, 306));
        groupBox = new QGroupBox(autosend_ui);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 381, 251));
        autosendtxt = new QPlainTextEdit(groupBox);
        autosendtxt->setObjectName(QStringLiteral("autosendtxt"));
        autosendtxt->setGeometry(QRect(0, 20, 381, 231));
        layoutWidget = new QWidget(autosend_ui);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(24, 20, 248, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(1000);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        autoset = new QPushButton(autosend_ui);
        autoset->setObjectName(QStringLiteral("autoset"));
        autoset->setGeometry(QRect(304, 20, 51, 23));

        retranslateUi(autosend_ui);

        QMetaObject::connectSlotsByName(autosend_ui);
    } // setupUi

    void retranslateUi(QWidget *autosend_ui)
    {
        autosend_ui->setWindowTitle(QApplication::translate("autosend_ui", "Form", 0));
        groupBox->setTitle(QApplication::translate("autosend_ui", "\350\207\252\345\212\250\345\217\221\351\200\201\345\214\272\345\237\237", 0));
        label->setText(QApplication::translate("autosend_ui", "\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232", 0));
        label_2->setText(QApplication::translate("autosend_ui", "\357\274\210ms\357\274\211", 0));
        autoset->setText(QApplication::translate("autosend_ui", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class autosend_ui: public Ui_autosend_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOSEND_H
