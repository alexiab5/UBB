#include "ui.h"
#include "tests.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//Tests::testAll();
    Repository r{"trenchCoats.txt"};
    Service s{r, "csv"};
	UI ui{s};
	ui.start();
}

