#pragma once
#ifndef OOP_A8_9_ALEXIAB5_ADMINGUI_H
#define OOP_A8_9_ALEXIAB5_ADMINGUI_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QUndoStack>
#include <QUndoCommand>
#include "service.h"
#include "undoRedoCommands.h"
#endif //OOP_A8_9_ALEXIAB5_ADMINGUI_H

class AdminGUI : public QWidget{
    Q_OBJECT
private:
    Service& service;
    void createAdminButtons();
    void createColourLayout();
    void createSizeLayout();
    void createQuantityLayout();
    void createPriceLayout();
    void createPhotographLayout();
    void createTableWidget();
    TrenchCoat extractTrenchCoatInfo();
//    void reloadTrenchCoatsTable();
    void selectRowTrenchCoatsTable(int index);

public:
    AdminGUI(Service& _service, QWidget* parent=nullptr);
    ~AdminGUI(){};
public slots:
    void closeButtonClicked();
    void addButtonClicked();
    void deleteButtonClicked();
    void updateButtonClicked();
    void undoButtonClicked();
    void redoButtonClicked();
signals:
    void CloseAdminWindow();
private:
    QVBoxLayout* mainAdminLayout= nullptr;
    QHBoxLayout* trenchCoatInfoLayout= nullptr;
    QVBoxLayout* trenchCoatInfo= nullptr;
    QLabel* adminTitle= nullptr;

    QHBoxLayout* buttonsLayout= nullptr;
    QHBoxLayout* undoRedoButtonsLayout= nullptr;
    QPushButton* addButton= nullptr;
    QPushButton* deleteButton= nullptr;
    QPushButton* updateButton= nullptr;
    QPushButton* closeButton= nullptr;
    QPushButton* undoButton= nullptr;
    QPushButton* redoButton= nullptr;
    QUndoStack* undoStack= nullptr;
    QAction* undoAction = nullptr;
    QAction* redoAction = nullptr;

    QHBoxLayout* priceLayout= nullptr;
    QLabel* priceLabel= nullptr;
    QLineEdit* priceInput= nullptr;
    QHBoxLayout* colourLayout= nullptr;
    QLabel* colourLabel= nullptr;
    QLineEdit* colourInput= nullptr;
    QHBoxLayout* sizeLayout= nullptr;
    QLabel* sizeLabel= nullptr;
    QLineEdit* sizeInput= nullptr;
    QHBoxLayout* quantityLayout= nullptr;
    QLabel* quantityLabel= nullptr;
    QLineEdit* quantityInput= nullptr;
    QHBoxLayout* photographLayout= nullptr;
    QLabel* photographLabel= nullptr;
    QLineEdit* photographInput= nullptr;

    QTableWidget* trenchCoatsTable= nullptr;
};