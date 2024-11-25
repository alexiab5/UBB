//
// Created by alexia on 28.05.2024.
//

#ifndef OOP_T3_ALEXIAB5_GUI_H
#define OOP_T3_ALEXIAB5_GUI_H

#include <QMainWindow>
#include "service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QMainWindow {
Q_OBJECT

public:
    explicit gui(Service &_serv, QWidget *parent = nullptr);

    ~gui() override;

private:
    Ui::gui *ui;
    Service &serv;
    std::vector<Document> docsOnDisplay;
    void populateList();
    void reloadList(std::vector<Document> newDocuments);
private slots:
    void searchTextChanged();
    void showSimilarity();
};


#endif //OOP_T3_ALEXIAB5_GUI_H
