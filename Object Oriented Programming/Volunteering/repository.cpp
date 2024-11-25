//
// Created by alexia on 24.06.2024.
//
#include "repository.h"

std::vector<Volunteer> VolunteersRepository::getAll() const {
    return volunteers;
}

void VolunteersRepository::add(Volunteer &v) {
    volunteers.push_back(v);
    this->save();
}

void VolunteersRepository::changeDepartment(int index, std::string department) {
    this->volunteers[index].setDepartment(department);
    this->save();
}

