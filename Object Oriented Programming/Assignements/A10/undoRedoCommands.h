#pragma once
#ifndef OOP_A10_ALEXIAB5_UNDOREDOCOMMANDS_H
#define OOP_A10_ALEXIAB5_UNDOREDOCOMMANDS_H
#include <QUndoCommand>
#include <QTableWidget>
#include "domain.h"
#include "service.h"
class AddCommand: public QUndoCommand{
public:
    AddCommand(Service& _service, QTableWidget* _tableWidget, TrenchCoat _trench, QUndoCommand *parent = nullptr);
    ~AddCommand(){};
    void undo() override;
    void redo() override;
private:
    QTableWidget* tableWidget;
    TrenchCoat trench;
    Service& service;
};

class DeleteCommand: public QUndoCommand{
public:
    DeleteCommand(Service& _service, QTableWidget* _tableWidget, TrenchCoat trench, int _oldPosition, QUndoCommand *parent = nullptr);
    ~DeleteCommand(){};
    void undo() override;
    void redo() override;
private:
    QTableWidget* tableWidget;
    TrenchCoat trench;
    Service& service;
    int oldPosition;
};

class UpdateCommand: public QUndoCommand{
public:
    UpdateCommand(Service& _service, QTableWidget* _tableWidget, TrenchCoat _oldTrench, TrenchCoat _updatedTrench, int _position, QUndoCommand *parent = nullptr);
    ~UpdateCommand(){};
    void undo() override;
    void redo() override;
private:
    QTableWidget* tableWidget;
    Service& service;
    TrenchCoat oldTrench;
    TrenchCoat updatedTrench;
    int position;
};
#endif //OOP_A10_ALEXIAB5_UNDOREDOCOMMANDS_H

