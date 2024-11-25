//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_WINDOW_H
#define TEST2_WINDOW_H
#include "controller.h"
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget, public Observer {
Q_OBJECT

public:
    explicit Window(Controller& c, Department d, QWidget *parent = nullptr);
    void update() override;
    ~Window() override;

private:
    Ui::Window *ui;
    Controller& controller;
    Department department;
    void populateList();
    void populateUnassignedList();
    void connectButtons();
public slots:
    void addButtonPushed();
    void assignButtonPushed();
    void showAllButtonPushed();
    void top3ButtonPushed();
};


#endif //TEST2_WINDOW_H
