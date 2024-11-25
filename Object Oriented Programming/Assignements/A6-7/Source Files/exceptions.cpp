//
// Created by alexia on 27.04.2024.
//
#include "exceptions.h"

RepositoryException::RepositoryException(std::string _message): message(_message) {}

const char *RepositoryException::what() const noexcept{
    return this->message.c_str();
}

RepositoryException::RepositoryException() : message("") {}


const char *DuplicatedTrenchCoatException::what() const noexcept{
    return "The trench coat with the provided credentials already exists in the repository!";
}

const char *InvalidIndexException::what() const noexcept{
    return "Invalid index!";
}

const char *InexistentTrenchCoatException::what() const noexcept{
    return "The trench coat with the provided credentials does not exist in the repository!";
}
