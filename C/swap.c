/**
 * Number Swapping - Multiple Methods
 * Demonstrates different techniques to swap two variables.
 */

#include <stdio.h>

/**
 * Method 1: Using temporary variable (most common and readable)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithTemp(int a, int b) {
    printf("Before swap: a = %d, b = %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("After swap:  a = %d, b = %d\n", a, b);
}

/**
 * Method 2: Using arithmetic operations (without temp variable)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * Note: May cause overflow with very large numbers
 */
void swapWithArithmetic(int a, int b) {
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap:  a = %d, b = %d\n", a, b);
}

/**
 * Method 3: Using XOR operation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithXOR(int a, int b) {
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swap:  a = %d, b = %d\n", a, b);
}

/**
 * Method 4: Using multiplication and division
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * Note: Doesn't work if either number is 0
 */
void swapWithMultiplication(int a, int b) {
    if (a == 0 || b == 0) {
        printf("Cannot use multiplication method with zero\n");
        return;
    }
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a * b;
    b = a / b;
    a = a / b;
    printf("After swap:  a = %d, b = %d\n", a, b);
}

/**
 * Method 5: Using pointers (pass by reference)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swapWithPointers(int *a, int *b) {
    printf("Before swap: a = %d, b = %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After swap:  a = %d, b = %d\n", *a, *b);
}

// Test examples
int main() {
    printf("Number Swapping - Testing All Methods\n\n");
    printf("============================================================\n");
    
    printf("\n1. Swap using Temporary Variable:\n");
    printf("------------------------------------------------------------\n");
    swapWithTemp(10, 20);
    
    printf("\n2. Swap using Arithmetic Operations:\n");
    printf("------------------------------------------------------------\n");
    swapWithArithmetic(5, 15);
    
    printf("\n3. Swap using XOR:\n");
    printf("------------------------------------------------------------\n");
    swapWithXOR(7, 14);
    
    printf("\n4. Swap using Multiplication:\n");
    printf("------------------------------------------------------------\n");
    swapWithMultiplication(3, 9);
    
    printf("\n5. Swap using Pointers:\n");
    printf("------------------------------------------------------------\n");
    int x = 100, y = 200;
    swapWithPointers(&x, &y);
    
    return 0;
}
