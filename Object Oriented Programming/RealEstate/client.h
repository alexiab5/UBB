//
// Created by alexia on 22.04.2024.
//
#pragma once
#ifndef T2_2_CLIENT_H
#define T2_2_CLIENT_H
#include <string>
#include "dwelling.h"
#endif //T2_2_CLIENT_H


class Client{
protected:
    std::string name;
    int income;
public:
    Client(std::string _name, int _income);
    virtual ~Client(){};
    virtual double totalIncome() const;
    virtual std::string toString() const;
    virtual bool isInterested(Dwelling d) const = 0;
    std::string getName() const;
};

class Person : public Client{
public:
    Person(std::string _name, int _income);
    bool isInterested(Dwelling d) const override;
};

class Company : public Client{
private:
    double moneyFromInvestments;
public:
    Company(std::string _name, int _income, double _moneyFromInvestments);
    double totalIncome() const override;
    bool isInterested(Dwelling d) const override;
    std::string toString() const override;
};