//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_REPOSITORY_H
#define TEST3_REPOSITORY_H
#include "doctor.h"
#include "pacient.h"
#include <vector>
#include <algorithm>
class DoctorsRepository{
private:
    std::vector<Doctor> doctors;
public:
    DoctorsRepository(){
        load();
    }
    void load(){
        std::ifstream file("doctors.txt", std::ios::in);
        if(file.is_open()){
            Doctor d;
            while(file >> d){
                doctors.push_back(d);
            }
            file.close();
        }
    }
    std::vector<Doctor> getAll() const{
        return doctors;
    }
};

class PacientsRepository{
private:
    std::vector<Pacient> pacients;
public:
    PacientsRepository(){
        load();
    }
    void load(){
        std::ifstream file("pacients.txt", std::ios::in);
        if(file.is_open()){
            Pacient p;
            while(file >> p){
                pacients.push_back(p);
            }
            file.close();
        }
    }
    void save(){
        std::ofstream file("pacients.txt");
        if(file.is_open()){
            for(auto p : pacients)
                file << p << std::endl;
            file.close();
        }
    }
    std::vector<Pacient> getAll() const{
        return pacients;
    }
    void add(Pacient& pacient){
        pacients.push_back(pacient);
        save();
    }
    void updateSpecialisation(Pacient &pacient, std::string specialisation){
        std::string name = pacient.getName();
        auto it = std::find_if(pacients.begin(), pacients.end(), [&name](Pacient& p){return p.getName() == name;});
        if(it != pacients.end()) {
            int index = it - pacients.begin();
            pacients[index].setSpecialisation(specialisation);
        }
        save();
    }
    void updateDiagnosis(Pacient &pacient, std::string diagnosis){
        std::string name = pacient.getName();
        auto it = std::find_if(pacients.begin(), pacients.end(), [&name](Pacient& p){return p.getName() == name;});
        if(it != pacients.end()) {
            int index = it - pacients.begin();
            pacients[index].setDiagnosis(diagnosis);
        }
        save();
    }
};
#endif //TEST3_REPOSITORY_H
