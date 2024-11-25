//
// Created by alexia on 26.06.2024.
//
#pragma once
#ifndef TEST4_BIOLOGIST_H
#define TEST4_BIOLOGIST_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Biologist{
private:
    std::string name, studiedSpecies;
public:
    Biologist(): name(""), studiedSpecies(""){}
    std::string getName() const{
        return name;
    }
    std::string getSpecies() const{
        return studiedSpecies;
    }
    friend std::istream& operator>>(std::istream &is, Biologist& b){
        std::string line, token;
        getline(is, line);
        std::stringstream ss(line);
        std::vector<std::string> res;
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 2)
            return is;
        b.name = res[0];
        b.studiedSpecies = res[1];
        return is;
    }
};
#endif //TEST4_BIOLOGIST_H
