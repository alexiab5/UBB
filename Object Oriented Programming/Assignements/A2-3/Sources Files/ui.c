#include "ui.h"

ConsoleUI* createUI(Service* service)
{
    ConsoleUI* ui = malloc(sizeof(ConsoleUI));
    if (ui == NULL)
        return NULL;
    ui->service = service;
    return ui;
}

/*
	Reads a string with spaces from the standard input.
	Input:	message - string, message to be shown to the user.
			maxStrSize - the maximum size for the string to be read
	Output: the string that was read.
*/
void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
    char c;
    while (strcmp(str, "") == 0) {
        printf(message);
        fgets(str, maxStrSize, stdin);
        // the newline is also read so we must eliminate it from the string
        size_t size = strlen(str) - 1;
        if (str[size] == '\n')
            str[size] = '\0';
    }
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
    char s[16];
    int res = 0;
    int flag = 0;
    int r = 0;

    while (flag == 0)
    {
        printf(message);
        scanf("%s", s);

        r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
        flag = (r == 1);
        if (flag == 0)
            printf("Error reading number!\n");
    }
    //
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return res;
}


Material* getMaterialInputADD()
{
    char name[50] = "", supplier[50] = "";
    int quantity = 0, day = 0, month = 0, year = 0;
    readStringWithSpaces("Name of the material: ", 50, name);
    readStringWithSpaces("Supplier of the material: ", 50, supplier);
    quantity = readIntegerNumber("Quantity of the material: ");
    printf("\nExpiration date:\n");
    year = readIntegerNumber("Year: ");
    month = readIntegerNumber("Month: ");
    day = readIntegerNumber("Day: ");
    struct tm expiration_date;
    bool invalid = createDate(year, month, day, &expiration_date);
    if (invalid)
        return NULL;
    Material* raw_material;
    raw_material = createMaterial(name, supplier, quantity, expiration_date);
    return raw_material;
}

Material* getMaterialInputUPDATE()
{
    char name[50] = "", supplier[50] = "";
    int quantity = 0, day = 0, month = 0, year = 0;
    readStringWithSpaces("Name of the material: ", 50, name);
    readStringWithSpaces("Supplier of the material: ", 50, supplier);
    printf("\nExpiration date:\n");
    year = readIntegerNumber("Year: ");
    month = readIntegerNumber("Month: ");
    day = readIntegerNumber("Day: ");
    struct tm expiration_date;
    bool invalid = createDate(year, month, day, &expiration_date);
    if (invalid)
        return NULL;
    Material* raw_material;
    raw_material = createMaterial(name, supplier, quantity, expiration_date);
    return raw_material;
}

void printMenu()
{
    printf("***************** BAKERY APPLICATION **************\n");
    printf("a. ADD a raw material\n");
    printf("b. DELETE a raw material\n");
    printf("c. UPDATE a raw material\n");
    printf("d. See all available materials past their expiration date, containing a given string\n");
    printf("e. Display all materials from a given supplier, which are in short supply, sorted ascending by their quantities.\n");
    printf("f. Display all materials currently in repository.\n");
    printf("g. UNDO\n");
    printf("h. REDO\n");
    printf("i. EXIT\n");
    printf("*****************************************************\n");
}

void print_materials(ConsoleUI* ui)
{
    printf("Current raw materials in repo:\n");
    Material materials[100];
    int size = 0;
    getAllService(ui->service, materials, &size);
    for (int i = 0; i < size; i++) {
        char str[200] = "";
        toString(&materials[i], str);
        printf("%s\n", str);
    }
}

