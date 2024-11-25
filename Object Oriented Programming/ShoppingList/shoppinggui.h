//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT2_SHOPPINGGUI_H
#define TESTQT2_SHOPPINGGUI_H
#include "repository.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class shoppinggui; }
QT_END_NAMESPACE

class shoppinggui : public QMainWindow {
Q_OBJECT

public:
    explicit shoppinggui(Repository& _repo, QWidget *parent = nullptr);
    ~shoppinggui() override;

private:
    Ui::shoppinggui *ui;
    Repository& repo;
    void populateList();
private slots:
    void filterButtonClicked();
    void deleteButtonClicked();
};


#endif //TESTQT2_SHOPPINGGUI_H
