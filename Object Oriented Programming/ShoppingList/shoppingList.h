//
// Created by alexia on 25.05.2024.
//

#ifndef TESTQT2_SHOPPINGLIST_H
#include <string>
#include <iostream>
#define TESTQT2_SHOPPINGLIST_H
class ShoppingList{
private:
    std::string category;
    std::string name;
    int quantity;
public:
    ShoppingList();
    ShoppingList(std::string _category, std::string _name, int _quantity);
    std::string getCategory() const;
    std::string getName() const;
    int getQuantity() const;

    friend std::ostream &operator<<(std::ostream &os, const ShoppingList& shoppingList);
    friend std::istream &operator>>(std::istream &is, ShoppingList& shoppingList);
};
#endif //TESTQT2_SHOPPINGLIST_H
