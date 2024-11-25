//
// Created by alexia on 28.05.2024.
//

#ifndef TESTQT5_GUI_H
#define TESTQT5_GUI_H

#include <QMainWindow>
#include "repo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QMainWindow {
    Q_OBJECT

public:
    explicit gui(Repository &repo, QWidget *parent = nullptr);

    ~gui() override;

private:
    Ui::gui *ui;
    Repository repo;

    void populateList();
private slots:
    void addBtnClicked();
    void computeBtnClicked();
};


#endif //TESTQT5_GUI_H
