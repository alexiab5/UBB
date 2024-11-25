#include "repository.h"
#include <string.h>
#include <stdbool.h>

BakeryRepository* createRepository()
{
    BakeryRepository* repository = malloc(sizeof(BakeryRepository));
    if (repository == NULL)
        return NULL;
    repository->materials = createDynamicArray(100, &destroyMaterial);
    return repository;
}

int addMaterial(Material* material, BakeryRepository* repository)
{
    // material = uniquely identified by name, supplier and quantity
    Material** materials = repository->materials->elems;
    int pos = searchUniqueMaterial(*material, repository);
    if (pos == -1) {
        return addElement(repository->materials, material);
    }
    else {
        setQuantity(materials[pos], getQuantity(materials[pos]) + getQuantity(material));
        return 2;
    }
}

bool removeMaterial(Material* material, BakeryRepository* repository)
{
    int pos = searchUniqueMaterial(*material, repository);
    if (pos == -1) {
        return 1; // the material does not exist
    }
    return deleteElementAtPosition(repository->materials, pos);
}

bool updateMaterial(Material* material, Material* new_material, BakeryRepository* repository)
{
    Material** materials = repository->materials->elems;
    int pos = searchUniqueMaterial(*material, repository);
    if (pos == -1){
        return 1; // the material does not exist
    }
    setName(materials[pos], getName(new_material));
    setQuantity(materials[pos], getQuantity(new_material));
    setSupplier(materials[pos], getSupplier(new_material));
    setExpirationDate(materials[pos], getExpirationDate(new_material));
    return 0;
}

void searchMaterialBySupplier(BakeryRepository* repository, char supplier[], Material** result, int* size)
{
    int length = getLength(repository->materials);
    *size = 0;
    for (int i = 0; i < length; i++) {
        Material* m = (Material*)get(repository->materials, i);
        if (strcmp(getSupplier(m), supplier) == 0) {
            result[(*size)++] = m;
        }
    }
}

/*
* returns the position of a specific material in the repository or -1 if it does not exist.
*/
int searchUniqueMaterial(Material material, BakeryRepository* repository)
{
    int length = getLength(repository->materials);
    char* name = getName(&material);
    struct tm expiration_date = getExpirationDate(&material);
    char* supplier = getSupplier(&material);
    for (int i = 0; i < length; i++) {
        Material* m = (Material*)get(repository->materials, i);
        if (strcmp(getName(m), name) == 0 && strcmp(getSupplier(&material), supplier) == 0 &&
            compareDates(getExpirationDate(m), getExpirationDate(&material)) == 0)
            return i;
    }
    return -1;
}

void getAll(BakeryRepository* repository, Material* materials)
{
    int length = getLength(repository->materials);
    for (int i = 0; i < length; i++) {
        Material* m = (Material*)get(repository->materials, i);
        materials[i] = *m;
    }
}

int getSize(BakeryRepository* repository)
{
    return getLength(repository->materials);
}


void destroyRepository(BakeryRepository* repository)
{
    destroyDynamicArray(repository->materials);
    free(repository);
}

Material* getMaterialOnPos(BakeryRepository* v, int pos)
{
    if (v == NULL)
        return NULL;
    Material* p = (Material*)get(v->materials, pos);
    return p;
}

