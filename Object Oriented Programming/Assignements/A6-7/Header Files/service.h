#pragma once
#include "repository.h"
#include "shoppingBasket.h"

class Service {
private:
    Repository repository;
    ShoppingBasket* shoppingBasket;
    std::string shoppingBasketType;
public:
    Service(Repository& repo, std::string _shoppingBasketType);

    /**
     * Adds a new TrenchCoat to the repository. Raises std::invalid_argument if the element already exists in the repository.
     * i.e there are no two TrenchCoats with all fields equal in the repository.
     * Input: a TElem representing the element to be added.
     **/
    void addTrenchCoatService(const TrenchCoat& trench);

    /**
     * Removes the TrenchCoat at a specific position from the repository. Raises std::invalid_argument if the position is invalid.
     * Input: an integer representing the position of the TrenchCoat to be removed.
     **/
    void removeTrenchCoatByPositionService(int position);

    /**
    * Updates the TrenchCoat at a specific position from the dynamic array.
    * Input: an integer representing the position of the element to be removed, a reference to a TrenchCoat representing the updated TrenchCoat.
    * Raises std::invalid_argument if the position is invalid or if the new TrenchCoat is already in the repository.
    **/
    void updateTrenchCoatService(const TrenchCoat& old_trench, const TrenchCoat& new_trench);

    /**
     * Returns a DynamicVector of all TrenchCoats currently in the repository.
     **/
    std::vector<TrenchCoat> getAllTrenchCoatsService()const;

    /**
    * Returns the TrenchCoat found at a specific position in the repository. Raises std::invalid_argument if the provided position is invalid.
    **/
    TrenchCoat getTrenchCoatByPositionService(int position) const;

    /**
    * Returns the number of TrenchCoats currently in the repository.
    **/
    int getTrenchCoatsCount() const;

    /**
     * Searches for a TrenchCoat in the repository.
     * Input: A reference to a TElem representing the TrenchCoat to be searched.
     * Returns: the position of the provided TrenchCoat in the repository or -1 if it does not exist.
     **/
    int searchForTrenchCoatService(const TrenchCoat& trench);

    /**
     * Replaces a TrenchCoat with another one.
     * Input: the TrenchCoat to be replaced (trench1), the TrenchCoat with which it will be replaced (trench2)
     * Raises: std::invalid_argument if the TrenchCoat to be removed does not exist or if the new TrenchCoat already exists.
     **/
    void replaceTrenchCoatService(const TrenchCoat& trench1, const TrenchCoat& trench2);

    /**
    * Removes a TrenchCoat from the repository. Raises std::invalid_argument if the provided TrenchCoat does not exist in the repository.
    * Input: the TrenchCoat to be removed.
    **/
    void removeTrenchCoatService(const TrenchCoat& trench);

    /**
    * Returns a DynamicVector containing all TrenchCoats in the database having a certain size.
    * Input: the size of the TrenchCoats
    **/
    std::vector<TrenchCoat> getTrenchCoatsBySizeService(int size) const;

    // shopping cart service

    /**
     * Adds a TrenchCoat to the shopping cart
     * Input: reference to the TrenchCoat to be added.
    **/
    void addToShoppingCartService(const TrenchCoat& trench);

    /**
     * Returns the total sum of the TrenchCoats currently in the shopping cart.
     **/
    float getTotalShoppingCartService() const;

    /**
     * Returns the number of TrenchCoats currently in the shopping cart.
     **/
    int getNumberOfItemsInShoppingCartService() const;

    /**
     * Eliminates all TrenchCoats currently in the shopping cart and resets the toal sum to 0.
     **/
    void buyAllService();

    /**
     * Returns a DynamicVector of all the TrenchCoats currently in the shopping cart.
     **/
    std::vector<TrenchCoat> getShoppingCartService() const;

    void setShoppingBasketType(std::string _shoppingBasketType);

    std::string getShoppingBasketType() const;

    std::string getShoppingBasketFile() const;
};