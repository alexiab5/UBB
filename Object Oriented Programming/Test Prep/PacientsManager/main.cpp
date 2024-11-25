#include <iostream>
#include <QApplication>
#include "controller.h"
#include "window.h"
#include "statisticswindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    PacientsRepository p;
    DoctorsRepository d;
    Controller c{d, p};
    StatisticsWindow* window = new StatisticsWindow(c);
    window->show();
    for(auto doct: c.getDoctors())
        std::cout << doct.getName() << " " << doct.getSpecialisation() << "\n";
    for(auto pac : c.getPacients())
        std::cout << pac << "\n";
    for(auto doct : c.getDoctors()){
        Window* w = new Window(c, doct);
        w->show();
    }
    return a.exec();
}
