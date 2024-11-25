#pragma once
#include "repository.h"
#include "operations_stack.h"

typedef struct {
    BakeryRepository* repository;
    OperationsStack* undoStack;
    OperationsStack* redoStack;
}Service;

Service* createService(BakeryRepository* repository, OperationsStack* undoStack, OperationsStack* redoStack);

/// <summary>
/// Adds a new material to the repository. If the material already exists, its quantity will be updated.
/// </summary>
/// <param name="material">= the material to be added.</param> <param name="repository">= the repository.</param>
/// <returns>0 if the material could not be added, 1 if it was added to repo.</returns>
bool addMaterialService(Service* service, Material* material);

/// <summary>
/// Removes a material from the repository.
/// </summary>
/// <param name="material">= the material to be removed.</param> <param name="repository">= the repository.</param>
/// <returns>0 if the material was successfully removed, 1 otherwise</returns>
bool removeMaterialService(Service* service, Material* material);

/// <summary>
/// Updates a material in the repository.
/// </summary>
/// <param name="material">= the material to be updated.</param> <param name="new_material">= the new material.</param>
/// <returns>0 if the material was successfully updated, 1 otherwise</returns>
bool updateMaterialService(Service* service, Material* material, Material* new_material);

void swap_materials(Material* material1, Material* material2);

/// <summary>
/// Sorts a list of materials ascending or descending by their quantities.
/// order = 1 => ascending order = 0 => descending
/// </summary>
void sort_materials_by_quantities(Material materials[], int length, bool order);

/// <summary>
/// Returns in the parameter "result" a sorted list of all materials having the provided supplier and the quantity <= than the provided quantity.
/// </summary>
void filterMaterialsShortSupplyBySupplier(Service* service, char supplier[], int quantity, Material result[], int* size);

/// <summary>
/// Returns in the parameter "result" a list of all materials past their expiration date, considering the actual date of today.
/// </summary>
void filterMaterialsPastExpirationDateByName(Service* service, char* material_name, Material* result, int* size);

/// <summary>
/// Returns in the parameter "result" a list of all materials past their expiration date, considering the actual date of today.
/// </summary>
void getAllService(Service* service, Material* materials, int* size);

void destroyService(Service* service);

/// <summary>
/// Undo the last operation.
/// Returns 0 if the operation was successfully undone, 1 otherwise.
/// </summary>
bool undoService(Service* service);

/// <summary>
/// Redo the last operation.
/// Returns 0 if the operation was successfully redone, 1 otherwise.
/// </summary>
bool redoService(Service* service);

