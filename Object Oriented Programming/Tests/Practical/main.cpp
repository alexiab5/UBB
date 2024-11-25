#include <iostream>
#include <QApplication>
#include "service.h"
#include "window.h"
#include "tableModel.h"

int main(int argc, char** argv){
    QApplication a(argc, argv);
    Service s;
    for(auto r : s.getResearchers())
        std::cout << r.getName() << " " << r.getPosition() << "\n";
    for(auto i : s.getIdeas())
        std::cout << i << "\n";

    TableModel* model = new TableModel{s};
    for(auto r : s.getResearchers()){
        Window *w = new Window{model, s, r};
        w->show();
    }
    return a.exec();
}