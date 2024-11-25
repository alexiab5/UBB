//
// Created by alexia on 27.06.2024.
//

#pragma once
#ifndef OOP_E_912_914_ALEXIAB5_WINDOW_H
#define OOP_E_912_914_ALEXIAB5_WINDOW_H

#include <QWidget>
#include "service.h"
#include "tableModel.h"
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget {
Q_OBJECT

public:
    explicit Window(TableModel* tableModel, Service& service, Researcher researcher, QWidget *parent = nullptr);

    ~Window() override;

private:
    Ui::Window *ui;
    Service& service;
    Researcher researcher;
    TableModel* tableModel;
    QSortFilterProxyModel* filterProxymodel;

    void connectButtons();

private slots:
    void addButtonClicked();
    void acceptButtonClicked();
    void developButtonClicked();
    void saveAllButtonClicked();
    void checkEnableDevelopButton();
    void saveDescriptionButtonClicked();
};


#endif //OOP_E_912_914_ALEXIAB5_WINDOW_H
