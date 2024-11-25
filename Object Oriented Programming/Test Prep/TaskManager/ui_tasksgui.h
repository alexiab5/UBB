/********************************************************************************
** Form generated from reading UI file 'tasksgui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSGUI_H
#define UI_TASKSGUI_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksGUI
{
public:
    QWidget *centralwidget;
    QListWidget *tasksListWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *inputPriorityLineEdit;
    QPushButton *showDurationButton;
    QLabel *totalDurationLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TasksGUI)
    {
        if (TasksGUI->objectName().isEmpty())
            TasksGUI->setObjectName("TasksGUI");
        TasksGUI->resize(461, 349);
        centralwidget = new QWidget(TasksGUI);
        centralwidget->setObjectName("centralwidget");
        tasksListWidget = new QListWidget(centralwidget);
        tasksListWidget->setObjectName("tasksListWidget");
        tasksListWidget->setGeometry(QRect(80, 40, 311, 181));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 240, 311, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        inputPriorityLineEdit = new QLineEdit(layoutWidget);
        inputPriorityLineEdit->setObjectName("inputPriorityLineEdit");

        horizontalLayout->addWidget(inputPriorityLineEdit);

        showDurationButton = new QPushButton(layoutWidget);
        showDurationButton->setObjectName("showDurationButton");

        horizontalLayout->addWidget(showDurationButton);

        totalDurationLabel = new QLabel(centralwidget);
        totalDurationLabel->setObjectName("totalDurationLabel");
        totalDurationLabel->setGeometry(QRect(160, 270, 161, 16));
        TasksGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TasksGUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 461, 22));
        TasksGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TasksGUI);
        statusbar->setObjectName("statusbar");
        TasksGUI->setStatusBar(statusbar);

        retranslateUi(TasksGUI);

        QMetaObject::connectSlotsByName(TasksGUI);
    } // setupUi

    void retranslateUi(QMainWindow *TasksGUI)
    {
        TasksGUI->setWindowTitle(QCoreApplication::translate("TasksGUI", "TasksGUI", nullptr));
        label->setText(QCoreApplication::translate("TasksGUI", "Input the priority of the task:", nullptr));
        showDurationButton->setText(QCoreApplication::translate("TasksGUI", "Show Duration", nullptr));
        totalDurationLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TasksGUI: public Ui_TasksGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSGUI_H
