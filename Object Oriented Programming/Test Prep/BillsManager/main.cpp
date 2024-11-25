#include <QtWidgets/QApplication>
#include "billsgui.h"
#include "repository.h"
#include "service.h"
#include "billsListModel.h"
#include <iostream>

void tests(){
    Repository repo{"bills.txt"};
    std::vector<Bill> bills = repo.getAllBills();
//    for(const auto& bill : bills)
//        std::cout << bill << "\n";
    Bill b{"orange", "xxx", 200, true};
    repo.addBill(b);
    bills = repo.getAllBills();
//    for(const auto& bill : bills)
//        std::cout << bill << "\n";
    try{
        repo.addBill(Bill{"orange", "EED36677", 200, true});
        assert(false);
    }
    catch(...){
        assert(true);
    }
    repo.removeBill(b);
    bills = repo.getAllBills();
//    for(const auto& bill : bills)
//        std::cout << bill << "\n";
    try{
        repo.removeBill(Bill{"orange", "xxx", 200, true});
        assert(false);
    }
    catch(...){
        assert(true);
    }
}

int main(int argc, char** argv) {
    tests();
    QApplication a(argc, argv);
    Repository repo{"bills.txt"};
    Service s{repo};
    QAbstractListModel *model = new BillsListModel{repo};
    BillsListFilterProxyModel* proxyModel= new BillsListFilterProxyModel{repo};
    BillsGUI gui{proxyModel, model, s};
    gui.show();
    return a.exec();
}
