//
// Created by alexia on 28.05.2024.
//
#include "repository.h"

Repository::Repository() {
    this->documents = std::vector<Document>();
    std::ifstream file("documents.txt");
    if(!file.is_open())
        throw std::exception();
    Document d;
    while(file >> d){
        documents.push_back(d);
    }
    file.close();
}

std::vector<Document> Repository::getAll() const {
    return this->documents;
}


