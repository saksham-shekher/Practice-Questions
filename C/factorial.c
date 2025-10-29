/**
 * Factorial Calculation - Multiple Methods
 * Factorial of n (n!) is the product of all positive integers less than or equal to n.
 * Example: 5! = 5 × 4 × 3 × 2 × 1 = 120
 */

#include <stdio.h>

/**
 * Method 1: Iterative approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long factorialIterative(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Method 2: Recursive approach
 * Time Complexity: O(n)
 * Space Complexity: O(n) - due to recursion stack
 */
long long factorialRecursive(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

/**
 * Method 3: Using while loop
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long factorialWhile(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    
    long long result = 1;
    int counter = n;
    while (counter > 1) {
        result *= counter;
        counter--;
    }
    return result;
}

/**
 * Method 4: Tail recursive approach
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
long long factorialTailHelper(int n, long long accumulator) {
    if (n == 0 || n == 1) return accumulator;
    return factorialTailHelper(n - 1, n * accumulator);
}

long long factorialTailRecursive(int n) {
    if (n < 0) return -1;
    return factorialTailHelper(n, 1);
}

/**
 * Method 5: Using do-while loop
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long factorialDoWhile(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    
    long long result = 1;
    int counter = n;
    do {
        result *= counter;
        counter--;
    } while (counter > 1);
    
    return result;
}

// Test examples
int main() {
    printf("Factorial Calculation - Testing All Methods\n\n");
    printf("============================================================\n");
    
    int testNumbers[] = {0, 1, 5, 10, 12, 15};
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    for (int i = 0; i < numTests; i++) {
        int num = testNumbers[i];
        printf("\nFactorial of %d:\n", num);
        printf("  Method 1 (Iterative):      %lld\n", factorialIterative(num));
        printf("  Method 2 (Recursive):      %lld\n", factorialRecursive(num));
        printf("  Method 3 (While Loop):     %lld\n", factorialWhile(num));
        printf("  Method 4 (Tail Recursive): %lld\n", factorialTailRecursive(num));
        printf("  Method 5 (Do-While):       %lld\n", factorialDoWhile(num));
    }
    
    return 0;
}
