#pragma once
#ifndef OOP_A6_7_ALEXIAB5_TRENCHCOATVALIDATOR_H
#define OOP_A6_7_ALEXIAB5_TRENCHCOATVALIDATOR_H
#include <stdexcept>
#include <regex>
#include "domain.h"
#endif //OOP_A6_7_ALEXIAB5_TRENCHCOATVALIDATOR_H

class ValidationException : public std::exception{
private:
    std::string message;
public:
    ValidationException(std::string& _message);
    const char* what() const noexcept override;
};

class TrenchCoatValidator{
public:
    static void validateTrenchCoat(const TrenchCoat& trench);
};