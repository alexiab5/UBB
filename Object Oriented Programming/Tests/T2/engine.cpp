//
// Created by alexia on 23.04.2024.
//
#include "engine.h"
#include <sstream>

Engine::Engine() {
    this->basePrice = 3000;
}

double Engine::getPrice() const {
    return this->basePrice;
}

ElectricEngine::ElectricEngine(int _autonomy) : Engine(), autonomy(_autonomy) {}

double ElectricEngine::getPrice() const {
    return (this->basePrice + this->autonomy * 0.01);
}

std::string ElectricEngine::toString() const {
    std::stringstream ss;
    ss << "Electric Engine: Autonomy " << this->autonomy << " total price: " << this->getPrice();
    return ss.str();
}

TurboEngine::TurboEngine() : Engine() {}

double TurboEngine::getPrice() const {
    return (this->basePrice + 100);
}

std::string TurboEngine::toString() const {
    std::stringstream ss;
    ss << "Turbo Engine: total price: " << this->getPrice();
    return ss.str();
}
