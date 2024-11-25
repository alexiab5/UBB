//
// Created by alexia on 28.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <sstream>
#include <QMessageBox>

gui::gui(Repository &_repo, QWidget *parent) :
        QMainWindow(parent), ui(new Ui::gui), repo(_repo) {
    ui->setupUi(this);
    this->populateList();
    connect(ui->addBtn, &QPushButton::clicked, this, &gui::addBtnClicked);
    connect(ui->computeBtn, &QPushButton::clicked, this, &gui::computeBtnClicked);
//    connect(ui->listWidget, &QListWidget::itemClicked, this, &gui::computeBtnClicked);
//    ui->listWidget->setSortingEnabled(true);
}

gui::~gui() {
    delete ui;
}

void gui::populateList() {
    auto v = this->repo.getAll();
    for(const auto& e : v){
        std::stringstream ss;
        ss << e;
        QListWidgetItem* w = new QListWidgetItem(QString::fromStdString(ss.str()));
        if(e.getA() == 0 || e.hasRealSolutions())
            w->setBackground(QBrush("green"));
        else {
            QFont f;
            f.setBold(true);
//            f = QFont("Arial",10,QFont::Bold);
            w->setFont(f);
        }
        ui->listWidget->addItem(w);
    }
}

void gui::computeBtnClicked() {
    auto v = ui->listWidget->selectedItems();
    if(!v.empty()){
        int it = ui->listWidget->row(v[0]);
        Equation eq = this->repo.getAll()[it];
        double det = eq.computeDiscriminant();
        std::stringstream ss;
        if(eq.getA() == 0){
            double x = -eq.getC() / eq.getB();
            ss << "x = " << x;
        }
        else if(det >= 0){
            double x1 = (double)(-eq.getB() + (double)sqrt(det))/2*eq.getA();
            double x2 = (double)(-eq.getB() + (double)sqrt(det))/2*eq.getA();
            ss << "x1 = " << x1 << " x2 = " << x2;
        }
        else{
            ss << "x1 = " << -eq.getB() << "/" << 2*eq.getA() << "+" << (double)sqrt(-det) << "i" <<"/" << 2*eq.getA();
            ss << " x2 = " << -eq.getB() << "/" << 2*eq.getA() << "-" << (double)sqrt(-det) << "i" <<"/" << 2*eq.getA();
        }
        ui->solutionsLabel->setText(QString::fromStdString("The solutions are: " + ss.str()));
    }
}

void gui::addBtnClicked(){
    std::string a = ui->lineEditA->text().toStdString();
    std::string b = ui->lineEditB->text().toStdString();
    std::string c = ui->lineEditC->text().toStdString();
    try{
        double a1 = std::stod(a);
        double b1 = std::stod(b);
        double c1 = std::stod(c);
        Equation eq{a1, b1, c1};
        this->repo.addEquation(eq);
        std::stringstream ss;
        ss << eq;
        QListWidgetItem* w = new QListWidgetItem(QString::fromStdString(ss.str()));
        if(eq.getA() == 0 || eq.hasRealSolutions())
            w->setBackground(QBrush("green"));
        ui->listWidget->addItem(w);
    }
    catch(...){
        QMessageBox msg;
        msg.setText("Error");
        msg.exec();
    }
}