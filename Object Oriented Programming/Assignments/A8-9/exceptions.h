#pragma once
#ifndef OOP_A6_7_ALEXIAB5_EXCEPTIONS_H
#define OOP_A6_7_ALEXIAB5_EXCEPTIONS_H
#include "repository.h"
#include <stdexcept>
#endif //OOP_A6_7_ALEXIAB5_EXCEPTIONS_H

class RepositoryException : public std::exception{
protected:
    std::string message;
public:
    RepositoryException();
    RepositoryException(std::string _message);
    virtual ~RepositoryException(){};
    virtual const char* what() const noexcept;
};

class DuplicatedTrenchCoatException : public RepositoryException{
    const char* what() const noexcept override;
};

class InvalidIndexException : public RepositoryException{
    const char* what() const noexcept override;
};

class InexistentTrenchCoatException : public RepositoryException{
    const char* what() const noexcept override;
};