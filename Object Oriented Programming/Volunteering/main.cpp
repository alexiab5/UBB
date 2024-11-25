#include <iostream>
#include <QApplication>
#include "controller.h"
#include "window.h"
#include "depwindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    DepartmentsRepository d{"departments.txt"};
    VolunteersRepository v{"volunteers.txt"};
    Controller c{d, v};
    depWindow dep{c};
    dep.show();
    for(auto dep : d.getAll()){
        std::cout << dep.getName() << " " << dep.getDescription() << "\n";
    }
    for(auto vol : v.getAll()){
        std::cout << vol << "\n";
    }
    for(auto dep : d.getAll()){
        Window* w = new Window{c, dep};
        w->show();
    }
    return a.exec();
}
