//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_CONTROLLER_H
#define TEST3_CONTROLLER_H
#include "repository.h"
#include "observer.h"
#include <vector>
class Controller: public Subject{
private:
    DoctorsRepository& doctors;
    PacientsRepository& pacients;
public:
    Controller(DoctorsRepository& doctors, PacientsRepository& pacients): doctors(doctors), pacients(pacients){};
    std::vector<Doctor> getDoctors() const{
        return doctors.getAll();
    }
    std::vector<Pacient> getPacients() const{
        return pacients.getAll();
    }
    std::vector<Pacient> getPacientsBySpecialisation(std::string specialisation) const;
    std::vector<std::string> getSpecialisations() const;
    void addPacient(Pacient& pacient);
    void updateDiagnosis(Pacient& p, std::string diagnosis);
    void updateSpecialisation(Pacient& p, std::string specialisation);
};
#endif //TEST3_CONTROLLER_H
