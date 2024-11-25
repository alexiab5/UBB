#include "service.h"
#include <stdexcept>

Service::Service()
{
    this->repository = Repository{};
    this->addTrenchCoats();
    this->shoppingCart = DynamicVector<TrenchCoat>{ this->repository.getDatabaseSize() };
    this->totalSum = 0.00;
}

void Service::addTrenchCoatService(const TrenchCoat& trench)
{
    this->repository.addTrenchCoat(trench);
}

void Service::removeTrenchCoatByPositionService(int position)
{
    this->repository.removeTrenchCoatByPosition(position);
}

void Service::updateTrenchCoatService(const TrenchCoat& old_trench, const TrenchCoat& new_trench)
{
    int index1 = this->repository.searchForTrenchCoat(old_trench);
    if (index1 == -1) {
        throw std::invalid_argument("The old trench coat does not exist in the database!");
    }
    int index2 = this->searchForTrenchCoatService(new_trench);
    if(index2 != -1){
        throw std::invalid_argument("A trench coat with the updated information already exists in the database!");
    }
    this->repository.updateTrenchCoat(index1, new_trench);
}

DynamicVector<TrenchCoat> Service::getAllTrenchCoatsService() const
{
    return this->repository.getAllTrenchCoats();
}

TrenchCoat Service::getTrenchCoatByPositionService(int position) const
{
    return this->repository.getTrenchCoatByPosition(position);
}

int Service::getTrenchCoatsCount() const
{
    return this->repository.getDatabaseSize();
}

int Service::searchForTrenchCoatService(const TrenchCoat &trench) const {
    return this->repository.searchForTrenchCoat(trench);
}

void Service::removeTrenchCoatService(const TrenchCoat &trench) {
    int index = this->repository.searchForTrenchCoat(trench);
    if(index == -1){
        throw std::invalid_argument("The trench coat with the provided attributes does not currently exist in the database!");
    }
    else{
        this->repository.removeTrenchCoatByPosition(index);
    }
}

void Service::replaceTrenchCoatService(const TrenchCoat &trench1, const TrenchCoat &trench2) {
    int index1 = this->repository.searchForTrenchCoat(trench1);
    if(index1 == -1){
        throw std::invalid_argument("The trench coat to be updated does not currently exist in the database!");
    }
    int index2 = this->repository.searchForTrenchCoat(trench2);
    if(index2 != -1){
        throw std::invalid_argument("A trench coat with the updated information already exists in the database");
    }
    this->repository.updateTrenchCoat(index1, trench2);
}

DynamicVector<TrenchCoat> Service::getTrenchCoatsBySizeService(int size) const
{
    return this->repository.getTrenchCoatsBySize(size);
}

void Service::addTrenchCoats()
{
    TrenchCoat t1{ "beige", "https://www.cos.com/en_eur/women/womenswear/coats-and-jackets/product.hooded-trench-coat-beige.1215478001.html", 38, 10, 1125 };
    this->repository.addTrenchCoat(t1);
    TrenchCoat t2{ "dark khaki", "https://www.cos.com/en_eur/women/womenswear/coats-and-jackets/product.double-breasted-wool-blend-trench-coat-green.1221627001.html", 42, 7, 1450 };
    this->repository.addTrenchCoat(t2);
    TrenchCoat t3{ "black", "https://www.cos.com/en_eur/women/womenswear/coats-and-jackets/product.scarf-detail-cropped-hybrid-trench-coat-black.1221576001.html", 40, 30, 495 };
    this->repository.addTrenchCoat(t3);
    TrenchCoat t4{ "khaki", "https://www.massimodutti.com/ro/trenci-scurt-petrecut-2-layers-l06750810", 36, 40, 999.99 };
    this->repository.addTrenchCoat(t4);
    TrenchCoat t5{ "camel", "https://www.massimodutti.com/ro/trenci-scurt-din-piele-nappa-l04710730", 34, 3, 1799.99 };
    this->repository.addTrenchCoat(t5);
    TrenchCoat t6{ "beige", "https://www.massimodutti.com/ro/trenci-cu-cordon-l06723612", 38, 15, 999 };
    this->repository.addTrenchCoat(t6);
    TrenchCoat t7{ "navy blue", "https://www.massimodutti.com/ro/palton-trenci-din-amestec-de-lana-bleumarin-l06439582", 40, 7, 1499 };
    this->repository.addTrenchCoat(t7);
    TrenchCoat t8{ "black", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 44, 25, 649 };
    this->repository.addTrenchCoat(t8);
    TrenchCoat t9{"light beige", "https://www.cos.com/en_eur/women/womenswear/coats-and-jackets/product.cropped-trench-coat-cape-beige.1184404001.html", 48, 17, 575.99};
    this->repository.addTrenchCoat(t9);
    TrenchCoat t10{"beige/checked", "https://www.cos.com/en_eur/women/womenswear/coats-and-jackets/product.checked-utility-trench-coat-beige.1191474001.html", 38, 2, 1250};
    this->repository.addTrenchCoat(t10);
}

void Service::addToShoppingCart(const TrenchCoat& trench)
{
    this->shoppingCart.addElement(trench);
    this->totalSum += trench.getPrice();
}

float Service::getTotalSum() const
{
    return this->totalSum;
}

int Service::getNumberOfItemsInShoppingCart() const
{
    return this->shoppingCart.getSize();
}

void Service::buyAll()
{
    int noItems = this->shoppingCart.getSize();
    for (int i = noItems - 1; i >= 0 ; i--) {
        this->shoppingCart.removeElement(i);
    }
    this->totalSum = 0;
}

DynamicVector<TrenchCoat> Service::getShoppingCart() const
{
    return this->shoppingCart;
}
