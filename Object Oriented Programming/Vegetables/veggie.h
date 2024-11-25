//
// Created by alexia on 26.05.2024.
//

#pragma once
#ifndef TESTQT3_VEGGIE_H
#include <string>
#include <fstream>
#include <sstream>
#define TESTQT3_VEGGIE_H
class Vegetable{
private:
    std::string name;
    std::string part;
    std::string family;
public:
    Vegetable();
    Vegetable(std::string _family, std::string _name, std::string _part);
    std::string getName() const;
    std::string getFamily() const;
    std::string getPart() const;

    friend std::ostream &operator<<(std::ostream& os, const Vegetable& vegetable);
    friend std::istream &operator>>(std::istream& is, Vegetable& vegetable);
};
#endif //TESTQT3_VEGGIE_H
