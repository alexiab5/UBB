//
// Created by alexia on 24.06.2024.
//
#include "controller.h"

void Controller::addPacient(Pacient &pacient) {
    this->pacients.add(pacient);
    this->notify();
}

void Controller::updateDiagnosis(Pacient &p, std::string diagnosis) {
    this->pacients.updateDiagnosis(p, diagnosis);
    this->notify();
}

void Controller::updateSpecialisation(Pacient &p, std::string specialisation) {
    this->pacients.updateSpecialisation(p, specialisation);
    this->notify();
}

std::vector<Pacient> Controller::getPacientsBySpecialisation(std::string specialisation) const {
    std::vector<Pacient> sorted;
    std::vector<Pacient> current = pacients.getAll();
    std::copy_if(current.begin(), current.end(), std::back_inserter(sorted), [&specialisation](Pacient &p){return p.getSpecialisation() == specialisation;});
    return sorted;
}

std::vector<std::string> Controller::getSpecialisations() const {
    std::vector<std::string> specialisations;
    auto pac = pacients.getAll();
    for(auto p : pac){
        std::string s = p.getSpecialisation();
        auto it = std::find(specialisations.begin(), specialisations.end(), s);
            specialisations.push_back(p.getSpecialisation());
    }
    return specialisations;
}

