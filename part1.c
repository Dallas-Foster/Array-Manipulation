/*
 * Array Manipulator: By Dallas Foster, 251287541
 *
 * The purpose of this program is to manipulate a user entered array in various ways. The program will first prompt
 * the user to input the sie of the array, ensuring that the size falls between 5 and 12 integers. The first manipulation
 * of the array prints out the elements of the array in order. The second manipulation prints out the array in
 * reverse as well as reversing the indexes. The third manipulation finds all the even numbers in the user inputted
 * array, and also their position in the array. The fourth manipulation prints the sum of all the elements in the array.
 * The fifth manipulation prints out the elements of the array in ascending order as well as their specific position.
 * The sixth manipulation will swap the first and last elements of the array and their positions, then print ou the new
 * array.
 *
 */

#include <stdio.h>

// Function to get the number of integers the user wants to process (between 5 and 12)
int get_integer_count() {
    int count;
    do {
        printf("Please enter the number of integers to process: "); //Prompt the user to enter size of array
        scanf("%d", &count);
        if (count < 5 || count > 12) {
            printf("Please enter a number between 5 and 12.\n");
        }
    } while (count < 5 || count > 12); // Continue prompting until a valid count is entered

    // Return the valid count and size of array in bytes
    printf("\tThere is enough room in your array for %d integers (%d bytes)\n\n", count, count * sizeof(int));
    return count;
}

// Function to get integers from the user and store them in an array
void get_integers(int count, int integers[]) {
    printf("Please enter your integers separated by spaces: ");
    for (int i = 0; i < count; i++) {
        scanf("%d", &integers[i]); // Read integers from the user and store them in the array
    }
}

// Function to display the array elements in the original order
void part1(int count, int integers[]) {
    printf("\n%s:\n\t%s", "Part 1", "Your array is: "); // Output formatting

    char *joiner = ""; // Used for formatting the output
    for (int i = 0; i < count; i++) { // Loop through the array
        printf("%s[%d] = %d", joiner, i, integers[i]); // Print elements of the array
        joiner = ", "; // Add a comma and space for formatting
    }
    printf("\n");
}

// Function to display the array elements in reverse order
void part2(int count, int integers[]) {
    printf("\n%s:\n\t%s", "Part 2", "Your array in reverse is: ");

    char *joiner = ""; // Used for formatting the output
    for (int i = count - 1; i >= 0; i--) {
        printf("%s[%d] = %d", joiner, i, integers[i]); // Print elements of the array in reverse order
        joiner = ", "; // Add a comma and space for formatting
    }
    printf("\n");
}

// Function to display the even elements in the array
void part3(int count, int integers[]) {
    printf("\n%s:\n\t%s", "Part 3", "The even element in the array is: ");

    char *joiner = ""; // Used for formatting the output
    for (int i = 0; i < count; i++) {
        if (integers[i] % 2 == 0) {
            printf("%s[%d] = %d", joiner, i, integers[i]); // Print even elements of the array
            joiner = ", "; // Add a comma and space for formatting
        }
    }
    printf("\n");
}

// Function to calculate and display the sum of all values in the array
void part4(int count, int integers[]) {
    int totalSum = 0;
    for (int i = 0; i < count; i++) {
        totalSum += integers[i]; // Calculate the sum of all values in the array
    }
    printf("\nPart 4:\n\tThe sum of all values in your array is: %d\n", totalSum);
}

// Function to sort the array and display the sorted order
void part5(int count, int integers[]) {
    printf("\n%s:\n\t%s", "Part 5", "Your array in sorted order is: ");

    // Create an array to store the order of elements in the sorted array
    int orderArray[count];
    // Initialize the orderArray with -1
    for (int i = 0; i < count; i ++) {
        orderArray[i] = -1;
    }
    // Initialize variables for tracking local and global maximum values
    int localMaximum = 0;
    int globalMaximum = 0;
    // Loop through the elements of the orderArray in reverse order
    for (int i = count - 1; i >= 0; i --) {
        // Iterate through the original 'integers' array to find the next element to include
        for (int j = 0; j < count; j ++)  {
            int used = 0;
            // Check if the 'j' index has already been used in 'orderArray'
            for (int k = 0; k < count; k ++) {
                if (orderArray[k] == j) {
                    used = 1;
                }
            }
            /*
             * If 'j' is not used and its value is greater than or equal to localMaximum and less than or equal
             * to globalMaximum (or either maximum is zero), assign it to the current position in 'orderArray'
             * and update localMaximum.
             */
            if (used == 0 && (integers[j] >= localMaximum || localMaximum == 0) && (integers[j] <= globalMaximum || globalMaximum == 0)) {
                orderArray[i] = j;
                localMaximum = integers[j];
            }
        }
        // Update the globalMaximum with the localMaximum
        globalMaximum = localMaximum;
        localMaximum = 0;
    }

    char *joiner = ""; // Used for formatting
    // Loop through the sorted order in 'orderArray' and print the corresponding elements
    for (int i = 0; i < count; i ++) {
        printf("%s[%d] = %d", joiner, orderArray[i], integers[orderArray[i]]);
        joiner = ", ";
    }

    printf("\n");
}

// Function to display the array with the first and last elements switched
void part6(int count, int integers[]) {
    printf("\n%s:\n\t%s", "Part 6", "Your array with first and last element switched is: ");

    char *joiner = ", "; // Used for formatting the output
    printf("[%d] = %d", count - 1, integers[count - 1]); // Print the last element first

    for (int i = 1; i < count - 1; i++) {
        printf("%s[%d] = %d", joiner, i, integers[i]); // Print the middle elements
    }

    printf("%s[%d] = %d", joiner, 0, integers[0]); // Print the first element last
    printf("\n");
}

int main() {
    int count = get_integer_count(); // Get the count of integers from the user
    int integers[count]; // Declare an array to store the integers

    get_integers(count, integers); // Get integers from the user and store them in the array

    // Execute functions to perform different tasks on the array
    part1(count, integers);
    part2(count, integers);
    part3(count, integers);
    part4(count, integers);
    part5(count, integers);
    part6(count, integers);

    return 0;
}
