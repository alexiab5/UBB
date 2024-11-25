//
// Created by alexia on 23.04.2024.
//
#include "ui.h"
#include <iostream>
ConsoleUI::ConsoleUI() {
    this->service = Service{};
}

void ConsoleUI::startUI() {
    while(true){
        std::cout << "1. Add a car.\n2. Show all cars.\n3. Save all cars with price less maxPrice to a file.\n4. EXIT." << std::endl;
        std::cout << ">>>";
        int option;
        std::cin >> option;
        if(option == 1) {
            std::string engine;
            int noDoors, autonomy = 0;
            std::cout << "How many doors does the car have? (2/4) >>> ";
            std::cin >> noDoors;
            std::cout << "What is the type of the engine? (Electric / Turbo) >>> ";
            std::cin >> engine;
            if (engine == "Electric") {
                std::cout << "What is the autonomy of the engine? >>> ";
                std::cin >> autonomy;
            }
            Car c =this->service.addCar(noDoors, engine, autonomy);
            std::cout << c.toString() << std::endl;
        }
        else if(option == 2){
            std::vector<Car> cars = this->service.getAllCars();
            for(auto c : cars)
                std::cout << c.toString() << std::endl;
        }
        else if(option == 3){
            std::string fileName;
            double maxPrice;
            std::cout << "Enter the name of the file: ";
            std::cin >> fileName;
            std::cout << "Enter the max price: ";
            std::cin >> maxPrice;
            std::vector<Car> cars = this->service.getCarsWithMaxPrice(maxPrice);
            this->service.writeToFile(fileName, cars);
        }
        else if(option == 4){
            break;
        }
    }
}

