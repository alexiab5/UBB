#pragma once
#ifndef TESTQT1_BILLSLISTFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>
#include "billsListModel.h"
#include "repository.h"
#define TESTQT1_BILLSLISTFILTERPROXYMODEL_H
class BillsListFilterProxyModel : public QSortFilterProxyModel{
public:
    BillsListFilterProxyModel(Repository& repo, QObject* parent=nullptr);
    void setFilterActive(bool active);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
private:
    bool filterActive;
    Repository& repo;
};
#endif //TESTQT1_BILLSLISTFILTERPROXYMODEL_H
