#include <iostream>
#include "tasksgui.h"
#include "repository.h"
#include <QApplication>

int main(int argc, char** argv) {
        QApplication a(argc, argv);
        Repository r{"tasks.txt"};
        TasksGUI gui{r};
        gui.show();
        return a.exec();
}
