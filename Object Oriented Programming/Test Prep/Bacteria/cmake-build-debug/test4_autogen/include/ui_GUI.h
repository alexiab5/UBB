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

class Ui_GUI
{
public:
    QTableView *tableView;
    QComboBox *comboBox;
    QPushButton *addBacteriumButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *speciesLineEdit;
    QLabel *label_3;
    QLineEdit *sizeLineEdit;
    QLabel *label_4;
    QLineEdit *diseasesLineEdit;
    QLabel *label;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLineEdit *addDiseaseLineEdit;
    QPushButton *addDiseaseButton;
    QListWidget *listWidget;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName("GUI");
        GUI->resize(629, 450);
        tableView = new QTableView(GUI);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 90, 311, 191));
        comboBox = new QComboBox(GUI);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(250, 50, 68, 22));
        addBacteriumButton = new QPushButton(GUI);
        addBacteriumButton->setObjectName("addBacteriumButton");
        addBacteriumButton->setGeometry(QRect(260, 320, 75, 24));
        layoutWidget = new QWidget(GUI);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 310, 189, 126));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        speciesLineEdit = new QLineEdit(layoutWidget);
        speciesLineEdit->setObjectName("speciesLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, speciesLineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        sizeLineEdit = new QLineEdit(layoutWidget);
        sizeLineEdit->setObjectName("sizeLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, sizeLineEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        diseasesLineEdit = new QLineEdit(layoutWidget);
        diseasesLineEdit->setObjectName("diseasesLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, diseasesLineEdit);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        layoutWidget1 = new QWidget(GUI);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(390, 320, 215, 26));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        addDiseaseLineEdit = new QLineEdit(layoutWidget1);
        addDiseaseLineEdit->setObjectName("addDiseaseLineEdit");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, addDiseaseLineEdit);

        addDiseaseButton = new QPushButton(layoutWidget1);
        addDiseaseButton->setObjectName("addDiseaseButton");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, addDiseaseButton);

        listWidget = new QListWidget(GUI);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(380, 90, 256, 192));

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        addBacteriumButton->setText(QCoreApplication::translate("GUI", "Add", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Species", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "Size", nullptr));
        label_4->setText(QCoreApplication::translate("GUI", "Diseases", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Name", nullptr));
        addDiseaseButton->setText(QCoreApplication::translate("GUI", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
