//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST3_OBSERVER_H
#define TEST3_OBSERVER_H
#include <vector>
#include <algorithm>

class Observer{
public:
    virtual void update() = 0;
    virtual ~Observer(){};
};

class Subject{
private:
    std::vector<Observer*> observers;
public:
    virtual ~Subject(){};
    void addObserver(Observer* obs){
        observers.push_back(obs);
    }
    void removeObserver(Observer* obs){
        auto it = std::find(observers.begin(), observers.end(), obs);
        if(it != observers.end()){
            observers.erase(it);
        }
    }
    void notify(){
        for(auto obs : observers){
            obs->update();
        }
    }
};
#endif //TEST3_OBSERVER_H
