#pragma once
#ifndef OOP_A10_ALEXIAB5_TRENCHCOATSTABLEMODEL_H
#define OOP_A10_ALEXIAB5_TRENCHCOATSTABLEMODEL_H
#include "service.h"
#include <QAbstractTableModel>

class TrenchCoatsTableModel : public QAbstractTableModel{
private:
    Service &service;
public:
    TrenchCoatsTableModel(Service &service);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
};
#endif //OOP_A10_ALEXIAB5_TRENCHCOATSTABLEMODEL_H
