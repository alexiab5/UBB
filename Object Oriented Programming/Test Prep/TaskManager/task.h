//
// Created by alexia on 26.05.2024.
//

#ifndef TESTQT4_TASK_H
#define TESTQT4_TASK_H
#include <string>
class Task{
private:
    std::string description;
    int duration;
    int priority;
public:
    Task();
    Task(std::string _description, int _duration, int _priority);
    int getDuration() const;
    int getPriority() const;
    std::string getDescription() const;
    friend std::istream &operator>>(std::istream &is, Task& task);
};
#endif //TESTQT4_TASK_H
