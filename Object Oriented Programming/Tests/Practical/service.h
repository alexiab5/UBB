//
// Created by alexia on 27.06.2024.
//
#pragma once
#ifndef OOP_E_912_914_ALEXIAB5_SERVICE_H
#define OOP_E_912_914_ALEXIAB5_SERVICE_H
#include "researcher.h"
#include "ideas.h"
#include <vector>
class Service{
private:
    std::vector<Researcher> researchers;
    std::vector<Idea> ideas;
    void loadResearchers();
    void loadIdeas();
public:
    Service(){
        loadResearchers();
        loadIdeas();
    }
    std::vector<Researcher> getResearchers(){
        return researchers;
    }
    std::vector<Idea> getIdeas(){
        return ideas;
    }
    void addIdea(Idea &idea);
    void saveAcceptedIdeas();
    void saveIdeasForResearcher(Researcher r);
    void acceptIdea(Idea i);
    std::vector<Idea> getAcceptedIdeasForResearcher(Researcher r);
};
#endif //OOP_E_912_914_ALEXIAB5_SERVICE_H
