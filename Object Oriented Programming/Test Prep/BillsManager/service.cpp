//
// Created by alexia on 25.05.2024.
//
#include "service.h"
#include <algorithm>

Service::Service(Repository &_repo): repo(_repo){}

std::vector<Bill> Service::getAllBillsService() const {
    return this->repo.getAllBills();
}

void Service::addBillService(Bill bill) {
    this->repo.addBill(bill);
}

void Service::removeBillService(Bill bill) {
    this->repo.removeBill(bill);
}

std::vector<Bill> Service::getAllUnpaidBills() const {
    std::vector<Bill> res;
    std::vector<Bill> bills = this->repo.getAllBills();
    std::copy_if(bills.begin(), bills.end(), std::back_inserter(res), [](Bill& bill){return !(bill.isPaid());});
    return res;
}

std::vector<Bill> Service::getAllPaidBills() const {
    std::vector<Bill> res;
    std::vector<Bill> bills = this->repo.getAllBills();
    std::copy_if(bills.begin(), bills.end(), std::back_inserter(res), [](Bill& bill){return bill.isPaid();});
    return res;
}

std::vector<Bill> Service::getBillsSortedByNameService() const {
    return this->repo.getBillsSortedByName();
}

std::vector<Bill> Service::getAllUnpaidBillsForCompany(std::string companyName) const {
    std::vector<Bill> bills = this->repo.getAllBills();
    std::vector<Bill> bills2;
    std::vector<Bill> unpaid;
    std::copy_if(bills.begin(), bills.end(), std::back_inserter(bills2), [&companyName](Bill& bill){return bill.getCompany() == companyName;});
    std::copy_if(bills2.begin(), bills2.end(), std::back_inserter(unpaid), [](Bill& bill){return !(bill.isPaid());});
    return unpaid;
}

