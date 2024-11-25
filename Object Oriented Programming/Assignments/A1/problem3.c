# include <stdio.h>
# include <stdbool.h>
# define MAX_LENGTH 1000
/*
    3.
    **a.** Print the Pascal triangle of dimension `n` of all combinations `C(m,k)` of m objects taken by `k, k = 0, 1, ..., m`, for line `m, where m = 1, 2, ..., n`.\
    **b.** Given a vector of numbers, find the longest contiguous subsequence of prime numbers.
*/


/*
    * The function prints a vector of numbers on the console.
    * Input: A vector of integer numbers and the length of the vector.
    * Output: -
 */
void print_numbers(int numbers_list[MAX_LENGTH], int list_length) {

    for (int i = 0; i < list_length; i++) {
        printf("%d ", numbers_list[i]);
    }
    printf("\n");
}


/*
    * The function reads a list of numbers from the keyboard and returns the number of numbers that were read.
    * Input: The vector where the numbers will be stored.
    * Output: The number of numbers that were read.
*/
int read_numbers(int numbers_list[MAX_LENGTH]) {

    printf("Enter the length of the vector: ");
    int number = 0;
    scanf_s("%d", &number);
    printf("Enter a vector of %d numbers: ", number);
    for (int i = 0; i < number; i++) {
        scanf_s("%d", &numbers_list[i]);
    }
    return number;
}

/*
    The function prints the Pascal triangle of dimension n.
    Input: the dimension of the triangle
*/
void print_pascal_triangle_1(int dimension) {
    int triangle[MAX_LENGTH];
    for (int i = 0; i <= dimension; i++) {
        triangle[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            triangle[j] = triangle[j - 1] + triangle[j];
        }
        triangle[0] = 1;
        print_numbers(triangle, i + 1);
    }
}

/*
    * The function determines the value of C(n, k) (Combinations of n objects taken k).
    * Input: n and k - integer numbers
    * Output: C(n, k)
*/
int combinations_n_taken_k(int n, int k) {
    double combinations = 1;
    for (int i = 1; i <= k; i++)
        combinations = combinations * (n - k + i) / i;
    return (int)combinations;
}

/*
    The function prints the Pascal triangle of dimension n.
    Input: the dimension of the triangle
*/
void print_pascal_triangle_2(int dimension) {
    for (int i = 0; i <= dimension; i++) {
        for (int j = 0; j <= i; j++) {
            int combinations;
            combinations = combinations_n_taken_k(i, j);
            printf("%d ", combinations);
        }
        printf("\n");
    }

}

/*
    * The function checks if a number if prime or not.
    * Input: an integer number
    * Output: true if the number if prime, false otherwise
*/
bool is_prime(int number) {
    if (number < 2)
        return false;
    if (number % 2 == 0 && number != 2)
        return false;
    for (int d = 3; d * d <= number; d += 2)
        if (number % d == 0)
            return false;
    return true;
}

/*
    * The function determines the longest contiguous subsequence of primes from a given vector.
    * Input: a vector of integer numbers and its length, the vector where the longest subsequence will be stored and its length.
    * Output: the function returns through its last 2 parameters the subsequence with the given propery, as well as its length.
*/
void determine_longest_contiguous_subsequence_primes(int numbers_list[MAX_LENGTH], int length, int longest_subsequence[MAX_LENGTH], int* longest_subsequence_length) {
    int i = 0, current_length = 0, starting_index = -1;
    *longest_subsequence_length = 0;
    while (i < length) {
        if (is_prime(numbers_list[i])) {
            current_length += 1;
        }
        else {
            if (current_length > *longest_subsequence_length) {
                *longest_subsequence_length = current_length;
                starting_index = i - current_length;
            }
            current_length = 0;
        }
        i += 1;
    }

    if (current_length > *longest_subsequence_length) {
        *longest_subsequence_length = current_length;
        starting_index = i - current_length;
    }

    for (int i = 0; i < *longest_subsequence_length; i++)
        longest_subsequence[i] = numbers_list[starting_index + i];
}

/*
*   The function prints the menu of the application.
*/
void print_menu()
{
    printf("           *********************   MAIN MENU   *********************\n");
    printf("1. Print the Pascal triangle of dimension n.\n");
    printf("2. Enter a vector of numbers.\n");
    printf("3. Find the longest contiguous subsequence of prime numbers in the vector.\n");
    printf("4. Exit the program.\n");
    printf("Enter the number of the action you wish to perform: ");
}

/*
*   The function runs the required application.
*/
void run_menu() {

    const int READ_NUMBERS = 2, PRINT_PASCAL = 1, FIND_SUBSEQUENCE = 3, EXIT = 4;
    int current_numbers[MAX_LENGTH], current_length = 0;

    while (true) {

        int user_option;

        print_menu();
        scanf_s("%d", &user_option);

        if (user_option == READ_NUMBERS) {
            current_length = read_numbers(current_numbers);
            //print_numbers(current_numbers, current_length);
        }

        else if (user_option == PRINT_PASCAL) {
            int dimension;
            printf("Enter the dimension of the Pascal triangle: ");
            scanf_s("%d", &dimension);
            if (dimension <= 0)
                printf("Dimension must be a positive integer.");
            else
                print_pascal_triangle_2(dimension);
        }

        else if (user_option == FIND_SUBSEQUENCE) {

            if (current_length <= 0) {
                printf("The vector of numbers is empty!");
            }

            else {
                int longest_subsequence[MAX_LENGTH], max_length;
                determine_longest_contiguous_subsequence_primes(current_numbers, current_length, longest_subsequence, &max_length);
                if (max_length == 0) {

                    printf("There is no contiguos subsequence of prime numbers in: ");
                    print_numbers(current_numbers, current_length);
                }
                else {
                    printf("The longest contiguos subsequence of prime numbers in: ");
                    print_numbers(current_numbers, current_length);
                    print_numbers(longest_subsequence, max_length);
                }
            }
        }

        else if (user_option == EXIT) {
            break;
        }

        else {
            printf("Invalid option!");
        }
    }

}

int main(int argc, char** argv) {

    run_menu();

    return 0;
}