//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_STATISTICSWINDOW_H
#define TEST3_STATISTICSWINDOW_H
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QBrush>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StatisticsWindow; }
QT_END_NAMESPACE

class StatisticsWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit StatisticsWindow(Controller &c, QWidget *parent = nullptr);
    void update() override;
    ~StatisticsWindow() override;

private:
    Ui::StatisticsWindow *ui;
    Controller& controller;
    void paintEvent(QPaintEvent *) override;
};


#endif //TEST3_STATISTICSWINDOW_H
