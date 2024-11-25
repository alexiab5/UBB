//
// Created by alexia on 23.04.2024.
//
#include "car.h"
#include <sstream>

Car::Car(Engine *_engine, int _numberOfDoors): engine(_engine), numberOfDoors(_numberOfDoors) {}

double Car::ComputePrice() const {
    if(this->numberOfDoors == 2)
        return 7000 + this->engine->getPrice();
    else if(this->numberOfDoors == 4)
        return 8500 + this->engine->getPrice();
}

std::string Car::toString() const {
    std::stringstream ss;
    ss << "Car with " << this->numberOfDoors << " doors " << this->engine->toString() << " Total Car Price: " << this->ComputePrice();
    return ss.str();
}

int Car::getNoDoors() const {
    return this->numberOfDoors;
}

Engine *Car::getEngine() const {
    return this->engine;
}

