//
// Created by alexia on 24.06.2024.
//
#include "controller.h"

std::vector<Volunteer> Controller::getVolunteers() const {
    return volunteers.getAll();
}

std::vector<Department> Controller::getDepartments() const {
    return departments.getAll();
}

void Controller::addVolunteer(Volunteer& v) {
    this->volunteers.add(v);
    this->notify();
}

std::vector<Volunteer> Controller::getVolunteersSorted() const {
    auto vols = volunteers.getAll();
    std::sort(vols.begin(), vols.end(), [](const Volunteer& v1, const Volunteer& v2){
        return v1.getName() < v2.getName();
    });
    return vols;
}

void Controller::changeDepartment(Volunteer volunteer, std::string department) {
    auto vols = volunteers.getAll();
    auto it = std::find_if(vols.begin(), vols.end(), [&volunteer](const Volunteer& v){
        return v.getName() == volunteer.getName() && v.getEmail() == volunteer.getEmail();});
    if(it != vols.end()){
        int index = it - vols.begin();
        this->volunteers.changeDepartment(index, department);
        this->notify();
    }
}

std::vector<Volunteer> Controller::getVolunteersByDepartment(Department department) const {
    std::vector<Volunteer> vols = this->volunteers.getAll();
    std::vector<Volunteer> bydep;
    std::copy_if(vols.begin(), vols.end(), std::back_inserter(bydep), [&department](Volunteer &v){return v.getDepartment() == department.getName();});
    return bydep;
}

double computeSuitability(const Volunteer& v, const Department& department){
    std::string name = department.getDescription();
    int count = 0;
    std::stringstream ss(v.getInterests());
    std::string word;
    while(getline(ss, word, ' ')){
        std::stringstream s2(name);
        std::string word2;
        while(getline(s2, word2, ' ')){
            if(word2 == word){
                count++;
                break;
            }
        }
    }
    int size = name.size();
    return (double)((double)count/(double)size);
}

std::vector<Volunteer> Controller::getTop3(Department department) const {
    Department d;
    std::vector<Volunteer> vols = this->getVolunteersByDepartment(d);
    if(vols.empty())
        return vols;
    std::sort(vols.begin(), vols.end(), [&department](const Volunteer &v1, const Volunteer &v2){return computeSuitability(v1, department) >
            computeSuitability(v2, department);});
    std::vector<Volunteer> top;
    top.push_back(vols[0]);
    if(vols.size() > 1)
        top.push_back(vols[1]);
    if(vols.size() > 2)
        top.push_back(vols[2]);
    return top;
}
