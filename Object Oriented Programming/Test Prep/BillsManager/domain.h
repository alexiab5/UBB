//
// Created by alexia on 24.05.2024.
//

#pragma once
#ifndef TESTQT1_DOMAIN_H
#define TESTQT1_DOMAIN_H
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
class Bill{
private:
    std::string companyName;
    std::string number;
    double sum;
    bool paid;
public:
    Bill();
    Bill(std::string companyName, std::string _number, double _sum, bool _isPaid);
    double getSum() const;
    std::string getCompany() const;
    std::string getNumber() const;
    bool isPaid() const;

    friend std::ostream& operator<<(std::ostream& os, const Bill& bill);
    friend std::istream& operator>>(std::istream& is, Bill& bill);
};
#endif //TESTQT1_DOMAIN_H
