//
// Created by alexia on 24.05.2024.
//
#include "domain.h"

Bill::Bill() {
    this->companyName = "";
    this->number = "";
    this->sum = 0.00;
    this->paid = false;
}

Bill::Bill(std::string _companyName, std::string _number, double _sum, bool _isPaid): companyName(_companyName), number(_number), sum(_sum), paid(_isPaid) {}

std::vector<std::string> tokenize(std::string str, char delimiter) {
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::ostream &operator<<(std::ostream &os, const Bill &bill) {
    std::string res = bill.companyName + ";" + bill.number + ";" + std::to_string(bill.sum) + ";";
    if(bill.paid)
        res += "true";
    else res += "false";
    return os << res;
}

std::istream &operator>>(std::istream &is, Bill &bill) {
    std::string line;
    std::getline(is, line);
    std::vector<std::string> tokens = tokenize(line, ';');
    if (tokens.size() != 4)
        return is;
    bill.companyName = tokens[0];
    bill.number = tokens[1];
    bill.sum = stod(tokens[2]);
    bill.paid = false;
    if(tokens[3] == "true")
        bill.paid = true;
    return is;
}

double Bill::getSum() const {
    return this->sum;
}

std::string Bill::getNumber() const {
    return this->number;
}

bool Bill::isPaid() const {
    return this->paid;
}

std::string Bill::getCompany() const {
    return this->companyName;
}

