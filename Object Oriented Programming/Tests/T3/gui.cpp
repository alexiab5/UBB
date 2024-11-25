//
// Created by alexia on 28.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"


gui::gui(Service &_serv, QWidget *parent) :
        QMainWindow(parent), ui(new Ui::gui), serv(_serv) {
    ui->setupUi(this);
    this->populateList();
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &gui::searchTextChanged);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &gui::showSimilarity);
}

gui::~gui() {
    delete ui;
}

void gui::populateList() {
    ui->listWidget->clear();
    auto v = this->serv.getSorted();
    this->docsOnDisplay = v;
    for(const auto& doc : v){
        std::stringstream ss;
        ss << doc.getName() << " | " << doc.getKeywords();
        ui->listWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void gui::reloadList(std::vector<Document> newDocuments) {
    ui->listWidget->clear();
    auto v = newDocuments;
    this->docsOnDisplay = v;
    for(const auto& doc : v){
        std::stringstream ss;
        ss << doc.getName() << " | " << doc.getKeywords();
        ui->listWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void gui::searchTextChanged() {
    std::string key = ui->searchLineEdit->text().toStdString();
    std::vector<Document> docs;
    if(key.empty())
        docs = this->serv.getAllService();
    else
        docs = this->serv.getMatchingDocuments(key);
    this->reloadList(docs);
}

void gui::showSimilarity() {
    std::string key = ui->searchLineEdit->text().toStdString();
    if(key.empty())
        return;
    auto v = ui->listWidget->selectedItems();
    int position = ui->listWidget->row(v[0]);
    Document doc = this->docsOnDisplay[position];
    double similarity = this->serv.getSimilarity(doc, key);
    std::stringstream ss;
    ss << "Similarity: " << similarity;
    ui->similarityLabel->setText(QString::fromStdString(ss.str()));
}
