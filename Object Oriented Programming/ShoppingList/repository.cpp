//
// Created by alexia on 26.05.2024.
//
#include "repository.h"
#include <sstream>
#include <fstream>
#include <algorithm>

Repository::Repository(std::string _fileName): fileName(_fileName) {
    this->shoppingLists = std::vector<ShoppingList>();
    this->load();
}

void Repository::deleteShoppingList(ShoppingList &shoppingList) {
    auto it = this->shoppingLists.begin();
    for(; it != this->shoppingLists.end(); it++){
        if(it->getQuantity() == shoppingList.getQuantity() && it->getName() == shoppingList.getName() && it->getCategory() == shoppingList.getCategory())
            break;
    }
    if(it != this->shoppingLists.end()){
        this->shoppingLists.erase(it);
    }
    else
        throw std::string("The shopping list to be removed does not exist");
}

void Repository::addShoppinglist(ShoppingList &shoppingList) {
    this->shoppingLists.push_back(shoppingList);
}

std::vector<ShoppingList> Repository::getAll() const {
    return this->shoppingLists;
}

int Repository::getSize() const {
    return this->shoppingLists.size();
}

void Repository::save() {
    std::ofstream file(this->fileName);
    if(!file.is_open())
        throw std::string("Could not open the file for writing");
    for(const auto& s : this->shoppingLists){
        file << s << "\n";
    }
    file.close();
}

void Repository::load() {
    std::ifstream file(this->fileName, std::ios::in);
    if(!file.is_open())
        throw std::string("Could not open the file for reading");
    this->shoppingLists.clear();
    ShoppingList s;
    while(file >> s){
        this->shoppingLists.push_back(s);
    }
    file.close();
}

std::vector<ShoppingList> Repository::filterByCategory(std::string category) const {
    std::vector<ShoppingList> res;
    for(const auto& s : this->shoppingLists){
        if(s.getCategory() == category)
            res.push_back(s);
    }
//    std::copy_if(shoppingLists.begin(), shoppingLists.end(), std::back_inserter(res),
//                 [&category](const ShoppingList& s){return s.getCategory() == category;});
    return res;
}

void Repository::deleteShoppingListByIndex(int index) {
    if(index < 0 || index > this->shoppingLists.size())
        throw std::string("Invalid index!");
    this->shoppingLists.erase(this->shoppingLists.begin() + index);
}

