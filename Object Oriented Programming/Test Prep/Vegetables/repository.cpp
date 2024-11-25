//
// Created by alexia on 26.05.2024.
//
#include "repository.h"
#include <fstream>
#include <algorithm>

Repository::Repository(std::string _fileName): fileName(_fileName) {
    this->vegetables = std::vector<Vegetable>();
    this->load();
}

void Repository::load() {
    std::ifstream file(this->fileName, std::ios::in);
    if(!file.is_open())
        throw std::exception();
    Vegetable v;
    while(file >> v){
        this->vegetables.push_back(v);
    }
    file.close();
}

std::vector<Vegetable> Repository::getAllByFamily(std::string familyName) const {
    std::vector<Vegetable> res;
    std::copy_if(this->vegetables.begin(), this->vegetables.end(), std::back_inserter(res),
                 [&familyName](const Vegetable& v){return v.getFamily() == familyName;});
    return res;
}

void Repository::save() {
    std::ofstream file(this->fileName);
    if(!file.is_open())
        throw std::exception();
    for(const auto& v : this->vegetables)
        file << v << "\n";
    file.close();
}

int Repository::getSize() const {
    return this->vegetables.size();
}

std::vector<std::string> Repository::getAllFamilies() const {
    std::vector<std::string> res;
    res.push_back(this->vegetables[0].getFamily());
    for(const auto& v : this->vegetables){
        std::string family = v.getFamily();
        auto it = std::find_if(res.begin(), res.end(),
                               [&family](const std::string &s){return s == family;});
        if(it == res.end())
            res.push_back(family);
    }
    return res;
}

std::vector<Vegetable> Repository::getAll() const {
    return this->vegetables;
}

Vegetable Repository::searchVegetableByName(std::string name) const {
    auto it = std::find_if(this->vegetables.begin(), this->vegetables.end(),
                           [&name](const Vegetable& v){return v.getName() == name;});
    if(it != this->vegetables.end())
        return *it;
    throw std::exception();
}
