//
// Created by alexia on 28.05.2024.
//
#include "service.h"
#include <algorithm>

Service::Service(Repository &_repo): repo(_repo) {}

std::vector<Document> Service::getAllService() const {
    return repo.getAll();
}

std::vector<Document> Service::getSorted() const {
    std::vector<Document> res = this->repo.getAll();
    std::sort(res.begin(), res.end(),
              [](const Document &d1, const Document &d2){return d1.getContent().size() < d2.getContent().size();});
    return res;
}

std::vector<Document> Service::getMatchingDocuments(std::string key) const {
    std::vector<Document> res;
    std::vector<Document> docs = repo.getAll();
    for(const auto & s : docs){
        if(s.getName().find(key) != std::string::npos || s.getKeywords().find(key) != std::string::npos ||
                s.getContent().find(key) != std::string::npos)
            res.push_back(s);
    }
    return res;
}

double Service::getSimilarity(Document doc, std::string key) const {
//    if(doc.getName().find(key) != std::string::npos)
//        return  (double)key.size() / (double)doc.getName().size();
    if(doc.getKeywords().find(key) != std::string::npos)
        return (double)key.size() / (double)doc.getKeywords().size();
    return 0;
//    if(doc.getContent().find(key) != std::string::npos)
//        return (double)key.size() / (double)doc.getContent().size();
}

