//
// Created by alexia on 26.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VegetablesGUI.h" resolved

#include "vegetablesGUI.h"
#include "ui_VegetablesGUI.h"
#include <QMessageBox>

VegetablesGUI::VegetablesGUI(Repository& _repo, QWidget *parent) :
        repo(_repo), QMainWindow(parent), ui(new Ui::VegetablesGUI) {
    ui->setupUi(this);
    this->loadFamiliesList();
    connect(ui->familyNameListWidget, &QListWidget::itemClicked, this, &VegetablesGUI::loadVegetablesList);
    connect(ui->searchButton, &QPushButton::clicked, this, &VegetablesGUI::searchButtonClicked);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &VegetablesGUI::linechanged);
}

VegetablesGUI::~VegetablesGUI() {
    delete ui;
}

void VegetablesGUI::loadFamiliesList() {
    auto v = this->repo.getAllFamilies();
    std::sort(v.begin(), v.end());
    ui->familyNameListWidget->clear();
    for(const auto& s : v){
        ui->familyNameListWidget->addItem(QString::fromStdString(s));
    }
}

void VegetablesGUI::loadVegetablesList() {
    auto s = ui->familyNameListWidget->selectedItems();
    if(s.empty())
        return;
    int row = ui->familyNameListWidget->row(s[0]);
    auto v = this->repo.getAllFamilies();
    std::sort(v.begin(), v.end());
    std::string familyName = v[row];
    auto veggies = this->repo.getAllByFamily(familyName);
    ui->vegetablesListWidget->clear();
    for(const auto& veg : veggies){
        std::stringstream ss;
        ss << veg.getName() << "|" << veg.getPart();
        ui->vegetablesListWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void VegetablesGUI::searchButtonClicked() {
    std::string veggie = ui->vegetableLineEdit->text().toStdString();
    if(veggie.empty()) {
        ui->ediblePartsLabel->setText("Edible parts:");
        return;
    }
    try{
        Vegetable v = this->repo.searchVegetableByName(veggie);
        std::string s = "Edible parts: " + v.getPart();
        ui->ediblePartsLabel->setText(QString::fromStdString(s));
        //deselect all other items
//        int aux = ui->familyNameListWidget->currentRow();
//        ui->familyNameListWidget->setCurrentRow(aux, QItemSelectionModel::Deselect);
        ui->familyNameListWidget->clearSelection();
        // selecting the family name of the veggie in the first list
        auto x = ui->familyNameListWidget->findItems(QString::fromStdString(v.getFamily()), Qt::MatchExactly);
        int row = ui->familyNameListWidget->row(x[0]);
        ui->familyNameListWidget->setCurrentRow(row, QItemSelectionModel::Select);
    }
    catch(...){
        ui->ediblePartsLabel->setText("Edible parts:");
        QMessageBox msg;
        msg.setText("There is no vegetable with that name in our database!");
        msg.exec();
    }
}

void VegetablesGUI::linechanged(){
    ui->label_2->setText("hahahahah");
}