#include "trenchCoatValidator.h"

ValidationException::ValidationException(std::string &_message) : message(_message) {}

const char *ValidationException::what() const noexcept {
    return this->message.c_str();
}

void TrenchCoatValidator::validateTrenchCoat(const TrenchCoat &trench) {
    std::string errors;
    // validate quantity
    if (trench.getQuantity() < 0)
        errors += "The quantity must be a positive integer.";
    // validate price
    if(trench.getPrice() < 0)
        errors += "The price must be a positive number.";
    // validate size
    int size = trench.getSize();
    if(size < 32 || size > 54 || size % 2 == 1)
        errors += "Sizes are between 32 and 54.";
    // validate photograph

    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.com\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");

    if (!std::regex_match(trench.getPhotograph(), pattern))
        errors += "Invalid photograph link";

    if(!errors.empty())
        throw ValidationException(errors);
}
