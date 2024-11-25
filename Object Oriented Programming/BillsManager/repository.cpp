//
// Created by alexia on 24.05.2024.
//
#include "repository.h"
#include <algorithm>

Repository::Repository(std::string _fileName): fileName(_fileName) {
    this->bills = std::vector<Bill>();
    this->load();
}

void Repository::addBill(Bill bill) {
    if(this->searchBill(bill) != -1)
        throw std::string("The bill already exists!");
    this->bills.push_back(bill);
    this->save();
}

int Repository::searchBill(Bill bill) const {
//    auto it = this->bills.begin();
//    for(; it != this->bills.end(); it++)
//        if(it->getNumber() == bill.getNumber())
//            return it - this->bills.begin();
//    return -1;
    std::string serialNumber = bill.getNumber();
    auto it = std::find_if(this->bills.begin(), this->bills.end(),
                                                  [&serialNumber](const Bill& bill){return bill.getNumber() == serialNumber;});
    if(it == this->bills.end())
        return -1;
    return it - this->bills.begin();
}

void Repository::removeBill(Bill bill) {
    auto it = this->bills.begin();
    for(; it != this->bills.end(); it++)
        if(it->getNumber() == bill.getNumber()) {
            this->bills.erase(it);
            this->save();
            return;
        }
    throw std::string("The bill to be removed does not exist!");
}

std::vector<Bill> Repository::getAllBills() const {
    return this->bills;
}

int Repository::getSize() const {
    return this->bills.size();
}

void Repository::save() {
    std::ofstream file(this->fileName);
    if(!file.is_open())
        throw std::string("Could not open file for writing");
    for(const auto& bill : this->bills){
        file << bill << "\n";
    }
    file.close();
}

void Repository::load() {
    std::ifstream file(this->fileName, std::ios::in);
    if(!file.is_open())
        throw std::string("Could not open file for reading");
    this->bills.clear();
    Bill bill;
    while(file >> bill){
        this->bills.push_back(bill);
    }
    file.close();
}

std::vector<Bill> Repository::getBillsSortedByName() const {
    std::vector<Bill> b = this->bills;
    std::sort(b.begin(), b.end(), [](const Bill &b1, const Bill &b2) { return b1.getCompany() < b2.getCompany(); });
    return b;
}
