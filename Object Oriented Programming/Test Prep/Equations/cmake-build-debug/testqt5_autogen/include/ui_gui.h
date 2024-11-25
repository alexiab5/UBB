/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
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

class Ui_gui
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *computeBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditB;
    QLabel *label_3;
    QLineEdit *lineEditC;
    QLineEdit *lineEditA;
    QPushButton *addBtn;
    QLabel *solutionsLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(608, 395);
        centralwidget = new QWidget(gui);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(250, 60, 301, 191));
        computeBtn = new QPushButton(centralwidget);
        computeBtn->setObjectName("computeBtn");
        computeBtn->setGeometry(QRect(340, 260, 151, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 90, 191, 109));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditB = new QLineEdit(layoutWidget);
        lineEditB->setObjectName("lineEditB");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditB);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditC = new QLineEdit(layoutWidget);
        lineEditC->setObjectName("lineEditC");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditC);

        lineEditA = new QLineEdit(layoutWidget);
        lineEditA->setObjectName("lineEditA");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditA);


        verticalLayout->addLayout(formLayout);

        addBtn = new QPushButton(layoutWidget);
        addBtn->setObjectName("addBtn");

        verticalLayout->addWidget(addBtn);

        solutionsLabel = new QLabel(centralwidget);
        solutionsLabel->setObjectName("solutionsLabel");
        solutionsLabel->setGeometry(QRect(50, 320, 381, 21));
        gui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gui);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 608, 22));
        gui->setMenuBar(menubar);
        statusbar = new QStatusBar(gui);
        statusbar->setObjectName("statusbar");
        gui->setStatusBar(statusbar);

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        computeBtn->setText(QCoreApplication::translate("gui", "Compute solutions", nullptr));
        label->setText(QCoreApplication::translate("gui", "a", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "b", nullptr));
        label_3->setText(QCoreApplication::translate("gui", "c", nullptr));
        addBtn->setText(QCoreApplication::translate("gui", "ADD", nullptr));
        solutionsLabel->setText(QCoreApplication::translate("gui", "The solutions are:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
