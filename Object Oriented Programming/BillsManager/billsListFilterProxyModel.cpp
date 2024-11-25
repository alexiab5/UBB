//
// Created by alexia on 25.05.2024.
//
#include "billsListFilterProxyModel.h"

BillsListFilterProxyModel::BillsListFilterProxyModel(Repository& repo, QObject *parent) : QSortFilterProxyModel(parent), repo(repo), filterActive(false){}

void BillsListFilterProxyModel::setFilterActive(bool active) {
    this->filterActive = active;
    this->invalidateFilter();
}

bool BillsListFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (!this->filterActive)
        return true;

    QModelIndex index = this->sourceModel()->index(source_row, 0, source_parent);
    QVariant data = sourceModel()->data(index, Qt::BackgroundRole);
    if(data == QBrush("red")) // show only unpaid bills
        return true;
    return false;
}

