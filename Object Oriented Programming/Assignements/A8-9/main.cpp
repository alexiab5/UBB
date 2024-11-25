#include "ui.h"
#include "appGUI.h"
#include "tests.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	//Tests::testAll();
    QApplication a(argc, argv);
    Repository r{"trenchCoats.txt"};
    Service s{r, "csv"};
//	UI ui{s};
//	ui.start();
    GUI gui{s};
    gui.show();

    return a.exec();
}

