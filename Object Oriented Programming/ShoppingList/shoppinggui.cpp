//
// Created by alexia on 26.05.2024.
//

#include "shoppinggui.h"
#include "ui_shoppinggui.h"
#include <sstream>
#include <QMessageBox>

shoppinggui::shoppinggui(Repository& _repo, QWidget *parent) : repo(_repo), QMainWindow(parent), ui(new Ui::shoppinggui) {
    ui->setupUi(this);
    this->populateList();
    connect(ui->filterButton, &QPushButton::clicked, this, &shoppinggui::filterButtonClicked);
    connect(ui->deteleButton, &QPushButton::clicked, this, &shoppinggui::deleteButtonClicked);

}

shoppinggui::~shoppinggui() {
    delete ui;
}

void shoppinggui::populateList() {
    ui->shoppingListWidget->clear();

    auto v = this->repo.getAll();
    for(const auto& s : v){
        std::stringstream ss;
        ss << s;
        ui->shoppingListWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void shoppinggui::filterButtonClicked() {
    std::string category = ui->filterLineEdit->text().toStdString();
    if(category.empty()){
        this->populateList();
        return;
    }
    ui->shoppingListWidget->clear();
    std::vector<ShoppingList> res = this->repo.filterByCategory(category);
    for(const auto& s : res){
        std::stringstream ss;
        ss << s;
        ui->shoppingListWidget->addItem(QString::fromStdString(ss.str()));
    }
}

void shoppinggui::deleteButtonClicked() {
    auto s = ui->shoppingListWidget->selectedItems();
    if(s.isEmpty())
        return;
    if(s.size() > 1){
        QMessageBox msg;
        msg.setText("Please select a single item from the list!");
        msg.exec();
        return;
    }
    int row = ui->shoppingListWidget->row(s[0]);
    this->repo.deleteShoppingListByIndex(row);
    ui->shoppingListWidget->takeItem(row);
}
