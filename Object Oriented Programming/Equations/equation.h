//
// Created by alexia on 28.05.2024.
//
#pragma once
#ifndef TESTQT5_EQUATION_H
#define TESTQT5_EQUATION_H
#include <iostream>
class Equation{
private:
    double a,b,c;
public:
    Equation();
    Equation(double a, double b, double c);
    double getA() const;
    double getB() const;
    double getC() const;
    bool hasRealSolutions() const;
    double computeDiscriminant() const;

    friend std::ostream &operator<<(std::ostream &os, const Equation& eq);
    friend std::istream &operator>>(std::istream &is, Equation& eq);
};
#endif //TESTQT5_EQUATION_H
