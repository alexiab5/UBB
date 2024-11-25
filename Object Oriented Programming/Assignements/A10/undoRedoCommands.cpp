//
// Created by alexia on 27.05.2024.
//
#include "undoRedoCommands.h"
#include <QDebug>

AddCommand::AddCommand(Service& _service, QTableWidget *_tableWidget, TrenchCoat _trench, QUndoCommand *parent): service(_service), tableWidget(_tableWidget), trench(_trench) {}

void AddCommand::undo() {
    this->service.removeTrenchCoatService(trench);
    int row = this->tableWidget->rowCount() - 1;
    this->tableWidget->removeRow(row);
}

void AddCommand::redo() {
    this->service.addTrenchCoatService(trench);
    int rowCount = this->tableWidget->rowCount();
    this->tableWidget->insertRow(rowCount);
    this->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(trench.getColour())));
    this->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number(trench.getSize())));
    this->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(QString::number(trench.getPrice())));
    this->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(QString::number(trench.getQuantity())));
    this->tableWidget->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(trench.getPhotograph())));
}


DeleteCommand::DeleteCommand(Service &_service, QTableWidget *_tableWidget, TrenchCoat _trench, int _oldPosition, QUndoCommand *parent):
                                service(_service), trench(_trench), tableWidget(_tableWidget), oldPosition(_oldPosition) {}

void DeleteCommand::undo() {
    this->service.addTrenchCoatService(trench);
    this->tableWidget->insertRow(this->oldPosition);
    this->tableWidget->setItem(this->oldPosition, 0, new QTableWidgetItem(QString::fromStdString(trench.getColour())));
    this->tableWidget->setItem(this->oldPosition, 1, new QTableWidgetItem(QString::number(trench.getSize())));
    this->tableWidget->setItem(this->oldPosition, 2, new QTableWidgetItem(QString::number(trench.getPrice())));
    this->tableWidget->setItem(this->oldPosition, 3, new QTableWidgetItem(QString::number(trench.getQuantity())));
    this->tableWidget->setItem(this->oldPosition, 4, new QTableWidgetItem(QString::fromStdString(trench.getPhotograph())));
}

void DeleteCommand::redo() {
    this->service.removeTrenchCoatService(trench);
    this->tableWidget->removeRow(this->oldPosition);
}

UpdateCommand::UpdateCommand(Service &_service, QTableWidget *_tableWidget, TrenchCoat _oldTrench, TrenchCoat _updatedTrench, int _position, QUndoCommand *parent):
                                service(_service), tableWidget(_tableWidget), oldTrench(_oldTrench), updatedTrench(_updatedTrench), position(_position) {}

void UpdateCommand::undo() {
    this->service.updateUniqueTrenchCoatService(this->oldTrench);
    this->tableWidget->setItem(this->position, 0, new QTableWidgetItem(QString::fromStdString(this->oldTrench.getColour())));
    this->tableWidget->setItem(this->position, 1, new QTableWidgetItem(QString::number(this->oldTrench.getSize())));
    this->tableWidget->setItem(this->position, 2, new QTableWidgetItem(QString::number(this->oldTrench.getPrice())));
    this->tableWidget->setItem(this->position, 3, new QTableWidgetItem(QString::number(this->oldTrench.getQuantity())));
    this->tableWidget->setItem(this->position, 4, new QTableWidgetItem(QString::fromStdString(this->oldTrench.getPhotograph())));
}

void UpdateCommand::redo() {
    this->service.updateUniqueTrenchCoatService(this->updatedTrench);
    this->tableWidget->setItem(this->position, 0, new QTableWidgetItem(QString::fromStdString(this->updatedTrench.getColour())));
    this->tableWidget->setItem(this->position, 1, new QTableWidgetItem(QString::number(this->updatedTrench.getSize())));
    this->tableWidget->setItem(this->position, 2, new QTableWidgetItem(QString::number(this->updatedTrench.getPrice())));
    this->tableWidget->setItem(this->position, 3, new QTableWidgetItem(QString::number(this->updatedTrench.getQuantity())));
    this->tableWidget->setItem(this->position, 4, new QTableWidgetItem(QString::fromStdString(this->updatedTrench.getPhotograph())));
}
