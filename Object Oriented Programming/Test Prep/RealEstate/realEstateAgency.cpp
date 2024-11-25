#include "realEstateAgency.h"
#include <fstream>

RealEstateAgency::RealEstateAgency(const std::vector<Dwelling> _dwellings, const std::vector<Client *> _clients): dwellings(_dwellings), clients(_clients) {}

void RealEstateAgency::removeClient(std::string name) {
    std::vector<Client*>::iterator it;
    for(it = this->clients.begin(); it != this->clients.end(); it++){
        if((*it)->getName() == name)
            break;
    }
    if(it != this->clients.end())
        this->clients.erase(it);
    else
        throw std::string {"The client does not exist"};
}

Dwelling RealEstateAgency::addDwelling(double price, bool isProfitable) {
    Dwelling d{price, isProfitable};
    this->dwellings.push_back(d);
    return d;
}

std::vector<Client *> RealEstateAgency::getInterestedClients(Dwelling d) const {
    std::vector<Client*> c;
    for(auto client : this->clients){
        if(client->isInterested(d))
            c.push_back(client);
    }
    return c;
}

void RealEstateAgency::writeToFile(std::string fileName) const {
    std::ofstream o(fileName);
    for(auto c : this->clients){
        o << c->toString() << std::endl;
    }
    o.close();
}

std::vector<Client *> RealEstateAgency::getClients() const {
    return this->clients;
}

std::vector<Dwelling> RealEstateAgency::getDwellings() const {
    return this->dwellings;
}
