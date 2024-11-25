//
// Created by alexia on 26.06.2024.
//
#pragma once
#ifndef TEST4_TABLEMODEL_H
#define TEST4_TABLEMODEL_H
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include "repository.h"

class TableModel: public QAbstractTableModel{
private:
    Repository& repository;
public:
    Biologist biologist;
    TableModel(Repository& repository, QObject* parent= nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void update();

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    void addBacterium(Bacterium& b);
};
#endif //TEST4_TABLEMODEL_H
