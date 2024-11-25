#pragma once
#include "service.h"
#include <stdio.h>
#include <string.h>
#define ADD "a"
#define DELETE "b"
#define UPDATE "c"
#define DISPLAY_BY_DATE "d"
#define DISPLAY_BY_SUPPLIER "e"
#define DISPLAY_ALL "f"
#define UNDO "g"
#define REDO "h"
#define EXIT "i"

typedef struct {
    Service* service;
}ConsoleUI;

ConsoleUI* createUI(Service* service);

Material* getMaterialInputADD();

Material* getMaterialInputUPDATE();

void readStringWithSpaces(const char* message, int maxStrSize, char str[]);

int readIntegerNumber(const char* message);

void printMenu();

void start(ConsoleUI* ui);

void print_materials(ConsoleUI* ui);

void destroyUI(ConsoleUI* ui);