//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_WINDOW_H
#define TEST3_WINDOW_H
#include "controller.h"
#include <QWidget>
#include "statisticswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget, public Observer {
Q_OBJECT

public:
    explicit Window(Controller &c, Doctor d, QWidget *parent = nullptr);
    void update() override;
    ~Window() override;

private:
    Ui::Window *ui;
    Controller& controller;
    Doctor doctor;
    std::vector<Pacient> pacientsOnDisplay;
    void populateList();
    void connectButtons();
public slots:
    void addButtonClicked();
    void updateSpecialisationButtonClicked();
    void updateDiagnosisButtonClicked();
    void checkBoxChanged();
};


#endif //TEST3_WINDOW_H
