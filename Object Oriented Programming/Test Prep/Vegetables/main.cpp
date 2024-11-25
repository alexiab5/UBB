#include <iostream>
#include "repository.h"
#include "vegetablesGUI.h"
#include <QApplication>

int main(int argc, char** argv) {
//    Repository r{"vegetables.txt"};
//    std::vector<Vegetable> v = r.getAll();
//    for(const auto& s : v){
//        std::cout << s << "\n";
//    }
//    std::vector<std::string> s = r.getAllFamilies();
//    for(const auto& x : s){
//        std::cout << x << "\n";
//    }
    QApplication a(argc, argv);
    Repository r{"vegetables.txt"};
    VegetablesGUI gui{r};
    gui.show();
    return a.exec();
}
