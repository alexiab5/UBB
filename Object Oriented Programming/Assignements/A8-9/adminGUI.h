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
#include "service.h"
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
    void reloadTrenchCoatsTable();
    void selectRowTrenchCoatsTable(int index);

public:
    AdminGUI(Service& _service, QWidget* parent=nullptr);
    ~AdminGUI(){};
public slots:
    void closeButtonClicked();
    void addButtonClicked();
    void deleteButtonClicked();
    void updateButtonClicked();
signals:
    void CloseAdminWindow();
private:
    QVBoxLayout* mainAdminLayout;
    QHBoxLayout* trenchCoatInfoLayout;
    QVBoxLayout* trenchCoatInfo;
    QLabel* adminTitle;

    QHBoxLayout* buttonsLayout;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* closeButton;

    QHBoxLayout* priceLayout;
    QLabel* priceLabel;
    QLineEdit* priceInput;
    QHBoxLayout* colourLayout;
    QLabel* colourLabel;
    QLineEdit* colourInput;
    QHBoxLayout* sizeLayout;
    QLabel* sizeLabel;
    QLineEdit* sizeInput;
    QHBoxLayout* quantityLayout;
    QLabel* quantityLabel;
    QLineEdit* quantityInput;
    QHBoxLayout* photographLayout;
    QLabel* photographLabel;
    QLineEdit* photographInput;

    QTableWidget* trenchCoatsTable;
};