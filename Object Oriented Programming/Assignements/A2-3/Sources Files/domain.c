#include "domain.h"
#include <stdio.h>

Material* createMaterial(char* name, char* supplier, int quantity, struct tm expiration_date)
{
    Material* material = malloc(sizeof(Material));
    if (material == NULL)
        return NULL;

    material->name = malloc(sizeof(char) * strlen(name) + 1);
    if (material->name == NULL) {
        free(material);
        return NULL;
    }
    strcpy(material->name, name);

    material->supplier = malloc(sizeof(char) * strlen(supplier) + 1);
    if (material->supplier == NULL) {
        free(material->name);
        free(material);
        return NULL;
    }
    strcpy(material->supplier, supplier);

    material->expiration_date = expiration_date;
    material->quantity = quantity;
    return material;
}

void destroyMaterial(Material* material)
{
    if (material == NULL)
        return;

    free(material->name);
    material->name = NULL;
    free(material->supplier);
    material->supplier = NULL;
    free(material);
    material = NULL;
}

Material* copyMaterial(Material* material)
{
    if (material == NULL)
        return NULL;

    Material* new_material;
    new_material = createMaterial(material->name, material->supplier, material->quantity, material->expiration_date);
    return new_material;
}


char* getName(Material* material)
{
    return material->name;
}

char* getSupplier(Material* material)
{
    return material->supplier;
}

int getQuantity(Material* material)
{
    return material->quantity;
}

struct tm getExpirationDate(Material* material)
{
    return material->expiration_date;
}

void setName(Material* material, char name[])
{
    strcpy(material->name, name);
}

void setSupplier(Material* material, char supplier[])
{
    strcpy(material->supplier, supplier);
}

void setQuantity(Material* material, int quantity)
{
    material->quantity = quantity;
}

void setExpirationDate(Material* material, struct tm expiration_date)
{
    material->expiration_date = expiration_date;
}

int compareDates(struct tm date1, struct tm date2)
{
    time_t t1 = mktime(&date1);
    time_t t2 = mktime(&date2);
    double diffSecs = difftime(t1, t2);
    if (diffSecs == 0)
        return 0;
    if (diffSecs > 0)
        return 1;
    return -1;
}

bool createDate(int year, int month, int day, struct tm* date)
{
    if (day < 1 || day > 31)
        return 1;
    if (year < 2000)
        return 1;
    if (month < 1 || month > 12)
        return 1;
    date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = day;
    date->tm_wday = 1;
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_yday = 0;
    date->tm_isdst = 0;
    return 0;
}

void getDateRepresentation(struct tm date, char date_repr[80])
{
    strftime(date_repr, 80, "%Y-%m-%d", &date);
}

void toString(Material material[], char str[])
{
    if (material == NULL)
        return;
    char expiration_date[80] = "";
    getDateRepresentation(material->expiration_date, expiration_date);
    sprintf(str, "Name = %s Supplier = %s Quantity = %d Expiration date = %s", material->name, material->supplier, material->quantity, expiration_date);
}
