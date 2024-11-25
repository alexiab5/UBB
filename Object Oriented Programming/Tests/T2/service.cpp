//
// Created by alexia on 23.04.2024.
//
#include "service.h"
#include <fstream>

Service::Service() {
    this->cars = std::vector<Car>();
    Engine* e1 = new TurboEngine();
    this->cars.push_back(Car{e1, 2});
    Engine* e2 = new ElectricEngine(10);
    this->cars.push_back(Car{e2, 2});
    Engine* e3 = new ElectricEngine(15);
    this->cars.push_back(Car{e3, 4});
}

std::vector<Car> Service::getAllCars() const {
    return this->cars;
}

Car Service::addCar(int numberOfDoors, std::string engineType, int autonomy) {
    Engine* e;
    if(engineType == "Electric"){
        e = new ElectricEngine(autonomy);
    }
    else{
        e = new TurboEngine();
    }
    Car c = Car{e, numberOfDoors};
    this->cars.push_back(c);
    return c;
}

std::vector<Car> Service::getCarsWithMaxPrice(double maxPrice) const {
    std::vector<Car> cars2;
    for(auto c : this->cars)
        if(c.ComputePrice() < maxPrice)
            cars2.push_back(c);
    return cars2;
}

void Service::writeToFile(std::string fileName, std::vector<Car> _cars) const {
    std::ofstream o(fileName);
    for(auto c : _cars)
        if(c.getNoDoors() == 2)
            o << c.toString() << std::endl;
    for(auto c : _cars)
        if(c.getNoDoors() == 4)
            o << c.toString() << std::endl;
    o.close();
}

//Service::~Service() {
//    for(auto c : this->cars)
//        delete c.getEngine();
//}



