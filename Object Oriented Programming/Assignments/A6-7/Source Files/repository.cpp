#include "repository.h"

Repository::Repository(const std::string& fileName)
{
	this->trenchCoatsDatabase = std::vector<TrenchCoat>();
    this->fileName = fileName;
    this->load();
}

Repository::Repository(Repository &repo): trenchCoatsDatabase(repo.trenchCoatsDatabase), fileName(repo.fileName) {}

void Repository::save() {
    std::ofstream file(this->fileName);
    if(!file.is_open())
        return;
    for (const auto& trench : this->trenchCoatsDatabase) {
        file << trench << "\n";
    }
    file.close();
}

void Repository::load() {
    std::ifstream file(this->fileName, std::ios::in);
    if(!file.is_open())
        return;
    this->trenchCoatsDatabase.clear();
    TrenchCoat trench{};
    while (file >> trench) {
        this->trenchCoatsDatabase.push_back(trench);
    }
    file.close();
}

void Repository::addTrenchCoat(const TrenchCoat& trench)
{
    if(this->searchForTrenchCoat(trench) != -1)
		throw DuplicatedTrenchCoatException();
	this->trenchCoatsDatabase.push_back(trench);
    this->save();
}

void Repository::removeTrenchCoatByPosition(int position)
{
	this->trenchCoatsDatabase.erase(this->trenchCoatsDatabase.begin() + position);
    this->save();
}

void Repository::removeTrenchCoat(const TrenchCoat& trench)
{
    std::vector<TrenchCoat>::iterator it;
    it = std::find(this->trenchCoatsDatabase.begin(), this->trenchCoatsDatabase.end(), trench);
    if(it == this->trenchCoatsDatabase.end())
		throw InexistentTrenchCoatException();
    this->trenchCoatsDatabase.erase(it);
    this->save();
}

void Repository::updateTrenchCoat(int index, const TrenchCoat& trench)
{
    if(index < 0 || index >= this->trenchCoatsDatabase.size())
        throw InvalidIndexException();
    this->trenchCoatsDatabase[index] = trench;
    this->save();
}

std::vector<TrenchCoat> Repository::getAllTrenchCoats() const
{
	return this->trenchCoatsDatabase;
}

std::vector<TrenchCoat> Repository::getTrenchCoatsBySize(int size) const
{

	std::vector<TrenchCoat> d = std::vector<TrenchCoat>();
//    int size2 = this->trenchCoatsDatabase.size();
//	for (auto trench : this->trenchCoatsDatabase)
//		if (trench.getSize() == size) {
//			d.push_back(trench);
//		}
    std::copy_if(this->trenchCoatsDatabase.begin(), this->trenchCoatsDatabase.end(), std::back_inserter(d),
                 [&size](const TrenchCoat& t){return t.getSize() == size;});
	return d;
}

int Repository::getDatabaseSize() const
{
	return this->trenchCoatsDatabase.size();
}

TrenchCoat Repository::getTrenchCoatByPosition(int position) const
{
	if (position < 0 || position >= this->getDatabaseSize())
		throw InvalidIndexException();
	return this->trenchCoatsDatabase[position];
}

int Repository::searchForTrenchCoat(const TrenchCoat &trench) {
    std::vector<TrenchCoat>::iterator it;
    it = std::find(this->trenchCoatsDatabase.begin(), this->trenchCoatsDatabase.end(), trench);
    if(it == this->trenchCoatsDatabase.end())
        return -1;
    return it - this->trenchCoatsDatabase.begin();
}
