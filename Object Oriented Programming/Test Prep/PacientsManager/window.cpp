//
// Created by alexia on 24.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "ui_Window.h"
#include <QMessageBox>

Window::Window(Controller &c, Doctor d, QWidget *parent) :
        QWidget(parent), ui(new Ui::Window), controller(c), doctor(d){
    controller.addObserver(this);
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(doctor.getName()));
    this->populateList();
    this->connectButtons();
}

Window::~Window() {
    controller.removeObserver(this);
    delete ui;
}

void Window::update() {
    this->populateList();
}

void Window::addButtonClicked() {
    std::string name = ui->nameLineEdit->text().toStdString();
    if(name.empty()){
        QMessageBox::critical(this, "Error", "Empty name field!");
        return;
    }
    std::string date = ui->dateLineEdit->text().toStdString();
    if(date < "2024.06.24"){
        QMessageBox::critical(this, "Error", "Date cannot be in the past!");
        return;
    }
    std::string specialisation = ui->specialisationLineEdit->text().toStdString();
    std::string doctor = ui->doctorLineEdit->text().toStdString();
    std::string diagnosis = ui->diagnosisLineEdit->text().toStdString();
    if(diagnosis.empty())
        diagnosis = "undiagnosed";
    Pacient p{name, date, diagnosis, specialisation, doctor};
    this->controller.addPacient(p);
}

void Window::updateSpecialisationButtonClicked() {
    auto selected = ui->listWidget->selectedItems();
    if(selected.size() == 0)
        return;
    std::string specialisation = ui->updateSpecialisationLineEdit->text().toStdString();
    if(specialisation.empty()){
        QMessageBox::critical(this, "Error", "Empty specialisation field");
        return;
    }
    int index = ui->listWidget->row(selected[0]);
    Pacient p = pacientsOnDisplay[index];
    if(p.getDiagnosis() == "undiagnosed" && p.getCurrentDoctor() != this->doctor.getName()){
        QMessageBox::critical(this, "Error", "You cannot update that pacient's specialisation!");
        return;
    }
    this->controller.updateSpecialisation(p, specialisation);
}

void Window::updateDiagnosisButtonClicked() {
    auto selected = ui->listWidget->selectedItems();
    if(selected.size() == 0)
        return;
    std::string diagnosis = ui->updateDiagnosisLineEdit->text().toStdString();
    if(diagnosis.empty()){
        QMessageBox::critical(this, "Error", "Empty diagnosis field");
        return;
    }
    int index = ui->listWidget->row(selected[0]);
    Pacient p = pacientsOnDisplay[index];
    if(p.getDiagnosis() != "undiagnosed" && p.getCurrentDoctor() != this->doctor.getName()){
        QMessageBox::critical(this, "Error", "You cannot update that pacient's diagnosis!");
        return;
    }
    if(diagnosis == "undiagnosed"){
        QMessageBox::critical(this, "Error", "You cannot changed the diagnosis to undiagnosed!");
        return;
    }
    this->controller.updateDiagnosis(p, diagnosis);
}

void Window::populateList() {
    ui->listWidget->clear();

    auto pacients = controller.getPacients();
    std::vector<Pacient> withSpecialisation;
    std::string s = doctor.getSpecialisation();
    std::copy_if(pacients.begin(), pacients.end(), std::back_inserter(withSpecialisation), [&s](const Pacient& p){return p.getSpecialisation() == s;});
    std::copy_if(pacients.begin(), pacients.end(), std::back_inserter(withSpecialisation), [&s](const Pacient& p){return p.getDiagnosis() == "undiagnosed" && p.getSpecialisation() != s;});
    std::sort(withSpecialisation.begin(), withSpecialisation.end(), [](const Pacient& p1,const Pacient& p2){return p1.getAdmissionDate() > p2.getAdmissionDate();});
    pacientsOnDisplay = withSpecialisation;
    for(auto pacient : withSpecialisation){
        std::stringstream ss;
        ss << pacient;
        QListWidgetItem* it = new QListWidgetItem(QString::fromStdString(ss.str()));
        if(pacient.getCurrentDoctor() == doctor.getName()){
            QBrush *b = new QBrush("green");
            it->setBackground(*b);
        }
        ui->listWidget->addItem(it);
    }
}

void Window::connectButtons() {
    connect(ui->addButton, &QPushButton::clicked, this, &Window::addButtonClicked);
    connect(ui->updateDiagnosisButton, &QPushButton::clicked, this, &Window::updateDiagnosisButtonClicked);
    connect(ui->updateSpecialisationButton, &QPushButton::clicked, this, &Window::updateSpecialisationButtonClicked);
    connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &Window::checkBoxChanged);
}

void Window::checkBoxChanged() {
    if(ui->checkBox->checkState() == Qt::Checked) {
        ui->listWidget->clear();

        auto pacients = controller.getPacients();
        std::vector<Pacient> withSpecialisation;
        std::string s = doctor.getSpecialisation();
        std::string name = doctor.getName();
        std::copy_if(pacients.begin(), pacients.end(), std::back_inserter(withSpecialisation),
                     [&name](const Pacient &p) { return p.getCurrentDoctor() == name; });
        std::sort(withSpecialisation.begin(), withSpecialisation.end(),
                  [](const Pacient &p1, const Pacient &p2) { return p1.getAdmissionDate() > p2.getAdmissionDate(); });
        pacientsOnDisplay = withSpecialisation;
        for (auto pacient: withSpecialisation) {
            std::stringstream ss;
            ss << pacient;
            QListWidgetItem *it = new QListWidgetItem(QString::fromStdString(ss.str()));
            QBrush *b = new QBrush("green");
            it->setBackground(*b);
            ui->listWidget->addItem(it);
        }
    }
    else{
        this->populateList();
    }
}
