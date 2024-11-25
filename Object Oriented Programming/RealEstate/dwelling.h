#pragma once
#ifndef T2_2_DWELLING_H
#define T2_2_DWELLING_H
#include <string>
#endif //T2_2_DWELLING_H

class Dwelling{
private:
    double price;
    bool isProfitable;
public:
    Dwelling(double _price, bool _isProfitable);
    double getPrice() const;
    bool isDwellingProfitable() const;
    std::string toString() const;
};