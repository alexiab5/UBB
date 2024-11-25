//
// Created by alexia on 25.05.2024.
//
#include "shoppingList.h"
#include <vector>
#include <sstream>

ShoppingList::ShoppingList(std::string _category, std::string _name, int _quantity): category(_category), name(_name), quantity(_quantity) {}

ShoppingList::ShoppingList(): name(""), category(""), quantity(0) {}

std::string ShoppingList::getCategory() const {
    return this->category;
}

std::string ShoppingList::getName() const {
    return this->name;
}

int ShoppingList::getQuantity() const {
    return this->quantity;
}

std::ostream &operator<<(std::ostream &os, const ShoppingList &shoppingList) {
    return os << shoppingList.category << "|" << shoppingList.name << "|" << shoppingList.quantity;
}

std::vector<std::string> tokenize(std::string str, char delimiter){
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> res;
    while(getline(ss, token, delimiter)){
        res.push_back(token);
    }
    return res;
}

std::istream &operator>>(std::istream &is, ShoppingList &shoppingList) {
    std::string line;
    std::getline(is, line);
    std::vector<std::string> res = tokenize(line, '|');
    if(res.size() != 3)
        return is;
    shoppingList.category = res[0];
    shoppingList.name = res[1];
    shoppingList.quantity = stoi(res[2]);
    return is;
}


