#include <iostream>
#include "ui.h"

void deleteClients(const std::vector<Client*> clients){
    for(auto c : clients)
        delete c;
}
int main() {
    std::vector<Dwelling> dwellings;
    dwellings.push_back({800000, true});
    dwellings.push_back({1000000, false});
    std::vector<Client*> clients;
    Client* c1 = new Person{"Alexia Ioana", 100000};
    clients.push_back(c1);
    Client* c2 = new Company{"BlaBla Dufenschmirtz", 90000000, 100000};
    clients.push_back(c2);
    RealEstateAgency* a = new RealEstateAgency{dwellings, clients};
    ConsoleUI ui{a};
    ui.startConsoleUI();
    deleteClients(clients);
    return 0;
}
