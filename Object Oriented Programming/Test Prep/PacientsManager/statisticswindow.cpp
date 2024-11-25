//
// Created by alexia on 24.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StatisticsWindow.h" resolved

#include "statisticswindow.h"
#include "ui_StatisticsWindow.h"


StatisticsWindow::StatisticsWindow(Controller &c, QWidget *parent) :
        QWidget(parent), ui(new Ui::StatisticsWindow), controller(c) {
    ui->setupUi(this);
    repaint();
}

StatisticsWindow::~StatisticsWindow() {
    delete ui;
}

void StatisticsWindow::update() {
    repaint();
}

void StatisticsWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::blue);
    QList<QRect> list;
    int noSpecialisations = controller.getSpecialisations().size();
    int width = 30, height = 92;
    int x = 100, y = 100;
    for(auto s : controller.getSpecialisations()){
        int nr = this->controller.getPacientsBySpecialisation(s).size();
        painter.drawRect(x, y, nr * width, nr * height);
        x += nr * width;
//        y += nr * height;
    }
}