void start(ConsoleUI* ui)
{
    while (1) {
        printMenu();

        char user_option[50] = "";
        printf("Enter the letter of the action you wish to perform: ");
        fgets(user_option, 50, stdin);
        size_t size = strlen(user_option) - 1;
        if (user_option[size] == '\n')
            user_option[size] = '\0';

        if (strcmp(user_option, ADD) == 0) {
            printf("\n*** Adding a raw material ***\n");
            Material* material = NULL;
            material = getMaterialInputADD();
            if (material != NULL) {
                addMaterialService(ui->service, material);
                printf("Material was successfully added!\n");
                print_materials(ui);
            }
            else {
                printf("Invalid material! Couldn't be added to the bakery repository!\n");
                destroyMaterial(material);
            }
        }
        else if (strcmp(user_option, UPDATE) == 0) {
            printf("\n*** Updating a raw material ***\n");
            printf("Enter the data of the material you wish to update:\n");
            Material* material = NULL;
            material = getMaterialInputUPDATE();
            if (material != NULL) {
                Material* new_material = NULL;
                printf("Enter the data of the new material:\n");
                new_material = getMaterialInputADD();
                if (new_material != NULL) {
                    bool not_updated = updateMaterialService(ui->service, material, new_material);
                    if (not_updated) {
                        printf("The material does not currently exist in the bakery repository.\n");
                    }
                    else {
                        printf("Material was successfully updated!\n");
                        print_materials(ui);
                    }
                }
                else {
                    printf("Invalid material!\n");
                }
            }
            else
                printf("Invalid material!\n");
        }
        else if (strcmp(user_option, DELETE) == 0) {
            printf("\n*** Deleting a raw material ***\n");
            Material* material = NULL;
            material = getMaterialInputUPDATE();
            if (material != NULL) {
                char str[200] = "";
                toString(material, str);
                printf("%s\n", str);

                bool not_removed = removeMaterialService(ui->service, material);
                if (not_removed) {
                    printf("The material does not currently exist in the bakery repository.\n");
                }
                else {
                    printf("Material was successfully deleted!\n");
                    print_materials(ui);
                }
            }
            else
                printf("Invalid material!");
            destroyMaterial(material);
        }
        else if (strcmp(user_option, DISPLAY_ALL) == 0) {
            print_materials(ui);
        }
        else if (strcmp(user_option, DISPLAY_BY_DATE) == 0) {
            int c;
            // get rid of whitespaces in the input buffer before reading the string
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter a string: ");
            char string[50] = "";
            fgets(string, 50, stdin);
            string[strlen(string) - 1] = '\0';
            Material result[100];
            int size = 0;
            filterMaterialsPastExpirationDateByName(ui->service, string, result, &size);
            if (size == 0)
                printf("There are no materials past expiration date containing that string.\n");
            else {
                printf("Materials past expiration date containing the given string:\n");
                for (int i = 0; i < size; i++) {
                    char s[80] = "";
                    getDateRepresentation(getExpirationDate(&result[i]), s);
                    printf("%s %s %d %s\n", getName(&result[i]), getSupplier(&result[i]),
                           getQuantity(&result[i]), s);
                }
            }
        }
        else if (strcmp(user_option, DISPLAY_BY_SUPPLIER) == 0) {
            char supplier[50] = "";
            readStringWithSpaces("Name of the supplier: ", 80, supplier);
            int quantity = 0;
            quantity = readIntegerNumber("Quantity: ");
            Material materials[CAPACITY];
            int size = 0;
            filterMaterialsShortSupplyBySupplier(ui->service, supplier, quantity, materials, &size);
            printf("Materials in short supply from %s:\n", supplier);
            for (int i = 0; i < size; i++) {
                char str[200] = "";
                toString(&materials[i], str);
                printf("%s\n", str);
            }
        }
        else if (strcmp(user_option, UNDO) == 0) {
            bool res = undoService(ui->service);
            if (res == 1) {
                printf("No undos available!\n");
            }
            else {
                print_materials(ui);
            }
        }
        else if (strcmp(user_option, REDO) == 0) {
            bool res = redoService(ui->service);
            if (res == 1) {
                printf("No redos available!\n");
            }
            else {
                print_materials(ui);
            }
        }
        else if (strcmp(user_option, EXIT) == 0) {
            printf("Exiting application...\n");
            break;
        }
        else {
            printf("Invalid option!\n");
        }
    }

}

void destroyUI(ConsoleUI* ui)
{
    destroyService(ui->service);
    free(ui);
}