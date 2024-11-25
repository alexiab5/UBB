//
// Created by alexia on 24.05.2024.
//

#pragma once
#ifndef TESTQT1_REPOSITORY_H
#include "domain.h"
#include <vector>
#include <fstream>
#define TESTQT1_REPOSITORY_H
class Repository {
private:
    std::vector<Bill> bills;
    std::string fileName;

    void save();

    void load();

public:
    Repository(std::string fileName = "bills.txt");

    void addBill(Bill bill);

    void removeBill(Bill bill);

    int searchBill(Bill bill) const;

    std::vector<Bill> getAllBills() const;

    int getSize() const;

    std::vector<Bill> getBillsSortedByName() const;
};
#endif //TESTQT1_REPOSITORY_H
