#pragma once
#include "dynamic_vector.h"
#define CAPACITY 20

class Repository {
private:
	DynamicVector<TrenchCoat> trenchCoatsDatabase;
public:
	Repository();
    /**
     * Adds a new TrenchCoat to the repository. Raises std::invalid_argument if the element already exists in the repository.
     * i.e there are no two TrenchCoats with all fields equal in the repository.
     * Input: a TElem representing the element to be added.
     **/
	void addTrenchCoat(const TrenchCoat& trench);

    /**
     * Removes the TrenchCoat at a specific position from the repository. Raises std::invalid_argument if the position is invalid.
     * Input: an integer representing the position of the TrenchCoat to be removed.
     **/
	void removeTrenchCoatByPosition(int position);

    /**
     * Removes a TrenchCoat from the repository. Raises std::invalid_argument if the provided TrenchCoat does not exist in the repository.
     * Input: the TrenchCoat to be removed.
     **/
	void removeTrenchCoat(const TrenchCoat& trench);

    /**
     * Updates the TrenchCoat at a specific position from the dynamic array.
     * Input: an integer representing the position of the element to be removed, a reference to a TrenchCoat representing the updated TrenchCoat.
     * Raises std::invalid_argument if the position is invalid or if the new TrenchCoat is already in the repository.
     **/
    void updateTrenchCoat(int index, const TrenchCoat& trench);

    /**
     * Returns a DynamicVector of all TrenchCoats currently in the repository.
     **/
	DynamicVector<TrenchCoat> getAllTrenchCoats() const;

    DynamicVector<TrenchCoat> getTrenchCoatsBySize(int size) const;

    /**
    * Returns the number of TrenchCoats currently in the repository.
    **/
	int getDatabaseSize() const;

    /**
    * Returns the TrenchCoat found at a specific position in the repository. Raises std::invalid_argument if the provided position is invalid.
    **/
	TrenchCoat getTrenchCoatByPosition(int position) const;

    /**
     * Searches for a TrenchCoat in the repository.
     * Input: A reference to a TElem representing the TrenchCoat to be searched.
     * Returns: the position of the provided TrenchCoat in the repository or -1 if it does not exist.
     **/
    int searchForTrenchCoat(const TrenchCoat &trench) const;
};