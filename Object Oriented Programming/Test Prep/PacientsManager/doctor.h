//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_DOCTOR_H
#define TEST3_DOCTOR_H
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
class Doctor{
private:
    std::string name, specialisation;
public:
    Doctor(): name(""), specialisation(""){};
    Doctor(std::string name, std::string specialisarion): name(name), specialisation(specialisarion){};
    std::string getName() const{
        return name;
    }
    std::string getSpecialisation() const{
        return specialisation;
    }
    friend std::istream& operator>>(std::istream &is, Doctor& doctor){
        std::string line;
        std::getline(is, line);
        std::string token;
        std::stringstream ss(line);
        std::vector<std::string> res;
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 2)
            return is;
        doctor.name = res[0];
        doctor.specialisation = res[1];
        return is;
    }
};
#endif //TEST3_DOCTOR_H
