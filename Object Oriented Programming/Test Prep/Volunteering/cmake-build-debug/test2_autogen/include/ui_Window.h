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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QListWidget *volunteersListWidget;
    QLabel *descriptionLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *emailLineEdit;
    QLabel *label_3;
    QLineEdit *interestsLineEdit;
    QLabel *label;
    QPushButton *addButton;
    QListWidget *unassignedListWidget;
    QPushButton *assignButton;
    QLabel *label_4;
    QPushButton *top3Button;
    QPushButton *showAllButton;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(739, 603);
        volunteersListWidget = new QListWidget(Window);
        volunteersListWidget->setObjectName("volunteersListWidget");
        volunteersListWidget->setGeometry(QRect(20, 50, 331, 221));
        descriptionLabel = new QLabel(Window);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(280, 10, 281, 31));
        layoutWidget = new QWidget(Window);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(420, 70, 241, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        emailLineEdit = new QLineEdit(layoutWidget);
        emailLineEdit->setObjectName("emailLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, emailLineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        interestsLineEdit = new QLineEdit(layoutWidget);
        interestsLineEdit->setObjectName("interestsLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, interestsLineEdit);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        unassignedListWidget = new QListWidget(Window);
        unassignedListWidget->setObjectName("unassignedListWidget");
        unassignedListWidget->setGeometry(QRect(20, 320, 331, 221));
        assignButton = new QPushButton(Window);
        assignButton->setObjectName("assignButton");
        assignButton->setGeometry(QRect(480, 370, 161, 31));
        label_4 = new QLabel(Window);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 290, 171, 16));
        top3Button = new QPushButton(Window);
        top3Button->setObjectName("top3Button");
        top3Button->setGeometry(QRect(510, 420, 71, 21));
        showAllButton = new QPushButton(Window);
        showAllButton->setObjectName("showAllButton");
        showAllButton->setGeometry(QRect(510, 450, 71, 21));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("Window", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "Email", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "Interests", nullptr));
        label->setText(QCoreApplication::translate("Window", "Name", nullptr));
        addButton->setText(QCoreApplication::translate("Window", "Add", nullptr));
        assignButton->setText(QCoreApplication::translate("Window", "Assign Department", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "Unassigned Volunteers", nullptr));
        top3Button->setText(QCoreApplication::translate("Window", "TOP 3", nullptr));
        showAllButton->setText(QCoreApplication::translate("Window", "Show all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
