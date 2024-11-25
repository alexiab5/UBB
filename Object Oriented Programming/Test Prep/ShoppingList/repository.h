//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT2_REPOSITORY_H
#include "shoppingList.h"
#include <vector>
#define TESTQT2_REPOSITORY_H
class Repository{
private:
    std::vector<ShoppingList> shoppingLists;
    std::string fileName;
    void save();
    void load();
public:
    Repository(std::string _fileName="shopingLists.txt");
    void deleteShoppingList(ShoppingList& shoppingList);
    void deleteShoppingListByIndex(int index);
    void addShoppinglist(ShoppingList& shoppingList);
    std::vector<ShoppingList> getAll() const;
    std::vector<ShoppingList> filterByCategory(std::string category) const;
    int getSize() const;
};
#endif //TESTQT2_REPOSITORY_H
