#include "ui.h"
#include <iostream>

ConsoleUI::ConsoleUI(RealEstateAgency *agency): agency(agency) {}

void ConsoleUI::startConsoleUI() {
    while (true){
        std::cout << "================= Welcome to the Real Estate Agency Manager App ==================" << std::endl;
        std::cout << "1. Remove a client\n2. Show all clients and dwellings\n3. Add a dwelling\n4. Save clients to a file.\n5. Exit" << std::endl;
        std::cout << ">>> ";
        int option;
        std::cin >> option;
        std::cin.ignore();
        if(option == 1){
            this->removeClientUI();
        }
        else if(option == 2){
            this->showAllClientsAndDwellings();
        }
        else if(option == 3){
            this->addDwellingUI();
        }
        else if(option == 4){
            this->writeToFileUI();
        }
        else if(option == 5){
            std::cout << "Goodbye!";
            break;
        }
        else{
            std::cout << "Invalid option!" << std::endl;
        }
    }
}

void ConsoleUI::addDwellingUI() {
    std::string profitable;
    bool p = false;
    double price;
    std::cout << "Price of the dwelling: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Is the dwelling profitable (y/n): ";
    std::getline(std::cin, profitable);
    if(profitable == "y")
        p = true;
    Dwelling d = this->agency->addDwelling(price, p);
    std::vector<Client*> clients = this->agency->getInterestedClients(d);
    for(auto c : clients){
        std::cout << c->toString() << std::endl;
    }
}

void ConsoleUI::removeClientUI() {
    std::string name;
    std::cout << "Client's name: ";
    std::getline(std::cin, name);
    this->agency->removeClient(name);
    try {
        std::cout << "Client successfully removed";
    }
    catch(...){
        std::cout << "Error removing client";
    }
}

void ConsoleUI::writeToFileUI() {
    std::string fname;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, fname);
    this->agency->writeToFile(fname);

}

void ConsoleUI::showAllClientsAndDwellings() {
    std::cout << "Current clients: " << std::endl;
    std::vector<Client*> clients = this->agency->getClients();
    for(auto c : clients){
        std::cout << c->toString() << std::endl;
    }
    std::cout << "Current dwellings: " << std::endl;
    std::vector<Dwelling> dwellings = this->agency->getDwellings();
    for(auto c : dwellings){
        std::cout << c.toString() << std::endl;
    }
}



