#include "domain.h"
#include <stdexcept>

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

void TrenchCoat::validateTrenchCoat()
{
    // validate quantity
    if (this->quantity < 0)
        throw std::invalid_argument("Quantity must be a positive integer.");
    // validate price
    if(this->price < 0)
        throw std::invalid_argument("Price must be a positive integer.");
    // validate size
    if(this->size < 32 || this->size > 54 || this->size % 2 == 1)
        throw std::invalid_argument("Invalid size.");
    // validate photograph
}



