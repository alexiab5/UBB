#pragma once
#include "service.h"

class UI {
private:
	Service service;
	void printAdminMenu();
	void printMainMenu();
	void printUserMenu();
	TrenchCoat getTrenchCoatInfo();
public:
	UI();
	void addTrenchCoatAdmin();
	void removeTrenchCoatAdmin();
	void updateTrenchCoatAdmin();
	void browseTrenchCoatsUser();
	void buyTrenchCoats();
	void displayAllAdmin();
	void start();
    int readInteger(const std::string &message);
};