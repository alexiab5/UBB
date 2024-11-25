//
// Created by alexia on 26.06.2024.
//
#include "tablemodel.h"

TableModel::TableModel(Repository &repository, QObject* parent):repository(repository),
                                                                              QAbstractTableModel(parent){}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::DisplayRole){
        int row = index.row();
        int column = index.column();
        Bacterium b =  repository.getBacteria()[row];
        if(column == 0){
            return QString::fromStdString(b.getName());
        }
        if(column == 1){
            return QString::fromStdString(b.getSpecies());
        }
        if(column == 2) {
            return QString::fromStdString(std::to_string(b.getSize()));
        }
        if(column == 3) {
            return QString::fromStdString(b.getDiseases());
        }
    }
    return QVariant{};
}

int TableModel::columnCount(const QModelIndex &parent) const {
        return 4;
}

int TableModel::rowCount(const QModelIndex &parent) const {
        return repository.getBacteria().size();
}

void TableModel::addBacterium(Bacterium &b) {
    this->repository.addBacterium(b);
    this->update();
}

void TableModel::update() {
    this->beginResetModel();
    this->endResetModel();
    emit dataChanged(index(0,0), index(rowCount()-1, columnCount()-1));
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role != Qt::EditRole)
        return false;
    int row = index.row();
    int column = index.column();
}

