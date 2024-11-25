//
// Created by alexia on 24.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "ui_Window.h"
#include <QMessageBox>

Window::Window(Controller& c, Department d, QWidget *parent) :
        QWidget(parent), ui(new Ui::Window), department(d), controller(c){
    ui->setupUi(this);
    controller.addObserver(this);
    this->setWindowTitle(QString::fromStdString(d.getName()));
    ui->descriptionLabel->setText(QString::fromStdString(d.getDescription()));
    this->populateList();
    this->populateUnassignedList();
    this->connectButtons();
}

Window::~Window() {
    controller.removeObserver(this);
    delete ui;
}

void Window::populateList() {
    if(ui->volunteersListWidget->count() > 0)
        ui->volunteersListWidget->clear();

    for(auto vol : controller.getVolunteersSorted()){
        if(vol.getDepartment() == department.getName()) {
            std::stringstream ss;
            ss << vol;
            ui->volunteersListWidget->addItem(QString::fromStdString(ss.str()));
        }
    }
}

void Window::update() {
    this->populateList();
    this->populateUnassignedList();
}

void Window::populateUnassignedList() {
    if(ui->unassignedListWidget->count() > 0)
        ui->unassignedListWidget->clear();

    for(auto vol : controller.getVolunteersSorted()){
        if(vol.getDepartment().empty()) {
            std::stringstream ss;
            ss << vol;
            ui->unassignedListWidget->addItem(QString::fromStdString(ss.str()));
        }
    }
}

void Window::connectButtons() {
    connect(ui->addButton, &QPushButton::clicked, this, &Window::addButtonPushed);
    connect(ui->assignButton, &QPushButton::clicked, this, &Window::assignButtonPushed);
    connect(ui->showAllButton, &QPushButton::clicked, this, &Window::showAllButtonPushed);
    connect(ui->top3Button, &QPushButton::clicked, this, &Window::top3ButtonPushed);
}

void Window::addButtonPushed() {
    std::string name = ui->nameLineEdit->text().toStdString();
    std::string email = ui->emailLineEdit->text().toStdString();
    std::string interests = ui->interestsLineEdit->text().toStdString();
    if(email.empty() || name.empty()){
        QMessageBox::critical(this, "Error", "Name or email fields missing!");
        return;
    }
    Volunteer v{name, email, interests, ""};
    this->controller.addVolunteer(v);
}

void Window::assignButtonPushed() {
    auto selected = ui->unassignedListWidget->selectedItems();
    if(selected.size() == 0)
        return;
    auto item = selected.at(0);
    int index = ui->unassignedListWidget->row(item);
    std::vector<Volunteer> vols = this->controller.getVolunteersSorted();
    std::vector<Volunteer> unassigned;
    std::copy_if(vols.begin(), vols.end(), std::back_inserter(unassigned), [](Volunteer &v){return v.getDepartment().empty();});
    this->controller.changeDepartment(unassigned[index], this->department.getName());
}

void Window::showAllButtonPushed() {
    this->populateUnassignedList();
}

void Window::top3ButtonPushed() {
    auto vols = this->controller.getTop3(this->department);
    ui->unassignedListWidget->clear();
    for(auto v : vols){
        std::stringstream ss;
        ss << v;
        ui->unassignedListWidget->addItem(QString::fromStdString(ss.str()));
    }
}
