#pragma once
#ifndef TESTQT1_BILLSLISTMODEL_H
#include <QListView>
#include <QAbstractListModel>
#include "repository.h"
#define TESTQT1_BILLSLISTMODEL_H
class BillsListModel: public QAbstractListModel{
private:
    Repository& repo;
public:
    BillsListModel(Repository& _repo);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};
#endif //TESTQT1_BILLSLISTMODEL_H
