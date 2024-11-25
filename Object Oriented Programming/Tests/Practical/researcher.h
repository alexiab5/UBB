//
// Created by alexia on 27.06.2024.
//
#pragma once
#ifndef OOP_E_912_914_ALEXIAB5_RESEARCHER_H
#define OOP_E_912_914_ALEXIAB5_RESEARCHER_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Researcher{
private:
    std::string name, position;
public:
    Researcher(): name(""), position(""){}
    Researcher(std::string name, std::string position): name(name), position(position){}
    std::string getName() const{
        return name;
    }
    std::string getPosition() const{
        return position;
    }
    friend std::istream& operator>>(std::istream &is, Researcher& r){
        std::string file, token;
        std::getline(is, file);
        std::vector<std::string> res;
        std::stringstream ss(file);
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 2)
            return is;
        r.name = res[0];
        r.position = res[1];
        return is;
    }
};
#endif //OOP_E_912_914_ALEXIAB5_RESEARCHER_H
