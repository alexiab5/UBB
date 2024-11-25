#include "service.h"
#include <stdexcept>

Service::Service(Repository& repo, std::string _shoppingBasketType): repository(repo), shoppingBasketType(_shoppingBasketType){
    if(_shoppingBasketType == "csv")
        this-> shoppingBasket = new ShoppingBasketCSV("shoppingBasket.csv");
    else
        this-> shoppingBasket = new ShoppingBasketHTML("shoppingBasket.html");
}

void Service::addTrenchCoatService(const TrenchCoat& trench)
{
    if(this->searchForUniqueTrenchCoat(trench) != -1)
        throw RepositoryException("This trench coat already exists!");
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
        throw InexistentTrenchCoatException();
    }
    int index2 = this->searchForTrenchCoatService(new_trench);
    if(index2 != -1){
        throw DuplicatedTrenchCoatException();
    }
    this->repository.updateTrenchCoat(index1, new_trench);
}

std::vector<TrenchCoat> Service::getAllTrenchCoatsService() const
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

int Service::searchForTrenchCoatService(const TrenchCoat &trench) {
    return this->repository.searchForTrenchCoat(trench);
}

void Service::removeTrenchCoatService(const TrenchCoat &trench) {
    int index = this->searchForUniqueTrenchCoat(trench);
    if(this->searchForUniqueTrenchCoat(trench) == -1)
        throw RepositoryException("This trench coat does not exist!");
    this->repository.removeTrenchCoatByPosition(index);
}

void Service::replaceTrenchCoatService(const TrenchCoat &trench1, const TrenchCoat &trench2) {
    int index1 = this->repository.searchForTrenchCoat(trench1);
    if(index1 == -1){
        throw InexistentTrenchCoatException();
    }
    int index2 = this->repository.searchForTrenchCoat(trench2);
    if(index2 != -1){
        throw DuplicatedTrenchCoatException();
    }
    this->repository.updateTrenchCoat(index1, trench2);
}

std::vector<TrenchCoat> Service::getTrenchCoatsBySizeService(int size) const
{
    return this->repository.getTrenchCoatsBySize(size);
}

void Service::setShoppingBasketType(std::string _shoppingBasketType) {
    if(_shoppingBasketType == "csv"){
        this->shoppingBasketType = _shoppingBasketType;
        free(shoppingBasket);
        shoppingBasket = new ShoppingBasketCSV("shoppingBasket.csv");
    }
    else if(_shoppingBasketType == "html"){
        this->shoppingBasketType = _shoppingBasketType;
        free(shoppingBasket);
        shoppingBasket = new ShoppingBasketHTML("shoppingBasket.html");
    }
}

std::string Service::getShoppingBasketType() const {
    return this->shoppingBasketType;
}

void Service::addToShoppingCartService(const TrenchCoat &trench) {
    this->shoppingBasket->addToShoppingCart(trench);
    this->shoppingBasket->writeToFile();
}

float Service::getTotalShoppingCartService() const {
    return this->shoppingBasket->getTotalSum();
}

int Service::getNumberOfItemsInShoppingCartService() const {
    return this->shoppingBasket->getNumberOfItemsInShoppingCart();
}

void Service::buyAllService() {
    this->shoppingBasket->emptyShoppingBasket();
    this->shoppingBasket->writeToFile();
}

std::vector<TrenchCoat> Service::getShoppingCartService() const {
    return this->shoppingBasket->getShoppingCart();
}

std::string Service::getShoppingBasketFile() const {
    return this->shoppingBasket->getFileName();
}

int Service::searchForUniqueTrenchCoat(const TrenchCoat &trench) {
    std::vector<TrenchCoat> trenches = this->repository.getAllTrenchCoats();
    int noOfTrenches = trenches.size();
    for(int i = 0; i < noOfTrenches; i++){
        if(trenches[i].getColour() == trench.getColour() && trenches[i].getPhotograph() == trench.getPhotograph())
            return i;
    }
    return -1;
}

void Service::updateUniqueTrenchCoatService(const TrenchCoat &trench) {
    int index = this->searchForUniqueTrenchCoat(trench);
    if(index == -1)
        throw RepositoryException("The trench coat to be updated does not exist");
    this->repository.updateTrenchCoat(index, trench);
}
