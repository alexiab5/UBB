//
// Created by alexia on 26.05.2024.
//
#include "veggie.h"
#include <vector>

Vegetable::Vegetable(): family(""), name(""), part("") {}

Vegetable::Vegetable(std::string _family, std::string _name, std::string _part): family(_family), name(_name), part(_part) {}

std::string Vegetable::getName() const {
    return this->name;
}

std::string Vegetable::getFamily() const {
    return this->family;
}

std::string Vegetable::getPart() const {
    return this->part;
}

std::ostream &operator<<(std::ostream &os, const Vegetable &vegetable) {
    return os << vegetable.family << "|" << vegetable.name << "|" << vegetable.part;
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

std::istream &operator>>(std::istream &is, Vegetable &vegetable) {
    std::string line;
    std::getline(is, line);
    std::vector<std::string> res = tokenize(line, '|');
    if(res.size() != 3)
        return is;
    vegetable.family = res[0];
    vegetable.name = res[1];
    vegetable.part = res[2];
    return is;
}


