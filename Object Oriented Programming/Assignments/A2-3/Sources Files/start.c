#include "start.h"

int main()
{
    BakeryRepository* repo;
    repo = createRepository();

    // tests
    testAll();

    // adding materials in repo
    struct tm date;
    createDate(2023, 2, 17, &date);
    addMaterial(createMaterial("banana", "ceva", 50, date), repo);
    createDate(2024, 3, 12, &date);
    addMaterial(createMaterial("eggs", "Agricola", 50, date), repo);
    createDate(2025, 4, 10, &date);
    addMaterial(createMaterial("flour", "White Lily", 100, date), repo);
    createDate(2024, 5, 5, &date);
    addMaterial(createMaterial("brown sugar", "Woodstock Farms", 250, date), repo);
    createDate(2025, 3, 11, &date);
    addMaterial(createMaterial("white sugar", "King Arthur", 300, date), repo);
    createDate(2023, 12, 17, &date);
    addMaterial(createMaterial("vanilla essence", "ceva", 20, date), repo);
    createDate(2023, 3, 17, &date);
    addMaterial(createMaterial("cinnamon", "ceva", 13, date), repo);
    createDate(2024, 5, 24, &date);
    addMaterial(createMaterial("oat milk", "ceva", 100, date), repo);
    createDate(2024, 2, 17, &date);
    addMaterial(createMaterial("almond milk", "fbevsd", 150, date), repo);
    createDate(2024, 3, 15, &date);
    addMaterial(createMaterial("spices", "fbevsd", 250, date), repo);

    Service* service;
    OperationsStack* undoStack = createStack();
    OperationsStack* redoStack = createStack();
    service = createService(repo, undoStack, redoStack);
    ConsoleUI* ui;
    ui = createUI(service);
    start(ui);

    destroyUI(ui);

    exit(0);
}