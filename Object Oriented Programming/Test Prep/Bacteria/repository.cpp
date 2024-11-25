//
// Created by alexia on 26.06.2024.
//
#include "repository.h"
#include <algorithm>

std::vector<Bacterium> Repository::getBacteriaForBiologist(const Biologist &b) {
    std::stringstream ss(b.getSpecies());
    std::string spec;
    std::vector<Bacterium> res;
    while(getline(ss, spec, ' ')){
        std::copy_if(bacteria.begin(), bacteria.end(), std::back_inserter(res), [&spec](Bacterium &b){
            return b.getSpecies() == spec;
        });
    }
    return res;
}

void Repository::addBacterium(Bacterium &b) {
    auto it = std::find_if(bacteria.begin(), bacteria.end(), [&b](Bacterium &bact){return b.getName() == bact.getName() && b.getSpecies() == bact.getSpecies();});
    if(it != bacteria.end())
        throw std::invalid_argument("Invalid bacterium!");
    this->bacteria.push_back(b);
}
