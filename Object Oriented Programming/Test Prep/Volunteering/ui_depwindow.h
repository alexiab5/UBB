/********************************************************************************
** Form generated from reading UI file 'depwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPWINDOW_H
#define UI_DEPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_depWindow
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *depWindow)
    {
        if (depWindow->objectName().isEmpty())
            depWindow->setObjectName("depWindow");
        depWindow->resize(400, 300);
        listWidget = new QListWidget(depWindow);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(80, 50, 256, 192));

        retranslateUi(depWindow);

        QMetaObject::connectSlotsByName(depWindow);
    } // setupUi

    void retranslateUi(QWidget *depWindow)
    {
        depWindow->setWindowTitle(QCoreApplication::translate("depWindow", "depWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class depWindow: public Ui_depWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPWINDOW_H
