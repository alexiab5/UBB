//
// Created by alexia on 27.05.2024.
//
#include "trenchCoatsTableModel.h"

TrenchCoatsTableModel::TrenchCoatsTableModel(Service &_service): service(_service) {}

int TrenchCoatsTableModel::rowCount(const QModelIndex &parent) const {
    return this->service.getNumberOfItemsInShoppingCartService();
}

int TrenchCoatsTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TrenchCoatsTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
            case 0:
                return "Colour";
            case 1:
                return "Size";
            case 2:
                return "Price";
            case 3:
                return "Quantity";
            case 4:
                return "Photograph";
            default:
                break;
        }
    }
    return QVariant();
}

QVariant TrenchCoatsTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    TrenchCoat trench = this->service.getShoppingCartService()[row];
    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(trench.getColour());
            case 1:
                return QString::number(trench.getSize());
            case 2:
                return QString::number(trench.getPrice());
            case 3:
                return QString::number(trench.getQuantity());
            case 4:
                return QString::fromStdString(trench.getPhotograph());
            default:
                break;
        }
    }
    return QVariant();
}

bool TrenchCoatsTableModel::insertRows(int row, int count, const QModelIndex &parent) {
    emit beginInsertRows(parent, row, row + count - 1);
    emit endInsertRows();
    return true;
}

bool TrenchCoatsTableModel::removeRows(int row, int count, const QModelIndex &parent) {
    emit beginRemoveRows(parent, row, row + count - 1);
    this->service.buyAllService();
    emit endRemoveRows();
    return true;
}

