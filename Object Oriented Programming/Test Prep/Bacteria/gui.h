//
// Created by alexia on 26.06.2024.
//

#pragma once
#ifndef TEST4_GUI_H
#define TEST4_GUI_H

#include <QWidget>
#include "tablemodel.h"
#include "repository.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Biologist b, Repository& repository, TableModel* tableModel, QWidget *parent = nullptr);

    ~GUI() override;

private:
    Ui::GUI *ui;
    TableModel* tableModel;
    QSortFilterProxyModel* filterProxyModel;
    Repository &repository;
    Biologist biologist;
    void connectButtons();
    void setFilter();
private slots:
    void addBacteriumButtonClicked();
    void addDiseaseButtonClicked();
    void displaySelectedSpecies();
    void populateList();
};


#endif //TEST4_GUI_H
