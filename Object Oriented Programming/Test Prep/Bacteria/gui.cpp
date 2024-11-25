//
// Created by alexia on 26.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>
#include <sstream>

GUI::GUI(Biologist b, Repository& repository, TableModel* tableModel, QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), repository(repository), tableModel(tableModel), biologist(b) {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(biologist.getName()));
    this->filterProxyModel = new QSortFilterProxyModel(this);
    filterProxyModel->setSourceModel(tableModel);
    ui->tableView->setModel(filterProxyModel);
    this->setFilter();
    this->connectButtons();

    ui->comboBox->clear();
    std::string species = biologist.getSpecies();
    std::stringstream ss(species);
    std::string token, res;
    while(getline(ss, token, ' ')){
        ui->comboBox->addItem(QString::fromStdString(token));
    }
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

GUI::~GUI() {
    delete ui;
}

void GUI::addBacteriumButtonClicked() {
    std::string name = ui->nameLineEdit->text().toStdString();
    std::string species = ui->speciesLineEdit->text().toStdString();
    int size = ui->nameLineEdit->text().toInt();
    std::string diseases = ui->diseasesLineEdit->text().toStdString();
    try{
        Bacterium b{name, species, diseases, size};
        this->tableModel->addBacterium(b);
    }
    catch(std::invalid_argument &ex){
        QMessageBox::critical(this, "Error", ex.what());
    }

//    this->setFilter();
}

void GUI::addDiseaseButtonClicked() {

}

void GUI::connectButtons() {
    connect(ui->addBacteriumButton, &QPushButton::clicked, this, &GUI::addBacteriumButtonClicked);
    connect(ui->addDiseaseButton, &QPushButton::clicked, this, &GUI::addDiseaseButtonClicked);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &GUI::displaySelectedSpecies);

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &GUI::populateList);  //!!!!!!!!
}

void GUI::setFilter() {
    this->filterProxyModel->invalidate();

    filterProxyModel->sort(0, Qt::AscendingOrder);
    std::string species = biologist.getSpecies();
    std::stringstream ss(species);
    std::string token, res;
    while(getline(ss, token, ' ')){
        res += token + "|";
    }
    if (!res.empty()) {
        res.pop_back();
    }
    QRegularExpression regex(QString::fromStdString(res));
    filterProxyModel->setFilterKeyColumn(1);
    filterProxyModel->setFilterRegularExpression(regex);
}

void GUI::displaySelectedSpecies() {
    this->filterProxyModel->invalidate();
    filterProxyModel->sort(0, Qt::AscendingOrder);
    filterProxyModel->setFilterRegularExpression(ui->comboBox->currentText());
    filterProxyModel->setFilterKeyColumn(1);
}

void GUI::populateList() {
    auto selected = ui->tableView->selectionModel()->selectedIndexes();
    if(selected.size() == 0){
        ui->listWidget->clear();
        return;
    }

    ui->listWidget->clear();
    int row = selected[0].row();

    auto bact = this->repository.getBacteriaForBiologist(this->biologist);
    std::vector<Bacterium> bac2;

    std::string species = ui->comboBox->currentText().toStdString();
    std::copy_if(bact.begin(), bact.end(), std::back_inserter(bac2), [&species](const Bacterium & b){return b.getSpecies() == species;});
    std::sort(bac2.begin(), bac2.end(), [](const Bacterium &b1, const Bacterium &b2){return b1.getName() < b2.getName();});

    std::string diseases = bact[row].getDiseases();
    std::stringstream ss(diseases);
    std::string token, res;
    while(getline(ss, token, ' ')){
        ui->listWidget->addItem(QString::fromStdString(token));
    }
}
