//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_REPOSITORY_H
#define TEST2_REPOSITORY_H
#include "department.h"
#include "volunteer.h"
#include <vector>
#include <fstream>
class DepartmentsRepository{
private:
    std::vector<Department> departments;
    std::string fileName;
public:
    DepartmentsRepository(std::string fileName): fileName(fileName){
        load();
    };
    void load(){
        std::ifstream file(fileName, std::ios::in);
        if(file.is_open()){
            Department d;
            while(file >> d){
                departments.push_back(d);
            }
            file.close();
        }
    }
    std::vector<Department> getAll() const{
        return departments;
    }
};

class VolunteersRepository{
private:
    std::vector<Volunteer> volunteers;
    std::string fileName;
public:
    VolunteersRepository(std::string fileName): fileName(fileName){
        load();
    };
    void load(){
        std::ifstream file(fileName, std::ios::in);
        if(file.is_open()){
            Volunteer d;
            while(file >> d){
                volunteers.push_back(d);
            }
            file.close();
        }
    }
    void save(){
        std::ofstream file(fileName);
        if(file.is_open()) {
            for (auto vol: volunteers){
                file << vol << std::endl;
            }
            file.close();
        }
    }
    void add(Volunteer& v);
    void changeDepartment(int index, std::string department);
    std::vector<Volunteer> getAll() const;
};
#endif //TEST2_REPOSITORY_H
