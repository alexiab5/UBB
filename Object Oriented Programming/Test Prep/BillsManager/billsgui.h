//
// Created by alexia on 25.05.2024.
//

#ifndef TESTQT1_BILLSGUI_H
#include "ui_billsgui.h"
#include "service.h"
#include "billsListFilterProxyModel.h"
#define TESTQT1_BILLSGUI_H
class BillsGUI : public QMainWindow{
private:
    Ui::BillsGUIClass *ui;
    Service& serv;
    BillsListFilterProxyModel* filterProxyModel;
private slots:
    void calculateSumButtonClicked();
    void checkBoxStateChanged(int state);
public:
    BillsGUI(BillsListFilterProxyModel* _filterProxyModel, QAbstractListModel* model, Service& _service, QWidget *parent=nullptr);
    ~BillsGUI();
};
#endif //TESTQT1_BILLSGUI_H
