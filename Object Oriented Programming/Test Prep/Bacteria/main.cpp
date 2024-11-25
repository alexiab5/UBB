#include <iostream>
#include <QApplication>
#include "tablemodel.h"
#include "gui.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    Repository r;
    for(auto b : r.getBiologists())
        std::cout << b.getName() << " " << b.getSpecies() << std::endl;
    for(auto b : r.getBacteria())
        std::cout << b << std::endl;
    TableModel* t = new TableModel{r};
    for(auto b : r.getBiologists()) {
        GUI* g = new GUI{b, r, t};
        g->show();
    }
    return a.exec();
}
