//
// Created by alexia on 26.06.2024.
//
#pragma once
#ifndef TEST4_BACTERIA_H
#define TEST4_BACTERIA_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Bacterium{
private:
    std::string name, species, diseases;
    int size;
public:
    Bacterium(): name(""), species(""), diseases(""), size(0){}
    Bacterium(std::string name, std::string species, std::string diseases, int size): name(name), species(species), diseases(diseases), size(size){}
    std::string getName() const{
        return name;
    }
    std::string getSpecies() const{
        return species;
    }
    std::string getDiseases() const{
        return diseases;
    }
    void setName(std::string newName){
        name = newName;
    }
    void setSpecies(std::string newSpecies){
        species = newSpecies;
    }
    void setDiseases(std::string newDiseases){
        diseases = newDiseases;
    }
    void setSpecies(int newSize){
        size = newSize;
    }
    void addDisease(std::string disease){
        diseases += disease;
    }
    int getSize() const{
        return size;
    }
    friend std::ostream& operator<<(std::ostream &os, const Bacterium& b){
        return os << b.name << "|" << b.species << "|" << b.size << "|" << b.diseases;
    }
    friend std::istream& operator>>(std::istream &is, Bacterium& b){
        std::string line, token;
        getline(is, line);
        std::stringstream ss(line);
        std::vector<std::string> res;
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 4)
            return is;
        b.name = res[0];
        b.species = res[1];
        b.size = stoi(res[2]);
        b.diseases = res[3];
        return is;
    }
};
#endif //TEST4_BACTERIA_H
