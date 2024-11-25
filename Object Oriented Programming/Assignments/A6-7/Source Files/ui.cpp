#include "ui.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

UI::UI(Service& _service) : service(_service){
}

void UI::printMainMenu()
{
	std::cout << std::endl << "************* Proper Trench Coats *************" << std::endl;
	std::cout << "1. Administrator mode" << std::endl;
	std::cout << "2. User mode" << std::endl;
	std::cout << "3. Exit" << std::endl;
}

void UI::printUserMenu() {
    std::cout << std::endl << "********* USER MODE **********" << std::endl;
    std::cout << "1. Browse trench coats currently available. " << std::endl;
    std::cout << "2. Go to the shopping cart. " << std::endl;
    std::cout << "3. EXIT user mode. " << std::endl;
}

void UI::printAdminMenu()
{
	std::cout << std::endl << "********* ADMIN MODE **********" << std::endl;
	std::cout << "1. ADD a trench coat." << std::endl;
	std::cout << "2. REMOVE a trench coat." << std::endl;
	std::cout << "3. UPDATE a trench coat." << std::endl;
	std::cout << "4. Display all trench coats in the database." << std::endl;
	std::cout << "5. EXIT to main menu." << std::endl;
}

int UI::readInteger(const std::string& message){
    int number;
    while(true){
        std::cout << message;
        std::string inputString;
        std::getline(std::cin, inputString);
        std::istringstream iss(inputString);
        if(iss >> number && iss.eof())
            return number;
        else
            std::cout << "Invalid input!" << std::endl;
    }
}

TrenchCoat UI::getTrenchCoatInfo() {
    std::string colour, photograph, input_string;
    int quantity, size;
    float price;
    while (colour.empty()) {
        std::cout << "Please enter the colour of the trench coat:";
        std::getline(std::cin, colour);
    }
    size = readInteger("Please enter the size of the trench coat:");
    quantity = readInteger("Please enter the quantity of the trench coat:");
    while (true) {
        std::cout << "Please enter the price of the trench coat:";
        // reading a float number
        std::string inputString;
        std::getline(std::cin, inputString);
        std::istringstream iss(inputString);
        if (iss >> price && iss.eof())
            break;
        else
            std::cout << "Invalid input!" << std::endl;
    }
    while (photograph.empty()) {
        std::cout << "Please enter the link to a photograph of the trench coat:";
        std::getline(std::cin, photograph);
    }
    TrenchCoat t{ colour, photograph, size, quantity, price };
    TrenchCoatValidator::validateTrenchCoat(t);
    return t;
}

void UI::addTrenchCoatAdmin() {
    TrenchCoat trench;
	try {
        trench = getTrenchCoatInfo();
	}
	catch (const ValidationException &error) {
		std::cout << "Invalid trench coat!" << std::endl;
        std::cerr << error.what() << std::endl;
		return;
	}
	try {
		this->service.addTrenchCoatService(trench);
	}
	catch(const RepositoryException & error) {
		std::cout << "The trench coat with the provided information could not be added to the database!" << std::endl;
		std::cerr << error.what() << std::endl;
		return;
	}
	std::cout << "Trench coat successfully added to the database!" << std::endl;
}

void UI::removeTrenchCoatAdmin()
{
    TrenchCoat trench;
    try {
        trench = getTrenchCoatInfo();
    }
    catch (const ValidationException &error) {
        std::cout << "Invalid trench coat!" << std::endl;
        std::cerr << error.what() << std::endl;
        return;
    }
	try {
		this->service.removeTrenchCoatService(trench);
	}
	catch (const RepositoryException& error) {
		std::cout << "Trench coat could not be removed from the database!" << std::endl;
		std::cerr << error.what() << std::endl;
		return;
	}
	std::cout << "The trench coat was successfully removed from the database!" << std::endl;
}

void UI::updateTrenchCoatAdmin()
{
    std::cout << "Please enter the information of the trench coat you want to update:" << std::endl;
    TrenchCoat old_trench;
    try {
        old_trench = getTrenchCoatInfo();
    }
    catch (const ValidationException &error) {
        std::cout << "Invalid trench coat!" << std::endl;
        std::cerr << error.what() << std::endl;
        return;
    }
	std::cout << "Please enter the updated information of the trench coat:" << std::endl;
    TrenchCoat new_trench;
	try {
		new_trench = getTrenchCoatInfo();
	}
    catch (const ValidationException &error) {
        std::cout << "Invalid trench coat!" << std::endl;
        std::cerr << error.what() << std::endl;
        return;
    }
    try {
        this->service.updateTrenchCoatService(old_trench, new_trench);
        std::cout << "Trench coat successfully updated!" << std::endl;
    }
    catch (const RepositoryException& error) {
        std::cout << "Trench coat could not be updated!" << std::endl;
        std::cerr << error.what() << std::endl;
        return;
    }
}

