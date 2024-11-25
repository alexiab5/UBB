/********************************************************************************
** Form generated from reading UI file 'vegetablesGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETABLESGUI_H
#define UI_VEGETABLESGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VegetablesGUI
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *familyNameListWidget;
    QListWidget *vegetablesListWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *vegetableLineEdit;
    QPushButton *searchButton;
    QLabel *ediblePartsLabel;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VegetablesGUI)
    {
        if (VegetablesGUI->objectName().isEmpty())
            VegetablesGUI->setObjectName("VegetablesGUI");
        VegetablesGUI->resize(627, 390);
        centralwidget = new QWidget(VegetablesGUI);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 60, 520, 194));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        familyNameListWidget = new QListWidget(layoutWidget);
        familyNameListWidget->setObjectName("familyNameListWidget");

        horizontalLayout_2->addWidget(familyNameListWidget);

        vegetablesListWidget = new QListWidget(layoutWidget);
        vegetablesListWidget->setObjectName("vegetablesListWidget");

        horizontalLayout_2->addWidget(vegetablesListWidget);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(180, 270, 217, 72));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        vegetableLineEdit = new QLineEdit(layoutWidget1);
        vegetableLineEdit->setObjectName("vegetableLineEdit");

        horizontalLayout->addWidget(vegetableLineEdit);

        searchButton = new QPushButton(layoutWidget1);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        ediblePartsLabel = new QLabel(layoutWidget1);
        ediblePartsLabel->setObjectName("ediblePartsLabel");

        verticalLayout->addWidget(ediblePartsLabel);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(470, 290, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 0, 131, 16));
        VegetablesGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VegetablesGUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 627, 22));
        VegetablesGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(VegetablesGUI);
        statusbar->setObjectName("statusbar");
        VegetablesGUI->setStatusBar(statusbar);

        retranslateUi(VegetablesGUI);

        QMetaObject::connectSlotsByName(VegetablesGUI);
    } // setupUi

    void retranslateUi(QMainWindow *VegetablesGUI)
    {
        VegetablesGUI->setWindowTitle(QCoreApplication::translate("VegetablesGUI", "VegetablesGUI", nullptr));
        label->setText(QCoreApplication::translate("VegetablesGUI", "Search for a vegetable", nullptr));
        searchButton->setText(QCoreApplication::translate("VegetablesGUI", "SEARCH", nullptr));
        ediblePartsLabel->setText(QCoreApplication::translate("VegetablesGUI", "Edible parts:", nullptr));
        label_2->setText(QCoreApplication::translate("VegetablesGUI", "HAHAHAHA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VegetablesGUI: public Ui_VegetablesGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETABLESGUI_H
