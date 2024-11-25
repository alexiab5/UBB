//
// Created by alexia on 28.05.2024.
//
#include "equation.h"
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

Equation::Equation() {
    a = b = c = 0;
}

Equation::Equation(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}

double Equation::getA() const {
    return a;
}

double Equation::getB() const {
    return b;
}

double Equation::getC() const {
    return c;
}

std::vector<std::string> tokenize(std::string str, char delimiter){
    std::vector<std::string> res;
    std::string token;
    std::stringstream ss(str);
    while(std::getline(ss, token, delimiter)){
        res.push_back(token);
    }
    return res;
}


std::istream &operator>>(std::istream &is, Equation &eq) {
    std::string line;
    std::getline(is, line);
    auto res = tokenize(line, ',');
    if(res.size() != 3)
        return is;
    eq.a = std::stod(res[0]);
    eq.b = std::stod(res[1]);
    eq.c = std::stod(res[2]);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Equation &eq) {
    if(eq.a != 0) {
        if(eq.a == 1)
            os <<"x^2";
        else
            os << eq.a << "x^2";
    }
    if(eq.b != 0){
        if(eq.b > 0)
            os << "+";
        if(eq.b == 1)
            os <<"x";
        else
            os << eq.b << "x";
    }
    if(eq.c != 0){
        if(eq.c > 0)
            os << "+";
        os << eq.c;
    }
    return os;
}

bool Equation::hasRealSolutions() const {
    return this->computeDiscriminant() >= 0;
}

double Equation::computeDiscriminant() const {
    return pow(this->b,2) - 4 * this->a * this->c;
}

