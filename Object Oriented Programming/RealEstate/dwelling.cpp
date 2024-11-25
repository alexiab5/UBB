#include "dwelling.h"
#include <sstream>
Dwelling::Dwelling(double _price, bool _isProfitable): price(_price), isProfitable(_isProfitable){}

double Dwelling::getPrice() const {
    return this->price;
}

bool Dwelling::isDwellingProfitable() const {
    return this->isProfitable;
}

std::string Dwelling::toString() const {
    std::stringstream ss;
    ss << "Dwelling Price: " << this->price << " Is Profitable? " << this->isProfitable;
    return ss.str();
}


