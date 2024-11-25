//
// Created by alexia on 27.06.2024.
//
#pragma once
#ifndef OOP_E_912_914_ALEXIAB5_TABLEMODEL_H
#define OOP_E_912_914_ALEXIAB5_TABLEMODEL_H
#include <QAbstractTableModel>
#include "service.h"

class TableModel: public QAbstractTableModel{
private:
    Service& service;
public:
    TableModel(Service& service, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void update();
    void addIdea(Idea& i);
    void acceptIdea(int row);
};

#endif //OOP_E_912_914_ALEXIAB5_TABLEMODEL_H
