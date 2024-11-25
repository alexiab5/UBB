//
// Created by alexia on 28.05.2024.
//
#pragma once
#ifndef OOP_T3_ALEXIAB5_SERVICE_H
#define OOP_T3_ALEXIAB5_SERVICE_H
#include "repository.h"
class Service{
private:
    Repository &repo;
public:
    Service(Repository & _repo);
    std::vector<Document> getAllService() const;
    std::vector<Document> getSorted() const;
    std::vector<Document> getMatchingDocuments(std::string key) const;
    double getSimilarity(Document doc, std::string key) const;
};
#endif //OOP_T3_ALEXIAB5_SERVICE_H
