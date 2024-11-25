//
// Created by alexia on 23.04.2024.
//
#pragma once
#ifndef OOP_T2_ALEXIAB5_ENGINE_H
#define OOP_T2_ALEXIAB5_ENGINE_H
#include <string>
#endif //OOP_T2_ALEXIAB5_ENGINE_H

class Engine{
protected:
    double basePrice;
public:
    Engine();
    virtual double getPrice() const;
    virtual std::string toString() const = 0;
    virtual ~Engine(){};
};

class ElectricEngine: public Engine{
private:
    int autonomy;
public:
    ElectricEngine(int _autonomy);
    double getPrice() const override;
    std::string toString() const override;
};

class TurboEngine: public Engine{
public:
    TurboEngine();
    double getPrice() const override;
    std::string toString() const override;
};