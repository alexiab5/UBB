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
#include <QtWidgets/QCheckBox>
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
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *updateSpecialisationLineEdit;
    QPushButton *updateSpecialisationButton;
    QFormLayout *formLayout_2;
    QLineEdit *updateDiagnosisLineEdit;
    QPushButton *updateDiagnosisButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *dateLineEdit;
    QLabel *label_3;
    QLineEdit *diagnosisLineEdit;
    QLabel *label_4;
    QLineEdit *specialisationLineEdit;
    QLabel *CurrentDoctor;
    QLineEdit *doctorLineEdit;
    QPushButton *addButton;
    QCheckBox *checkBox;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(670, 481);
        listWidget = new QListWidget(Window);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 60, 301, 241));
        layoutWidget = new QWidget(Window);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 320, 315, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        updateSpecialisationLineEdit = new QLineEdit(layoutWidget);
        updateSpecialisationLineEdit->setObjectName("updateSpecialisationLineEdit");

        formLayout->setWidget(0, QFormLayout::LabelRole, updateSpecialisationLineEdit);

        updateSpecialisationButton = new QPushButton(layoutWidget);
        updateSpecialisationButton->setObjectName("updateSpecialisationButton");

        formLayout->setWidget(0, QFormLayout::FieldRole, updateSpecialisationButton);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        updateDiagnosisLineEdit = new QLineEdit(layoutWidget);
        updateDiagnosisLineEdit->setObjectName("updateDiagnosisLineEdit");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, updateDiagnosisLineEdit);

        updateDiagnosisButton = new QPushButton(layoutWidget);
        updateDiagnosisButton->setObjectName("updateDiagnosisButton");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, updateDiagnosisButton);


        verticalLayout->addLayout(formLayout_2);

        layoutWidget1 = new QWidget(Window);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(340, 80, 311, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        nameLineEdit = new QLineEdit(layoutWidget1);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        dateLineEdit = new QLineEdit(layoutWidget1);
        dateLineEdit->setObjectName("dateLineEdit");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, dateLineEdit);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_3);

        diagnosisLineEdit = new QLineEdit(layoutWidget1);
        diagnosisLineEdit->setObjectName("diagnosisLineEdit");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, diagnosisLineEdit);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_4);

        specialisationLineEdit = new QLineEdit(layoutWidget1);
        specialisationLineEdit->setObjectName("specialisationLineEdit");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, specialisationLineEdit);

        CurrentDoctor = new QLabel(layoutWidget1);
        CurrentDoctor->setObjectName("CurrentDoctor");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, CurrentDoctor);

        doctorLineEdit = new QLineEdit(layoutWidget1);
        doctorLineEdit->setObjectName("doctorLineEdit");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, doctorLineEdit);


        verticalLayout_2->addLayout(formLayout_3);

        addButton = new QPushButton(layoutWidget1);
        addButton->setObjectName("addButton");

        verticalLayout_2->addWidget(addButton);

        checkBox = new QCheckBox(Window);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(170, 40, 151, 21));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        updateSpecialisationButton->setText(QCoreApplication::translate("Window", "Update Required Specialisation", nullptr));
        updateDiagnosisButton->setText(QCoreApplication::translate("Window", "Update Diagnosis", nullptr));
        label->setText(QCoreApplication::translate("Window", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "Diagnosis", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "Required Specialisation", nullptr));
        CurrentDoctor->setText(QCoreApplication::translate("Window", "Current Doctor", nullptr));
        addButton->setText(QCoreApplication::translate("Window", "Add Pacient", nullptr));
        checkBox->setText(QCoreApplication::translate("Window", "View your pacients only", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
