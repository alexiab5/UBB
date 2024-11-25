#include <QApplication>
#include <QDebug>
#include "repository.h"
#include "shoppinggui.h"

void tests(){
    Repository r{"shoppingLists.txt"};
    auto s = r.getAll();
//    for(const auto& r : s){
//        std::cout << r << "\n";
//    }
    ShoppingList sh{"Dairy", "Milk", 1};
    r.deleteShoppingList(sh);
    s = r.getAll();
//    for(const auto& r : s){
//        std::cout << r << "\n";
//    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository r{"shoppingLists.txt"};
    shoppinggui gui{r};
    gui.show();
    return a.exec();
}
