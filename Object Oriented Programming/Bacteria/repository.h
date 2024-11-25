//
// Created by alexia on 26.06.2024.
//
#pragma once
#ifndef TEST4_REPOSITORY_H
#define TEST4_REPOSITORY_H
#include "biologist.h"
#include "bacteria.h"
#include <fstream>

class Repository{
private:
    std::vector<Bacterium> bacteria;
    std::vector<Biologist> biologists;
public:
    Repository(){
        loadBiologists();
        loadBacteria();
    }
    std::vector<Bacterium> getBacteria(){
        return bacteria;
    };
    std::vector<Biologist> getBiologists(){
        return biologists;
    }
    void updateBacterium(Bacterium& oldBacterium, Bacterium& newBacterium);
    std::vector<Bacterium> getBacteriaForBiologist(const Biologist& b);
    void loadBiologists(){
        std::ifstream file("biologists.txt", std::ios::in);
        if(file.is_open()){
            Biologist b;
            while(file >> b){
                biologists.push_back(b);
            }
            file.close();
        }
    }
    void loadBacteria(){
        std::ifstream file("bacteria.txt", std::ios::in);
        if(file.is_open()){;
            Bacterium b;
            while (file >> b){
                bacteria.push_back(b);
            }
            file.close();
        }
    }
    void saveBacteria(){
        std::ofstream file("bacteria.txt");
        if(file.is_open()) { ;
            for (auto b: bacteria)
                file << b << std::endl;
        }
        file.close();
    }
    void addBacterium(Bacterium& b);
};
#endif //TEST4_REPOSITORY_H
