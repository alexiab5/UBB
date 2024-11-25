//
// Created by alexia on 26.05.2024.
//
#include "repository.h"
#include <fstream>

Repository::Repository(std::string _fileName): fileName(_fileName) {
    this->tasks = std::vector<Task>();
    this->load();
}

void Repository::load() {
    std::ifstream file(this->fileName, std::ios::in);
    if(!file.is_open())
        throw std::exception();
    Task t;
    while(file >> t){
        this->tasks.push_back(t);
    }
    file.close();
}

std::vector<Task> Repository::getAll() const {
    return this->tasks;
}

int Repository::calculateDurationForTasks(int priority) const {
    int sum = 0;
    for(const auto& t : tasks){
        if(t.getPriority() == priority)
            sum += t.getDuration();
    }
    return sum;
}


