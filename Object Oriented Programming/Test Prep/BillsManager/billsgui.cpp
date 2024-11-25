//
// Created by alexia on 22.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_billsGUI.h" resolved

#include "billsgui.h"
#include <QMessageBox>
using namespace Ui;

BillsGUI::BillsGUI(BillsListFilterProxyModel* _filterProxyModel, QAbstractListModel* model, Service& _service, QWidget *parent) : QMainWindow(parent), ui{new Ui::BillsGUIClass}, serv(_service), filterProxyModel(_filterProxyModel){
    ui->setupUi(this);
    filterProxyModel->setSourceModel(model);
    ui->listView->setModel(filterProxyModel);
    connect(ui->calculateSumButton, &QPushButton::clicked, this, &BillsGUI::calculateSumButtonClicked);
    connect(ui->paidCheckBox, &QCheckBox::stateChanged, this, &BillsGUI::checkBoxStateChanged);
}

BillsGUI::~BillsGUI() {
    delete ui;
}

void BillsGUI::calculateSumButtonClicked() {
    std::string company = ui->companyInputLineEdit->text().toStdString();
    std::vector<Bill> bills = this->serv.getAllUnpaidBillsForCompany(company);
    if(bills.empty()){
        this->ui->totalSumLabel->setText("Total sum:");
        QMessageBox msg;
        msg.setText("There is no unpaid bill from that company!");
        msg.exec();
        return;
    }
    double sum = 0;
    for(const auto& bill : bills){
        sum += bill.getSum();
    }
    std::string s = "Total sum: " + std::to_string(sum);
    this->ui->totalSumLabel->setText(QString::fromStdString(s));
}

void BillsGUI::checkBoxStateChanged(int state) {
    this->filterProxyModel->setFilterActive(state == Qt::Checked);
}
