//
// Created by alexia on 28.05.2024.
//
#pragma once

#ifndef OOP_T3_ALEXIAB5_REPOSITORY_H
#define OOP_T3_ALEXIAB5_REPOSITORY_H
#include "domain.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class Repository{
private:
    std::vector<Document> documents;
public:
    Repository();
    std::vector<Document> getAll() const;
};
#endif //OOP_T3_ALEXIAB5_REPOSITORY_H
