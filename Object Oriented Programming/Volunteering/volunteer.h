//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_VOLUNTEER_H
#define TEST2_VOLUNTEER_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
class Volunteer{
private:
    std::string name, department, listOfInterests, email;
public:
    Volunteer(): name(""), department(""), listOfInterests(""), email(""){};
    Volunteer(std::string name, std::string email, std::string listOfInterests,  std::string department): name(name), department(department), listOfInterests(listOfInterests), email(email){};
    std::string getName() const{
        return name;
    }
    std::string getEmail() const{
        return email;
    }
    std::string getInterests() const{
        return listOfInterests;
    }
    std::string getDepartment() const{
        return department;
    }
    void setDepartment(std::string d){
        department = d;
    }
    friend std::istream& operator>>(std::istream &is, Volunteer& volunteer){
        std::string line;
        getline(is, line);
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> result;
        while(getline(ss, token, '|')){
            result.push_back(token);
        }
        if(result.size() != 4)
            return is;
        volunteer.name = result[0];
        volunteer.email = result[1];
        volunteer.listOfInterests = result[2];
        volunteer.department = result[3];
        return is;
    }
    friend std::ostream& operator<<(std::ostream &os, const Volunteer& volunteer){
        return os << volunteer.name << "|" << volunteer.email << "|" << volunteer.listOfInterests << "|" << volunteer.department << "|";
    }
};
#endif //TEST2_VOLUNTEER_H