void UI::browseTrenchCoatsUser()
{
    int trenchSize;
    while (true) {
        std::string inputString;
        std::cout << "Enter the size of the trench coats you want to see: ";
        std::getline(std::cin, inputString);
        if (inputString.empty()) {
            trenchSize = 0;
            break;
        }
        std::istringstream iss(inputString);
        if (iss >> trenchSize && iss.eof())
            break;
        else
            std::cout << "Invalid input!" << std::endl;
    }
    std::vector<TrenchCoat> d{};
    if (trenchSize == 0) {
        d = this->service.getAllTrenchCoatsService();
    }
    else {
        d = this->service.getTrenchCoatsBySizeService(trenchSize);
    }
    int current_size = d.size();
    if (current_size == 0) {
        std::cout << "There are no trench coats with that size available!";
        return;
    }
    int currentPosition = 0;
    while(true) {
        std::cout << "COLOUR: " << d[currentPosition].getColour() << " | SIZE: " << d[currentPosition].getSize() << " | PRICE: "
            << d[currentPosition].getPrice() << " | LINK: " << d[currentPosition].getPhotograph() << std::endl;
        // open url
        std::string url = d[currentPosition].getPhotograph();
        std::string op = std::string("start ").append(url);
        system(op.c_str());
        
        std::cout << "1. Add to shopping cart." << std::endl;
        std::cout << "2. Skip to the next." << std::endl;
        std::cout << "3. Quit browsing." << std::endl;
        int option = readInteger(">>>");
        switch (option) {
            case 1:
                try {
                    this->service.addToShoppingCartService(d[currentPosition]);
                    std::cout << "TrenchCoat successfully added to shopping cart! Current cost: "
                              << this->service.getTotalShoppingCartService() << std::endl;

                }
                catch(const std::exception &error){
                    std::cerr << error.what() << std::endl;
                }
                break;
            case 2:
                currentPosition++;
                if (currentPosition == current_size)
                    currentPosition = 0;
                break;
            case 3:
                std::cout << "Thank you for choosing us for your shopping!" << std::endl;
                return;
        }
    }
}

void UI::buyTrenchCoats()
{
    std::vector<TrenchCoat> shoppingCart = this->service.getShoppingCartService();
    if (shoppingCart.empty()) {
        std::cout << "Your shopping cart is currently empty!" << std::endl;
        return;
    }
    std::cout << "Trench coats currently in the shopping cart:" << std::endl;
    try{
        std::string fileName = this->service.getShoppingBasketFile();
        std::string commandToOpenFile = "start " + fileName;
        system(commandToOpenFile.c_str());
    }
    catch(const std::exception &error){
        std::cerr << error.what() << std::endl;
    }
    for (const auto& trench : shoppingCart)
        std::cout << trench << std::endl;
    std::cout << "Total cost: " << this->service.getTotalShoppingCartService() << std::endl;
    std::cout << "Continue to payment? (y/n)" << std::endl;
    std::string option;
    std::getline(std::cin, option);
    if (option == "y") {
        this->service.buyAllService();
        std::cout << "Thank you for your purchase!" << std::endl;
        return;
    }
    return;
}

void UI::displayAllAdmin()
{
	std::vector<TrenchCoat> trenchCoats = this->service.getAllTrenchCoatsService();
	int current_size = trenchCoats.size();
	if (current_size == 0) {
		std::cout << "The trench coats database is currently empty!";
		return;
	}
	std::cout << "Trench coats currently in database:" << std::endl;
	for (const auto& trench : trenchCoats)
		std::cout << trench << std::endl;
}

void UI::start()
{
	bool ok = true;
	while(ok) {
        this->printMainMenu();
        int option;
        bool admin = false;
        option = readInteger("Please enter your option:");
        switch (option) {
            case 1:
                admin = true;
                break;
            case 2:
                admin = false;
                break;
            case 3:
                ok = false;
                std::cout << "Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
        if (admin) {
            bool ok2 = true;
            while (ok2) {
                this->printAdminMenu();
                option = readInteger("Please enter your option:");
                switch (option) {
                    case 1:
                        this->addTrenchCoatAdmin();
                        break;
                    case 2:
                        this->removeTrenchCoatAdmin();
                        break;
                    case 3:
                        this->updateTrenchCoatAdmin();
                        break;
                    case 4:
                        this->displayAllAdmin();
                        break;
                    case 5:
                        ok2 = false;
                        break;
                    default:
                        std::cout << "Invalid option!";
                        break;
                }
            }
        }
        else {
            bool ok2 = true;
            std::cout << "What is the type of file you want to use for storing the shopping basket? (csv/html): ";
            std::string fileType;
            std::getline(std::cin, fileType);
            this->service.setShoppingBasketType(fileType);
            while (ok2) {
                this->printUserMenu();
                int user_option = this->readInteger(">>>");
                switch (user_option) {
                case 1:
                    this->browseTrenchCoatsUser();
                    break;
                case 2:
                    this->buyTrenchCoats();
                    break;
                case 3:
                    std::cout << "Goodbye!" << std::endl;
                    ok2 = false;
                    break;
                default:
                    std::cout << "Invalid option!" << std::endl;
                    break;
                }
            }
        }
    }
}
