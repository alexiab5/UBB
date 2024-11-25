//
// Created by alexia on 26.05.2024.
//

#pragma once
#ifndef TESTQT3_REPOSITORY_H
#include "veggie.h"
#include <vector>
#define TESTQT3_REPOSITORY_H
class Repository{
private:
    std::vector<Vegetable> vegetables;
    std::string fileName;
    void save();
    void load();
public:
    Repository(std::string _fileName="vegetables.txt");
    std::vector<Vegetable> getAll() const;
    std::vector<Vegetable> getAllByFamily(std::string familyName) const;
    std::vector<std::string> getAllFamilies() const;
    Vegetable searchVegetableByName(std::string name) const;
    int getSize() const;
};
#endif //TESTQT3_REPOSITORY_H
