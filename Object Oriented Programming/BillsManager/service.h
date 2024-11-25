//
// Created by alexia on 25.05.2024.
//

#ifndef TESTQT1_SERVICE_H
#include "repository.h"
#define TESTQT1_SERVICE_H
class Service{
private:
    Repository& repo;
public:
    Service(Repository& _repo);
    std::vector<Bill> getAllBillsService() const;
    void addBillService(Bill bill);
    void removeBillService(Bill bill);
    std::vector<Bill> getAllUnpaidBills() const;
    std::vector<Bill> getAllPaidBills() const;
    std::vector<Bill> getBillsSortedByNameService() const;
    std::vector<Bill> getAllUnpaidBillsForCompany(std::string companyName) const;
};
#endif //TESTQT1_SERVICE_H
