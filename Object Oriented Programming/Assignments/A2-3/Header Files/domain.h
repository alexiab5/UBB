#pragma once
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char* name;
    char* supplier;
    int quantity;
    struct tm expiration_date;
}Material;

Material* createMaterial(char* name, char* supplier, int quantity, struct tm expiration_date);

void destroyMaterial(Material* material);

Material* copyMaterial(Material* material);

char* getName(Material* material);

char* getSupplier(Material* material);

int getQuantity(Material* material);

struct tm getExpirationDate(Material* material);

void setName(Material* material, char name[]);

void setSupplier(Material* material, char supplier[]);

void setQuantity(Material* material, int quantity);

void setExpirationDate(Material* material, struct tm expiration_date);

int compareDates(struct tm date1, struct tm date2);

bool createDate(int year, int month, int day, struct tm* date);

void getDateRepresentation(struct tm date, char date_repr[80]);

void toString(Material* material, char str[]);

