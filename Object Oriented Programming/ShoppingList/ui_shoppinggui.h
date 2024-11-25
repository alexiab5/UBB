/********************************************************************************
** Form generated from reading UI file 'shoppinggui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGGUI_H
#define UI_SHOPPINGGUI_H

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

class Ui_shoppinggui
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *shoppingListWidget;
    QPushButton *deteleButton;
    QHBoxLayout *horizontalLayout;
    QLabel *filterLabel;
    QLineEdit *filterLineEdit;
    QPushButton *filterButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *shoppinggui)
    {
        if (shoppinggui->objectName().isEmpty())
            shoppinggui->setObjectName("shoppinggui");
        shoppinggui->resize(523, 416);
        centralwidget = new QWidget(shoppinggui);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        shoppingListWidget = new QListWidget(centralwidget);
        shoppingListWidget->setObjectName("shoppingListWidget");

        verticalLayout->addWidget(shoppingListWidget);

        deteleButton = new QPushButton(centralwidget);
        deteleButton->setObjectName("deteleButton");

        verticalLayout->addWidget(deteleButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        filterLabel = new QLabel(centralwidget);
        filterLabel->setObjectName("filterLabel");

        horizontalLayout->addWidget(filterLabel);

        filterLineEdit = new QLineEdit(centralwidget);
        filterLineEdit->setObjectName("filterLineEdit");

        horizontalLayout->addWidget(filterLineEdit);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");

        horizontalLayout->addWidget(filterButton);


        verticalLayout->addLayout(horizontalLayout);

        shoppinggui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shoppinggui);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 523, 22));
        shoppinggui->setMenuBar(menubar);
        statusbar = new QStatusBar(shoppinggui);
        statusbar->setObjectName("statusbar");
        shoppinggui->setStatusBar(statusbar);

        retranslateUi(shoppinggui);

        QMetaObject::connectSlotsByName(shoppinggui);
    } // setupUi

    void retranslateUi(QMainWindow *shoppinggui)
    {
        shoppinggui->setWindowTitle(QCoreApplication::translate("shoppinggui", "shoppinggui", nullptr));
        deteleButton->setText(QCoreApplication::translate("shoppinggui", "DELETE", nullptr));
        filterLabel->setText(QCoreApplication::translate("shoppinggui", "Filter by category", nullptr));
        filterButton->setText(QCoreApplication::translate("shoppinggui", "FILTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shoppinggui: public Ui_shoppinggui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGGUI_H
