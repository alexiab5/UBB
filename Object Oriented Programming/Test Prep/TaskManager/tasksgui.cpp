//
// Created by alexia on 26.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TasksGUI.h" resolved

#include "tasksgui.h"
#include "ui_TasksGUI.h"
#include <sstream>
#include <QMessageBox>

TasksGUI::TasksGUI(Repository& _repo, QWidget *parent) :
        repo(_repo), ui(new Ui::TasksGUI) {
    ui->setupUi(this);
    this->populateList();
    connect(this->ui->showDurationButton, &QPushButton::clicked, this, &TasksGUI::showDurationButtonClicked);
}

TasksGUI::~TasksGUI() {
    delete ui;
}

void TasksGUI::populateList() {
    auto v = this->repo.getAll();
    ui->tasksListWidget->clear();
    for(const auto& s : v) {
        std::stringstream ss;
        ss << s.getDescription() << "|" << s.getDuration();
        QListWidgetItem *it = new QListWidgetItem{QString::fromStdString(ss.str())};
        QFont f;
        if (s.getPriority() == 1) {
            f = QFont("Arial", 10, QFont::Bold, false);
            it->setFont(f);
        }
        else{
            f = QFont("Arial", 10, -1, false);
            it->setBackground(QBrush("cyan"));
        }
        it->setFont(f);
        ui->tasksListWidget->addItem(it);
    }
}

void TasksGUI::showDurationButtonClicked() {
    std::string priority = ui->inputPriorityLineEdit->text().toStdString();
    int pr;
    try{
        pr = stoi(priority);
    }
    catch(...){
        ui->totalDurationLabel->setText("");
        QMessageBox msg;
        msg.setText("Invalid priority");
        msg.exec();
        return;
    }
    int total = this->repo.calculateDurationForTasks(pr);
    ui->totalDurationLabel->setText(QString::fromStdString("Total duration of tasks: " + std::to_string(total)));
}
