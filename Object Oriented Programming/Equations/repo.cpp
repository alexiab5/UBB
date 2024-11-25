#include "repo.h"

Repository::Repository() {
    this->equations = std::vector<Equation>();
    this->load();
}

int Repository::getSize() const {
    return this->equations.size();
}

std::vector<Equation> Repository::getAll() const {
    return this->equations;
}

void Repository::addEquation(Equation eq) {
    this->equations.push_back(eq);
}

void Repository::load() {
    std::ifstream file("eq.txt", std::ios::in);
    if(!file.is_open())
        throw std::exception();
    Equation eq;
    while(file >> eq){
        equations.push_back(eq);
    }
    file.close();
}


