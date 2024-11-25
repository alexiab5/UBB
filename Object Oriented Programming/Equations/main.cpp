#include <iostream>
#include "gui.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    Repository r{};
    gui g{r};
    g.show();

    return a.exec();
//Repository r{};
//auto v = r.getAll();
//for(auto s : v){
//    std::cout << s << "\n";
//}
}
