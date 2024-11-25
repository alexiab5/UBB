//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_PACIENT_H
#define TEST3_PACIENT_H
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
class Pacient{
private:
    std::string name, specialisation, diagnosis, admissionDate, currentDoctor;
public:
    Pacient(): name(""), specialisation(""), diagnosis("undiagnosed"), currentDoctor(""), admissionDate(""){};
    Pacient(std::string name, std::string admissionDate, std::string diagnosis="undiagnosed", std::string specialisation="", std::string currentDoctor=""):
        name(name), specialisation(specialisation), admissionDate(admissionDate), currentDoctor(currentDoctor), diagnosis(diagnosis){};
    std::string getName() const{
        return name;
    }
    std::string getSpecialisation() const{
        return specialisation;
    }
    std::string getAdmissionDate() const{
        return admissionDate;
    }
    std::string getDiagnosis() const{
        return diagnosis;
    }
    std::string getCurrentDoctor() const{
        return currentDoctor;
    }
    void setSpecialisation(std::string s){
        specialisation = s;
    }
    void setDiagnosis(std::string d){
        diagnosis = d;
    }
    friend std::istream& operator>>(std::istream &is, Pacient& pacient){
        std::string line;
        std::getline(is, line);
        std::string token;
        std::stringstream ss(line);
        std::vector<std::string> res;
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 5)
            return is;
        pacient.name = res[0];
        pacient.admissionDate = res[1];
        pacient.diagnosis = res[2];
        pacient.specialisation = res[3];
        pacient.currentDoctor = res[4];
        return is;
    }
    friend std::ostream& operator<<(std::ostream &os, const Pacient& pacient) {
        return os << pacient.name << "|" << pacient.admissionDate << "|" << pacient.diagnosis << "|" << pacient.specialisation << "|" << pacient.currentDoctor << "|";
    }
};
#endif //TEST3_PACIENT_H
