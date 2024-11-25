//
// Created by alexia on 28.05.2024.
//
#include "gui.h"
#include "repository.h"
#include <QApplication>

int main(int argc, char** argv)
{

//    auto v = r.getAll();
//    for(auto s : v){
//        std::cout << s.getName() << " " << s.getKeywords() << "\n";
//    }
    QApplication a(argc, argv);
    Repository r{};
    Service s{r};
    gui g{s};
    g.show();
    return a.exec();
}