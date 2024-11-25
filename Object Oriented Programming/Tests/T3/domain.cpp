//
// Created by alexia on 28.05.2024.
//
#include "domain.h"
#include <vector>
#include <sstream>

Document::Document(): name(""), keywords(""), content("") {}

Document::Document(std::string _name, std::string _keywords, std::string _content): name(_name), keywords(_keywords), content(_content) {}

std::string Document::getName() const {
    return name;
}

std::string Document::getKeywords() const {
    return keywords;
}

std::string Document::getContent() const {
    return content;
}

std::istream &operator>>(std::istream &is, Document &doc) {
    std::vector<std::string> res;
    std::string line;
    std::getline(is, line);
    std::stringstream ss(line);
    std::string token;
    while(std::getline(ss, token, ',')){
        res.push_back(token);
    }
    if(res.size() != 3)
        return is;
    doc.name = res[0];
    doc.keywords = res[1];
    doc.content = res[2];
    return is;
}

