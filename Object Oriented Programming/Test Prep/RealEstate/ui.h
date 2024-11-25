#pragma once
#ifndef T2_2_UI_H
#define T2_2_UI_H
#include "realEstateAgency.h"
#endif //T2_2_UI_H

class ConsoleUI{
private:
    RealEstateAgency* agency;
    void addDwellingUI();
    void removeClientUI();
    void writeToFileUI();
    void showAllClientsAndDwellings();
public:
    ConsoleUI(RealEstateAgency* agency);
    //~ConsoleUI();
    void startConsoleUI();
};