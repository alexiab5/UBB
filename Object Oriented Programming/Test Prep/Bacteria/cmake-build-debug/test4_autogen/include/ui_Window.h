/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QComboBox *comboBox;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QTableView *bacteriaTableView;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(754, 518);
        comboBox = new QComboBox(Window);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(250, 80, 68, 22));
        listWidget = new QListWidget(Window);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(380, 110, 256, 192));
        pushButton = new QPushButton(Window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 430, 75, 24));
        lineEdit_5 = new QLineEdit(Window);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(410, 340, 113, 21));
        pushButton_2 = new QPushButton(Window);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 340, 75, 24));
        layoutWidget = new QWidget(Window);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 310, 189, 104));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        bacteriaTableView = new QTableView(Window);
        bacteriaTableView->setObjectName("bacteriaTableView");
        bacteriaTableView->setGeometry(QRect(50, 110, 256, 192));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        pushButton->setText(QCoreApplication::translate("Window", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Window", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Window", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
