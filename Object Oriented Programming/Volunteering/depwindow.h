//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_DEPWINDOW_H
#define TEST2_DEPWINDOW_H

#include <QWidget>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class depWindow; }
QT_END_NAMESPACE

class depWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit depWindow(Controller& controller, QWidget *parent = nullptr);
    void update() override;
    ~depWindow() override;

private:
    Controller& controller;
    Ui::depWindow *ui;
    void populateList();
};


#endif //TEST2_DEPWINDOW_H
