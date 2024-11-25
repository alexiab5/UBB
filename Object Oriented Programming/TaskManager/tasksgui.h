//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT4_TASKSGUI_H
#define TESTQT4_TASKSGUI_H
#include "repository.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class TasksGUI; }
QT_END_NAMESPACE

class TasksGUI : public QMainWindow {
    Q_OBJECT

public:
    explicit TasksGUI(Repository& repo, QWidget *parent = nullptr);

    ~TasksGUI() override;

private:
    Ui::TasksGUI *ui;
    Repository& repo;
    void populateList();
private slots:
    void showDurationButtonClicked();
};


#endif //TESTQT4_TASKSGUI_H
