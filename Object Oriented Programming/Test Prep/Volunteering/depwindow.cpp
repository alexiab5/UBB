//
// Created by alexia on 24.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_depWindow.h" resolved

#include "depwindow.h"
#include "ui_depWindow.h"


depWindow::depWindow(Controller& controller, QWidget *parent) :
        QWidget(parent), ui(new Ui::depWindow), controller(controller) {
    ui->setupUi(this);
    controller.addObserver(this);
    this->populateList();
}

depWindow::~depWindow() {
    controller.removeObserver(this);
    delete ui;
}

void depWindow::update() {
    this->populateList();
}

void depWindow::populateList() {
    ui->listWidget->clear();

    std::vector<std::string> res;
    for(auto d : controller.getDepartments()){
        std::stringstream ss;
        ss << d.getName() << "|";
        int nr = this->controller.getVolunteersByDepartment(d).size();
        ss << nr;
        res.push_back(ss.str());
    }
    for(auto s : res){
        ui->listWidget->addItem(QString::fromStdString(s));
    }
}
