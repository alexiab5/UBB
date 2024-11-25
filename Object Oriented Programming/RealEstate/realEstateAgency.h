#pragma once
#ifndef T2_2_REALESTATEAGENCY_H
#define T2_2_REALESTATEAGENCY_H
#include <vector>
#include "client.h"
#include "dwelling.h"
#endif //T2_2_REALESTATEAGENCY_H

class RealEstateAgency{
private:
    std::vector<Dwelling> dwellings;
    std::vector<Client*> clients;
public:
    RealEstateAgency(const std::vector<Dwelling> _dwellings, const std::vector<Client*> _clients);
    void removeClient(std::string name);
    Dwelling addDwelling(double price, bool isProfitable);
    std::vector<Client*> getInterestedClients(Dwelling d) const;
    void writeToFile(std::string fileName) const;
    std::vector<Client*> getClients() const;
    std::vector<Dwelling> getDwellings() const;
};