//
// Created by alexia on 27.06.2024.
//

#ifndef OOP_E_912_914_ALEXIAB5_IDEAS_H
#define OOP_E_912_914_ALEXIAB5_IDEAS_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Idea{
private:
    std::string title, description, status, creator;
    int duration;
public:
    Idea(): title(""), description(""), status(""), creator(""), duration(1) {}
    Idea(std::string title, std::string description, std::string status, std::string creator, int duration): title(title),
            description(description), status(status), creator(creator), duration(duration){}
    std::string getTitle() const{
        return title;
    }
    std::string getDescription() const{
        return description;
    }
    std::string getStatus() const{
        return status;
    }
    std::string getCreator() const{
        return creator;
    }
    int getDuration() const{
        return duration;
    }

    void setStatus(std::string newStatus){
        status = newStatus;
    }

    friend std::istream& operator>>(std::istream &is, Idea& idea){
        std::string file, token;
        std::getline(is, file);
        std::vector<std::string> res;
        std::stringstream ss(file);
        while(std::getline(ss, token, '|')){
            res.push_back(token);
        }
        if(res.size() != 5)
            return is;
        idea.title = res[0];
        idea.description = res[1];
        idea.status = res[2];
        idea.creator = res[3];
        idea.duration = stoi(res[4]);
        return is;
    }

    friend std::ostream& operator<<(std::ostream &os, const Idea& idea) {
        return os << idea.title << "|" <<  idea.description << "|" <<  idea.status << "|" << idea.creator << "|" << idea.duration;
    }
};

#endif //OOP_E_912_914_ALEXIAB5_IDEAS_H
