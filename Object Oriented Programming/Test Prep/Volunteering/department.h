//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_DEPARTMENT_H
#define TEST2_DEPARTMENT_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
class Department{
private:
    std::string name, description;
public:
    Department(): name(""), description(""){};
    Department(std::string name, std::string description): name(name), description(description){};
    std::string getName() const{
        return name;
    }
    std::string getDescription() const{
        return description;
    }
    friend std::istream& operator>>(std::istream &is, Department& department){
        std::string line;
        getline(is, line);
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> result;
        while(getline(ss, token, '|')){
            result.push_back(token);
        }
        if(result.size() != 2)
            return is;
        department.name = result[0];
        department.description = result[1];
        return is;
    }
};
#endif //TEST2_DEPARTMENT_H
