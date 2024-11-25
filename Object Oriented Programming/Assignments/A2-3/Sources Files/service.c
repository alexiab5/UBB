#include "service.h"

Service* createService(BakeryRepository* repository, OperationsStack* undoStack, OperationsStack* redoStack)
{
    Service* service = malloc(sizeof(Service));
    if (service == NULL)
        return NULL;
    service->repository = repository;
    service->undoStack = undoStack;
    service->redoStack = redoStack;
    return service;
}

bool addMaterialService(Service* service, Material* material)
{
    int quantity = getQuantity(material);
    int res = addMaterial(material, service->repository);
    if (res == 0) {
        Operation* o = createOperation(material, "add");
        push(service->undoStack, o);
        return 0;
    }
    else if (res == 2) // the material already existed and its quantity was updated
    {

        int pos = searchUniqueMaterial(*material, service->repository);
        Material* m = malloc(sizeof(Material));
        m = (Material*)get(service->repository->materials, pos);
        setQuantity(material, getQuantity(m) - quantity); // the original quantity

        Operation* o = createOperation(material, "update");
        push(service->undoStack, o);

        o = (Operation*)createOperation(m, "update");
        push(service->undoStack, o);
        destroyMaterial(material);
        return 0;
    }
    return 1;
}

bool removeMaterialService(Service* service, Material* material)
{
    Material *m = malloc(sizeof(Material));
    m = copyMaterial(material);
    bool res = removeMaterial(material, service->repository);
    if (res == 0) {
        Operation* o = createOperation(m, "remove");
        push(service->undoStack, o);
    }
    else{
        destroyMaterial(m);
    }
    return res;
}

bool updateMaterialService(Service* service, Material* material, Material *new_material)
{
    bool res = updateMaterial(material, new_material, service->repository);
    if (res == 0) {
        int pos = searchUniqueMaterial(*new_material, service->repository);
        Material* m = (Material*)get(service->repository->materials, pos);

        Operation* o = (Operation*)createOperation(new_material, "update");
        push(service->undoStack, o);
        o = (Operation*)(m, "update");
        push(service->undoStack, o);
    }
    return res;
}

void swap_materials(Material* material1, Material* material2)
{
    Material tmp = *material1;
    *material1 = *material2;
    *material2 = tmp;

}

void sort_materials_by_quantities(Material materials[], int length, bool order) {
    // order = 1 => ascending, 0 => descending
    for (int i = 0; i < length - 1; i ++) {
        for(int j = 0; j < length - 1; j ++)
            if (order == 1) {
                if (getQuantity(&materials[j]) > getQuantity(&materials[j + 1]))
                    swap_materials(&materials[j], &materials[j + 1]);

            }
            else {
                if (getQuantity(&materials[j]) < getQuantity(&materials[j + 1]))
                    swap_materials(&materials[j], &materials[j + 1]);
            }
    }

}

void filterMaterialsShortSupplyBySupplier(Service* service, char supplier[], int quantity, Material result[], int* size)
{
    Material* materials[CAPACITY];
    int size2 = 0;
    *size = 0;
    searchMaterialBySupplier(service->repository, supplier, materials, &size2);
    for (int i = 0; i < size2; i++) {
        if (getQuantity(materials[i]) <= quantity) {
            result[(*size)++] = *materials[i];
        }
    }
    sort_materials_by_quantities(result, *size, 1);
}

/*
Function checks if a string contains another string
*/
bool StringContains(char* string1, char* string2)
{
    // search for string2 in string1
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int current_index = 0;
    for (int i = 0; i < length1; i++) {
        if (current_index < length2 && string1[i] == string2[current_index])
            current_index++;
        else {
            if (current_index == length2)
                return true;
            current_index = 0;
        }
    }
    if (current_index == length2)
        return true;
    return false;
}

void filterMaterialsPastExpirationDateByName(Service* service, char* string, Material* result, int* size)
{
    Material materials[CAPACITY];
    int size2 = 0;
    *size = 0;
    getAllService(service, materials, &size2);
    for (int i = 0; i < size2; i++) {
        // getting current date
        time_t raw_date;
        time(&raw_date);
        struct tm* current_date;
        current_date = localtime(&raw_date);
        if (strcmp(string, "") == 0){
            if (compareDates(getExpirationDate(&materials[i]), *current_date) < 0) {
                result[*size] = materials[i];
                *size = *size + 1;
            }
        }
        else {
            if (compareDates(getExpirationDate(&materials[i]), *current_date) < 0 && StringContains(getName(&materials[i]), string)) {
                result[*size] = materials[i];
                *size = *size + 1;
            }
        }
    }
}

void getAllService(Service* service, Material* materials, int* size)
{	getAll(service->repository, materials);
    *size = getSize(service->repository);
}

void destroyService(Service* service)
{
    destroyRepository(service->repository);
    destroyStack(service->undoStack);
    destroyStack(service->redoStack);
    free(service);
}

bool undoService(Service* service)
{
    if (isEmpty(service->undoStack)) {
        return 1;
    }

    Operation* operation = pop(service->undoStack);
    if (strcmp(getOperationType(operation), "add") == 0) {
        Material* material = getMaterial(operation);
        Material* m2 = malloc(sizeof(Material));
        m2 = copyMaterial(material);
        Operation* op2 = createOperation(m2, "add");

        free(operation->operationType);
        free(operation);

        removeMaterial(material, service->repository);
        push(service->redoStack, op2);
    }
    else if (strcmp(getOperationType(operation), "remove") == 0) {
        Material* material = getMaterial(operation);
        addMaterial(material, service->repository);
        push(service->redoStack, operation);
    }
    else if (strcmp(getOperationType(operation), "update") == 0) {
        Operation* operation2 = pop(service->undoStack);
        Material* current_material = getMaterial(operation);
        Material* old_material = getMaterial(operation2);

        updateMaterial(current_material, old_material, service->repository);
        push(service->redoStack, operation); // old current material
        push(service->redoStack, operation2); // new current material
    }

    //destroyOperation(operation);

    return 0;
}

bool redoService(Service* service)
{
    if (isEmpty(service->redoStack)) {
        return 1;
    }

    Operation* operation = pop(service->redoStack);
    if (strcmp(getOperationType(operation), "add") == 0) {
        Material* material = getMaterial(operation);
        addMaterial(material, service->repository);
        push(service->undoStack, operation);
    }
    else if (strcmp(getOperationType(operation), "remove") == 0) {
        Material* material = getMaterial(operation);
        Material* m2 = malloc(sizeof(Material));
        m2 = copyMaterial(material);
        Operation* op2 = createOperation(m2, "add");

        free(operation->operationType);
        free(operation);

        removeMaterial(material, service->repository);
        push(service->redoStack, op2);
    }
    else if (strcmp(getOperationType(operation), "update") == 0) {
        Operation* operation2 = pop(service->redoStack);
        Material* new_material = getMaterial(operation);
        Material* old_material = getMaterial(operation2);

        updateMaterial(new_material, old_material, service->repository);
        push(service->undoStack, operation);
        push(service->undoStack, operation2);
    }

    //destroyOperation(operation);

    return 0;
}