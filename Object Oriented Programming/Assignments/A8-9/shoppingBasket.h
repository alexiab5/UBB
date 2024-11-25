#pragma once
#ifndef OOP_A6_7_ALEXIAB5_SHOPPINGBASKET_H
#define OOP_A6_7_ALEXIAB5_SHOPPINGBASKET_H
#include <vector>
#include <fstream>
#include "domain.h"
#endif //OOP_A6_7_ALEXIAB5_SHOPPINGBASKET_H

class ShoppingBasket{
protected:
    std::vector<TrenchCoat> trenchCoats;
    float totalSum;
public:
    ShoppingBasket();
    virtual ~ShoppingBasket(){};
    void addToShoppingCart(const TrenchCoat& trench);

    float getTotalSum() const;

    int getNumberOfItemsInShoppingCart() const;

    void emptyShoppingBasket();

    std::vector<TrenchCoat> getShoppingCart() const;

    virtual void writeToFile() const = 0;
    virtual std::string getFileName() const = 0;
};

class ShoppingBasketCSV : public ShoppingBasket{
private:
    std::string fileName;
public:
    ShoppingBasketCSV(std::string _fileName);
    std::string getFileName() const override;
    void writeToFile() const override;
};

class ShoppingBasketHTML : public ShoppingBasket{
private:
    std::string fileName;
public:
    ShoppingBasketHTML(std::string _fileName);
    std::string getFileName() const override;
    void writeToFile() const override;
};