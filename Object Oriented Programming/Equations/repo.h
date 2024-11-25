#pragma once
#include "equation.h"
#include <vector>
#include <fstream>

class Repository{
private:
    std::vector<Equation> equations;
    void load();
public:
    Repository();
    int getSize() const;
    std::vector<Equation> getAll() const;
    void addEquation(Equation eq);
};