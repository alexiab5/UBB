#include "domain.h"
#include <stdexcept>
#include <vector>
#include <sstream>

TrenchCoat::TrenchCoat() : colour{ "" }, photograph{ "" }, size{ 0 }, quantity{ 0 }, price { 0.0 }
{}

TrenchCoat::TrenchCoat(const std::string & colour, const std::string & photograph, int size, int quantity, float price)
{
    this->colour = colour;
    this->photograph = photograph;
    this->size = size;
    this->quantity = quantity;
    this->price = price;
}

TrenchCoat& TrenchCoat::operator=(const TrenchCoat& trench)
{
    if (this == &trench)
        return *this;

    this->colour = trench.colour;
    this->photograph = trench.photograph;
    this->size = trench.size;
    this->quantity = trench.quantity;
    this->price = trench.price;

    return *this;
}

bool TrenchCoat::operator==(const TrenchCoat& trench) const
{
    return (this->colour == trench.colour && this->photograph == trench.photograph && this->size == trench.size &&
            this->quantity == trench.quantity && this->price == trench.price);
}


//Getters

std::string TrenchCoat::getColour() const
{
    return this->colour;
}

std::string TrenchCoat::getPhotograph() const
{
    return this->photograph;
}

int TrenchCoat::getSize() const
{
    return this->size;
}

int TrenchCoat::getQuantity() const
{
    return this->quantity;
}

float TrenchCoat::getPrice() const
{
    return this->price;
}

//Setters

void TrenchCoat::setColour(const std::string& colour)
{
    this->colour = colour;
}

void TrenchCoat::setPhotograph(const std::string& photograph)
{
    this->photograph = photograph;
}

void TrenchCoat::setSize(int size)
{
    this->size = size;
}

void TrenchCoat::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void TrenchCoat::setPrice(float price)
{
    this->price = price;
}

std::ostream &operator<<(std::ostream &os, const TrenchCoat &trench) {
    os << trench.colour << "," << trench.size << "," << trench.price << "," << trench.quantity << ","
            << trench.photograph;
    return os;
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream & operator>>(std::istream & is, TrenchCoat& trench)
{
    std::string line;
    std::getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    trench.colour = tokens[0];
    trench.size = stoi(tokens[1]);
    trench.price = stof(tokens[2]);
    trench.quantity = stoi(tokens[3]);
    trench.photograph = tokens[4];
    return is;
}