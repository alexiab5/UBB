//
// Created by alexia on 30.04.2024.
//
#include "shoppingBasket.h"

ShoppingBasket::ShoppingBasket(): trenchCoats(std::vector<TrenchCoat>{}), totalSum(0.00) {}

void ShoppingBasket::emptyShoppingBasket() {
    this->trenchCoats.clear();
    this->totalSum = 0.00;
}

void ShoppingBasket::addToShoppingCart(const TrenchCoat &trench) {
    this->trenchCoats.push_back(trench);
    this->totalSum += trench.getPrice();
}

float ShoppingBasket::getTotalSum() const {
    return this->totalSum;
}

std::vector<TrenchCoat> ShoppingBasket::getShoppingCart() const {
    return this->trenchCoats;
}

int ShoppingBasket::getNumberOfItemsInShoppingCart() const {
    return this->trenchCoats.size();
}

ShoppingBasketCSV::ShoppingBasketCSV(std::string _fileName): ShoppingBasket(), fileName(_fileName) {}

void ShoppingBasketCSV::writeToFile() const {
    std::ofstream CSVOutputFile(this->fileName.c_str());

    if (!CSVOutputFile.is_open())
        throw std::invalid_argument("The CSV file could not be opened!");

    CSVOutputFile << "Colour, Size, Price, Quantity, Photograph\n";
    for (auto trench : this->trenchCoats)
        CSVOutputFile << trench.getColour() << "," << trench.getSize() << "," << trench.getPrice() << "," << trench.getQuantity() << "," << trench.getPhotograph() << "\n";

    CSVOutputFile.close();
}

std::string ShoppingBasketCSV::getFileName() const {
    return this->fileName;
}

ShoppingBasketHTML::ShoppingBasketHTML(std::string _fileName): ShoppingBasket(), fileName(_fileName) {}

void ShoppingBasketHTML::writeToFile() const {
    std::ofstream HTMLOutputFile(this->fileName.c_str());

    if (!HTMLOutputFile.is_open())
        throw std::invalid_argument("The HTML file could not be opened!");

    HTMLOutputFile << "<!DOCTYPE html> <html> <head> <title> Trench Coats</title> </head > <body> <table border=\"1\">";
    HTMLOutputFile << "<tr> <td> Colour </td> <td> Size </td> <td> Price </td> <td> Quantity </td> <td> Photograph </td> </tr>";
    for (auto trench : this->trenchCoats)
        HTMLOutputFile << "<tr> <td>" << trench.getColour() << "</td> <td>" << trench.getSize() << "</td> <td>" << trench.getPrice() << "</td> <td>" << trench.getQuantity() << "</td> <td><a href=\"" << trench.getPhotograph() << "\"> Link</a></ td> </tr>";

    HTMLOutputFile << "</table> </body> </html>";

    HTMLOutputFile.close();
}

std::string ShoppingBasketHTML::getFileName() const {
    return this->fileName;
}
