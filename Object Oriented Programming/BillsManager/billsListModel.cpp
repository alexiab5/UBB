//
// Created by alexia on 25.05.2024.
//
#include "billsListModel.h"

BillsListModel::BillsListModel(Repository &_repo): repo(_repo) {}

int BillsListModel::rowCount(const QModelIndex &parent) const {
    return this->repo.getSize();
}

QVariant BillsListModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    Bill bill = this->repo.getBillsSortedByName()[row];
    if(role == Qt::DisplayRole){
//        std::stringstream ss;
//        ss << bill;
//        return QString::fromStdString(ss.str());
        std::string s = bill.getCompany() + " " + std::to_string(bill.getSum());
        return QString::fromStdString(s);
    }
    if(role == Qt::BackgroundRole){
        if(!bill.isPaid())
            return QBrush(QColor("red"));
    }
    return QVariant();
}

QVariant BillsListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return QAbstractItemModel::headerData(section, orientation, role);
}


