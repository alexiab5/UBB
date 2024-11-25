//
// Created by alexia on 26.05.2024.
//
#include "task.h"
#include <vector>
#include <sstream>

Task::Task(): description(""), duration(0), priority(0) {

}

Task::Task(std::string _description, int _duration, int _priority): description(_description), duration(_duration), priority(_priority) {

}

int Task::getDuration() const {
    return this->duration;
}

int Task::getPriority() const {
    return this->priority;
}

std::string Task::getDescription() const {
    return this->description;
}

std::vector<std::string> tokenize(std::string str, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);
    while(std::getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

std::istream &operator>>(std::istream &is, Task &task) {
    std::string line;
    std::getline(is, line);
    auto v = tokenize(line, '|');
    if(v.size() != 3)
        return is;
    task.description = v[0];
    task.priority = stoi(v[2]);
    task.duration = stoi(v[1]);
    return is;
}


