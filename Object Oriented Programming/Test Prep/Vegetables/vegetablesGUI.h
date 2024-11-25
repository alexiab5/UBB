//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT3_VEGETABLESGUI_H
#define TESTQT3_VEGETABLESGUI_H
#include "repository.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class VegetablesGUI; }
QT_END_NAMESPACE

class VegetablesGUI : public QMainWindow {
Q_OBJECT

public:
    explicit VegetablesGUI(Repository& _repo, QWidget *parent = nullptr);

    ~VegetablesGUI() override;

private:
    Ui::VegetablesGUI *ui;
    Repository& repo;
    void loadFamiliesList();
private slots:
    void loadVegetablesList();
    void searchButtonClicked();
    void linechanged();
};


#endif //TESTQT3_VEGETABLESGUI_H
