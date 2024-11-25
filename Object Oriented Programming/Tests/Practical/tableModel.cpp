//
// Created by alexia on 27.06.2024.
//
#include "tableModel.h"

TableModel::TableModel(Service &service, QObject *parent): service(service), QAbstractTableModel(parent) {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return service.getIdeas().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if(role == Qt::DisplayRole){
        Idea currentIdea = service.getIdeas()[row];
        if(column == 0){
            return QString::fromStdString(currentIdea.getTitle());
        }
        if(column == 1){
            return QString::fromStdString(currentIdea.getDescription());
        }
        if(column == 2){
            return QString::fromStdString(currentIdea.getStatus());
        }
        if(column == 3){
            return QString::fromStdString(currentIdea.getCreator());
        }
        if(column == 4){
            std::string nr = std::to_string(currentIdea.getDuration());
            return QString::fromStdString(nr);
        }
    }
    return QVariant{};
}

void TableModel::update() {
    this->beginResetModel();
    this->endResetModel();
    auto index1 = createIndex(0, 0);
    auto index2 = createIndex(rowCount()-1, columnCount() -1);
    emit dataChanged(index1, index2);
}

void TableModel::addIdea(Idea &i) {
    this->service.addIdea(i);
    this->update();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TableModel::acceptIdea(int row) {
    auto ideas = this->service.getIdeas();
    std::sort(ideas.begin(), ideas.end(), [](const Idea& i1, const Idea &i2){return i1.getDuration() < i2.getDuration();});

    Idea current = ideas[row];
    if(current.getStatus() != "proposed"){
        throw std::invalid_argument("You cannot accept this idea!");
    }
    auto idea = ideas[row];
    this->service.acceptIdea(idea);
    auto ind1 = createIndex(row, 2);
    emit dataChanged(ind1, ind1);
}

