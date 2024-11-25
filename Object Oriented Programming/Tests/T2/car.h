//
// Created by alexia on 23.04.2024.
//
#pragma once
#ifndef OOP_T2_ALEXIAB5_CAR_H
#define OOP_T2_ALEXIAB5_CAR_H
#include "engine.h"
#endif //OOP_T2_ALEXIAB5_CAR_H

class Car{
private:
    int numberOfDoors;
    Engine* engine;
public:
    Car(Engine* _engine, int _numberOfDoors);
    double ComputePrice() const;
    std::string toString() const;
    int getNoDoors() const;
    Engine* getEngine() const;
};