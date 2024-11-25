//
// Created by alexia on 23.04.2024.
//

#ifndef OOP_T2_ALEXIAB5_SERVICE_H
#define OOP_T2_ALEXIAB5_SERVICE_H
#include "car.h"
#include <vector>
#endif //OOP_T2_ALEXIAB5_SERVICE_H

class Service{
private:
    std::vector<Car> cars;
public:
    Service();
    Car addCar(int numberOfDoors, std::string engineType, int autonomy=0);
    std::vector<Car> getAllCars() const;
    std::vector<Car> getCarsWithMaxPrice(double maxPrice) const;
    void writeToFile(std::string fileName, std::vector<Car> _cars) const;
    //~Service();
};