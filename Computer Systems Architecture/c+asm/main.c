#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Read from the keyboard a string of numbers, given in the base 10 as signed numbers (a string of characters is read from the keyboard 
// and a string of numbers must be stored in the memory).

int main(){
    char input_numbers_string[100] = "";
    int numbers_array[100];
    char current_digits_array[100] = "";
    printf("Enter the string of numbers in base 10, separated by commas: ");
    scanf("%s", input_numbers_string);
    
    char character = input_numbers_string[0];
    int number_of_digits = 0;
    int numbers_count = 0;
    int i = 0;

    while(character != '\0'){
        if (character == ','){
            int number = convert_char_to_int(current_digits_array, number_of_digits);
            numbers_array[numbers_count++] = number;
            number_of_digits = 0;
        }
        else{
            current_digits_array[number_of_digits++] = character; 
        }
        character = input_numbers_string[++i];
    }
    int number = convert_char_to_int(current_digits_array, number_of_digits);
    numbers_array[numbers_count++] = number;
    printf("The numbers are: ");
    for(int i = 0; i < numbers_count; i++){
        printf("%d ", numbers_array[i]);
    }
    return 0;
}