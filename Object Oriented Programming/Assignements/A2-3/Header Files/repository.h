#pragma once
#include "domain.h"
#include "dynamic_array.h"
#include <stdbool.h>
#include <assert.h>

typedef struct {
    DynamicArray* materials;
}BakeryRepository;

BakeryRepository* createRepository();

/// <summary>
/// Adds a new material to the repository. If the material already exists, its quantity will be updated.
/// </summary>
/// <param name="material">= the material to be added.</param> <param name="repository">= the repository.</param>
/// <returns>0 if the material could not be added, 1 if it was added to repo, 2 if it was updated</returns>
int addMaterial(Material* material, BakeryRepository* repository);

/// <summary>
/// Removes a material from the repository.
/// </summary>
/// <param name="material">= the material to be removed.</param> <param name="repository">= the repository.</param>
/// <returns>0 if the material was successfully removed, 1 otherwise</returns>
bool removeMaterial(Material* material, BakeryRepository* repository);

/// <summary>
/// Updates a material in the repository.
/// </summary>
/// <param name="material">= the material to be updated.</param> <param name="new_material">= the new material.</param>
/// <returns>0 if the material was successfully updated, 1 otherwise</returns>
bool updateMaterial(Material* material, Material* new_material, BakeryRepository* repository);

/// <summary>
/// Returns in the parameter "result" a list of all materials having the provided supplier.
/// </summary>
void searchMaterialBySupplier(BakeryRepository* repository, char supplier[], Material** result, int* size);

/// <summary>
/// Searches for a specific material in repo.
/// Returns its actual position in the repository or -1 if it does not exist.
/// </summary>
int searchUniqueMaterial(Material material, BakeryRepository* repository);

/// <summary>
/// Returns in the parameter "materials" a list of all current materials in repo.
/// </summary>
void getAll(BakeryRepository* repository, Material* materials);

/// <summary>
/// Returns the size of a repository.
/// </summary>
int getSize(BakeryRepository* repository);

/// <summary>
/// Destroys the repository by deallocating its corresponding space.
/// </summary>
void destroyRepository(BakeryRepository* repository);

Material* getMaterialOnPos(BakeryRepository* v, int pos);
