//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT4_REPOSITORY_H
#define TESTQT4_REPOSITORY_H
#include "task.h"
#include <vector>
#include <algorithm>

class Repository{
private:
    std::vector<Task> tasks;
    std::string fileName;
    void load();
public:
    Repository(std::string _fileName="tasks.txt");
    std::vector<Task> getAll() const;
    int calculateDurationForTasks(int priority) const;
};
#endif //TESTQT4_REPOSITORY_H
