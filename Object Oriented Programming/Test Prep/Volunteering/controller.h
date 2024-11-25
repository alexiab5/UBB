//
// Created by alexia on 24.06.2024.
//
#pragma once
#ifndef TEST2_CONTROLLER_H
#define TEST2_CONTROLLER_H
#include "repository.h"
#include "observer.h"

class Controller: public Subject{
private:
    DepartmentsRepository& departments;
    VolunteersRepository& volunteers;
public:
    Controller(DepartmentsRepository& departments, VolunteersRepository& volunteers): departments(departments),
                                                                                    volunteers(volunteers){};
    ~Controller(){};
    std::vector<Volunteer> getVolunteers() const;
    std::vector<Volunteer> getVolunteersSorted() const;
    std::vector<Volunteer> getVolunteersByDepartment(Department department) const;
    std::vector<Volunteer> getTop3(Department department) const;
    std::vector<Department> getDepartments() const;
    void changeDepartment(Volunteer volunteer, std::string department);
    void addVolunteer(Volunteer& v);
};
#endif //TEST2_CONTROLLER_H
