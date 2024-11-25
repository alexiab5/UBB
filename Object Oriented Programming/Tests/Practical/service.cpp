//
// Created by alexia on 27.06.2024.
//
#include "service.h"
#include <fstream>
#include <algorithm>

void Service::loadResearchers() {
    std::ifstream file("r.txt", std::ios::in);
    if(file.is_open()){
        Researcher r;
        while(file >> r){
            researchers.push_back(r);
        }
        file.close();
    }
}

void Service::loadIdeas() {
    std::ifstream file("i.txt", std::ios::in);
    if(file.is_open()){
        Idea r;
        while(file >> r){
            ideas.push_back(r);
        }
        file.close();
    }
}

void Service::addIdea(Idea &idea) {
    this->ideas.push_back(idea);
}

void Service::acceptIdea(Idea i) {
    auto it = ideas.begin();
    while(it != ideas.end()) {
        if(it->getCreator() == i.getCreator() && it->getDescription() == i.getDescription()) {
            it->setStatus("accepted");
            break;
        }
    }
}

void Service::saveAcceptedIdeas() {
    std::ofstream file("accepted.txt");
    if(file.is_open()) {
        std::vector<Idea> accepted;
        std::copy_if(ideas.begin(), ideas.end(), std::back_inserter(accepted), [](Idea i){return i.getStatus() == "accepted";});
        std::sort(accepted.begin(), accepted.end(), [](const Idea& i1, const Idea &i2){return i1.getDuration() < i2.getDuration();});
        for (auto i: accepted) {
            std::stringstream ss;
            ss << i.getTitle() << " [" << i.getCreator() << "] " << i.getDuration() << " " << i.getDescription();
            file << ss.str() << std::endl;
        }
    }
}

std::vector<Idea> Service::getAcceptedIdeasForResearcher(Researcher r) {
    std::vector<Idea> accepted;
    std::copy_if(ideas.begin(), ideas.end(), std::back_inserter(accepted), [&r](Idea i)
            {return i.getStatus() == "accepted" && i.getCreator() == r.getName();});
    return accepted;
}

void Service::saveIdeasForResearcher(Researcher r) {
    auto ids = this->getAcceptedIdeasForResearcher(r);
    for(auto s : ids){
        std::string name = s.getTitle();
        std::ofstream file(name);
        if(file.is_open()) {
            std::stringstream ss;
            ss << s.getTitle() << " [" << s.getCreator() << "] " << s.getDuration() << " " << s.getDescription();
            file << ss.str() << std::endl;
        }
    }
}
