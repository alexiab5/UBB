#include "repository.h"
#include "stdexcept"

Repository::Repository()
{
	this->trenchCoatsDatabase = DynamicVector<TrenchCoat>{CAPACITY};
}

void Repository::addTrenchCoat(const TrenchCoat& trench)
{
	int index = this->trenchCoatsDatabase.searchForElement(trench);
	if(index != -1)
		throw std::invalid_argument("Trench coat already exists in the database! ");
	this->trenchCoatsDatabase.addElement(trench);
}

void Repository::removeTrenchCoatByPosition(int position)
{
	this->trenchCoatsDatabase.removeElement(position);
}

void Repository::removeTrenchCoat(const TrenchCoat& trench)
{
	int index = this->trenchCoatsDatabase.searchForElement(trench);
	if (index == -1)
		throw std::invalid_argument("The trench coat with the provided credentials does not exist in the database! ");
	this->trenchCoatsDatabase.removeElement(index);
}

void Repository::updateTrenchCoat(int index, const TrenchCoat& trench)
{
	this->trenchCoatsDatabase.updateElement(index, trench);
}

DynamicVector<TrenchCoat> Repository::getAllTrenchCoats() const
{
	return this->trenchCoatsDatabase;
}

DynamicVector<TrenchCoat> Repository::getTrenchCoatsBySize(int size) const
{
	int size2 = this->trenchCoatsDatabase.getSize();
	DynamicVector<TrenchCoat> d{ size2 };
	for (int i = 0; i < size2; i++)
		if (this->trenchCoatsDatabase.getElement(i).getSize() == size) {
			d.addElement(this->trenchCoatsDatabase.getElement(i));
		}
	return d;}

int Repository::getDatabaseSize() const
{
	return this->trenchCoatsDatabase.getSize();
}

TrenchCoat Repository::getTrenchCoatByPosition(int position) const
{
	if (position < 0 || position >= this->getDatabaseSize())
		throw std::invalid_argument("Invalid position!");
	return this->trenchCoatsDatabase.getElement(position);
}

int Repository::searchForTrenchCoat(const TrenchCoat &trench) const {
    return this->trenchCoatsDatabase.searchForElement(trench);
}
