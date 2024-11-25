/********************************************************************************
** Form generated from reading UI file 'billsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLSGUI_H
#define UI_BILLSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BillsGUIClass
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *paidCheckBox;
    QListView *listView;
    QLabel *calculateSumTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *enterCompanyLabel;
    QLineEdit *companyInputLineEdit;
    QPushButton *calculateSumButton;
    QLabel *totalSumLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BillsGUIClass)
    {
        if (BillsGUIClass->objectName().isEmpty())
            BillsGUIClass->setObjectName("BillsGUIClass");
        BillsGUIClass->resize(588, 438);
        centralwidget = new QWidget(BillsGUIClass);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        paidCheckBox = new QCheckBox(centralwidget);
        paidCheckBox->setObjectName("paidCheckBox");

        verticalLayout->addWidget(paidCheckBox);

        listView = new QListView(centralwidget);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        calculateSumTitle = new QLabel(centralwidget);
        calculateSumTitle->setObjectName("calculateSumTitle");

        verticalLayout->addWidget(calculateSumTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        enterCompanyLabel = new QLabel(centralwidget);
        enterCompanyLabel->setObjectName("enterCompanyLabel");

        horizontalLayout->addWidget(enterCompanyLabel);

        companyInputLineEdit = new QLineEdit(centralwidget);
        companyInputLineEdit->setObjectName("companyInputLineEdit");

        horizontalLayout->addWidget(companyInputLineEdit);

        calculateSumButton = new QPushButton(centralwidget);
        calculateSumButton->setObjectName("calculateSumButton");

        horizontalLayout->addWidget(calculateSumButton);


        verticalLayout->addLayout(horizontalLayout);

        totalSumLabel = new QLabel(centralwidget);
        totalSumLabel->setObjectName("totalSumLabel");

        verticalLayout->addWidget(totalSumLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        BillsGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BillsGUIClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 588, 22));
        BillsGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(BillsGUIClass);
        statusbar->setObjectName("statusbar");
        BillsGUIClass->setStatusBar(statusbar);

        retranslateUi(BillsGUIClass);

        QMetaObject::connectSlotsByName(BillsGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BillsGUIClass)
    {
        BillsGUIClass->setWindowTitle(QCoreApplication::translate("BillsGUIClass", "BillsGUIClass", nullptr));
        paidCheckBox->setText(QCoreApplication::translate("BillsGUIClass", "Show unpaid bills only", nullptr));
        calculateSumTitle->setText(QCoreApplication::translate("BillsGUIClass", "Calculate sum of unpaid bills for a company", nullptr));
        enterCompanyLabel->setText(QCoreApplication::translate("BillsGUIClass", "Enter the name of the company:", nullptr));
        calculateSumButton->setText(QCoreApplication::translate("BillsGUIClass", "Calculate sum", nullptr));
        totalSumLabel->setText(QCoreApplication::translate("BillsGUIClass", "Total sum:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BillsGUIClass: public Ui_BillsGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLSGUI_H
