#include "client.h"
#include <sstream>

Client::Client(std::string _name, int _income): name(_name), income(_income) {}

double Client::totalIncome() const {
    return this->income;
}

std::string Client::toString() const {
    std::stringstream o;
    o << "Client Name: " << this->name << "Income: " << this->income;
    return o.str();
}

std::string Client::getName() const {
    return this->name;
}

Person::Person(std::string _name, int _income) : Client(_name, _income){}

bool Person::isInterested(Dwelling d) const {
    return (d.getPrice() / 1000 <= this->totalIncome());
}

Company::Company(std::string _name, int _income, double _moneyFromInvestments): Client(_name, _income), moneyFromInvestments(_moneyFromInvestments) {}

double Company::totalIncome() const {
    return (this->income + this->moneyFromInvestments);
}

bool Company::isInterested(Dwelling d) const {
    return (d.getPrice() / 1000 <= this->totalIncome() && d.isDwellingProfitable());
}

std::string Company::toString() const {
    std::stringstream o;
    o << "Client Name: " << this->name << " Income: " << this->income << " Money from Investments: " << this->moneyFromInvestments << " Total Income: " << this->totalIncome();
    return o.str();
}
