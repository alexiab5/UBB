#pragma once
#include <string>

class TrenchCoat {
private:
	std::string colour, photograph;
	int size, quantity;
	float price;
public:

	TrenchCoat();
	TrenchCoat(const std::string& colour, const std::string& photograph, int size, int quantity, float price);

	TrenchCoat& operator=(const TrenchCoat &trench);
	bool operator==(const TrenchCoat &trench) const;

    /**
     * Returns a string representing the colour of a TrenchCoat.
    **/
    std::string getColour() const;

    /**
     * Returns a string representing the photograph of a TrenchCoat.
     **/
    std::string getPhotograph() const;

    /**
     * Returns an integer representing the size of a TrenchCoat.
     **/
	int getSize() const;

    /**
     * Returns an integer representing the quantity of a TrenchCoat.
     **/
	int getQuantity() const;

    /**
     * Returns a float representing the price of a TrenchCoat.
     **/
	float getPrice() const;

    /**
     * Sets the colour of a TrenchCoat to the provided colour.
     * Input: reference to a const std::string representing the new colour of the TrenchCoat.
     **/
	void setColour(const std::string &colour);

    /**
     * Sets the photograph of a TrenchCoat to the provided photograph.
     * Input: reference to a const std::string representing the link to the new photograph of the TrenchCoat.
     **/
	void setPhotograph(const std::string &photograph);

    /**
     * Sets the size of a TrenchCoat to the provided size.
     * Input: an integer representing the new size of the TrenchCoat.
     **/
	void setSize(int size);

    /**
     * Sets the quantity of a TrenchCoat to the provided quantity.
     * Input: an integer representing the new quantity of the TrenchCoat.
     **/
	void setQuantity(int quantity);

    /**
     * Sets the price of a TrenchCoat to the provided price.
     * Input: a float representing the new price of the TrenchCoat.
     **/
	void setPrice(float price);

    friend std::ostream& operator<<(std::ostream& os, const TrenchCoat& trench);
    friend std::istream& operator>>(std::istream& is, TrenchCoat& trench);
};