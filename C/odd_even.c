/**
 * Odd/Even Checker - Multiple Methods
 * Determines whether a number is odd or even.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Method 1: Using modulo operator (most common)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int isEvenModulo(int n) {
    return n % 2 == 0;
}

/**
 * Method 2: Using bitwise AND operation
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int isEvenBitwise(int n) {
    return (n & 1) == 0;
}

/**
 * Method 3: Using division and comparison
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int isEvenDivision(int n) {
    return (n / 2) * 2 == n;
}

/**
 * Method 4: Using modulo with ternary operator
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int isEvenTernary(int n) {
    return (n % 2 == 0) ? 1 : 0;
}

/**
 * Comprehensive check returning string
 */
const char* checkOddEven(int n) {
    return isEvenModulo(n) ? "Even" : "Odd";
}

// Test examples
int main() {
    printf("Odd/Even Checker - Testing All Methods\n\n");
    printf("============================================================\n");
    
    int testNumbers[] = {0, 1, 2, 15, 20, 37, 100, -5, -8};
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for (int i = 0; i < numTests; i++) {
        int num = testNumbers[i];
        printf("\nNumber: %d\n", num);
        printf("  Method 1 (Modulo):    %s\n", checkOddEven(num));
        printf("  Method 2 (Bitwise):   %s\n", isEvenBitwise(num) ? "Even" : "Odd");
        printf("  Method 3 (Division):  %s\n", isEvenDivision(num) ? "Even" : "Odd");
        printf("  Method 4 (Ternary):   %s\n", isEvenTernary(num) ? "Even" : "Odd");
    }
    
    return 0;
}
