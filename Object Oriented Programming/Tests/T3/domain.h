//
// Created by alexia on 28.05.2024.
//
#pragma once

#ifndef OOP_T3_ALEXIAB5_DOMAIN_H
#define OOP_T3_ALEXIAB5_DOMAIN_H
#include <string>
#include <iostream>

class Document{
private:
    std::string name, keywords, content;
public:
    Document();
    Document(std::string _name, std::string _keywords, std::string _content);
    std::string getName() const;
    std::string getKeywords() const;
    std::string getContent() const;

    friend std::istream &operator>>(std::istream &is, Document &doc);
};
#endif //OOP_T3_ALEXIAB5_DOMAIN_H
