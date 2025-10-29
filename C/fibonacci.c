/**
 * Fibonacci Sequence - Multiple Methods
 * The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * Each number is the sum of the two preceding ones.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Method 1: Iterative approach
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void fibonacciIterative(int n, int result[]) {
    if (n <= 0) return;
    
    result[0] = 0;
    if (n == 1) return;
    
    result[1] = 1;
    for (int i = 2; i < n; i++) {
        result[i] = result[i-1] + result[i-2];
    }
}

/**
 * Method 2: Recursive approach (not efficient for large n)
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 */
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void fibonacciRecursive(int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = fibRecursive(i);
    }
}

/**
 * Method 3: Using memoization (dynamic programming)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int fibMemo(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

void fibonacciMemoization(int n, int result[]) {
    int memo[1000];
    for (int i = 0; i < 1000; i++) {
        memo[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        result[i] = fibMemo(i, memo);
    }
}

/**
 * Method 4: Space optimized iterative (only store last two numbers)
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void fibonacciOptimized(int n, int result[]) {
    if (n <= 0) return;
    
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        result[i] = a;
        int next = a + b;
        a = b;
        b = next;
    }
}

/**
 * Method 5: Using array/tabulation (bottom-up dynamic programming)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void fibonacciTabulation(int n, int result[]) {
    if (n <= 0) return;
    
    result[0] = 0;
    if (n == 1) return;
    
    result[1] = 1;
    for (int i = 2; i < n; i++) {
        result[i] = result[i-1] + result[i-2];
    }
}

// Helper function to print array
void printArray(int arr[], int n, const char* methodName) {
    printf("%s: ", methodName);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test examples
int main() {
    printf("Fibonacci Sequence - Testing All Methods\n\n");
    printf("============================================================\n");
    
    int n = 10;
    int result[1000];
    
    printf("Generating first %d Fibonacci numbers:\n\n", n);
    
    fibonacciIterative(n, result);
    printArray(result, n, "1. Iterative Method");
    
    fibonacciRecursive(n, result);
    printArray(result, n, "2. Recursive Method");
    
    fibonacciMemoization(n, result);
    printArray(result, n, "3. Memoization Method");
    
    fibonacciOptimized(n, result);
    printArray(result, n, "4. Optimized Method");
    
    fibonacciTabulation(n, result);
    printArray(result, n, "5. Tabulation Method");
    
    printf("\n============================================================\n");
    printf("Generating first 15 Fibonacci numbers (Iterative):\n");
    fibonacciIterative(15, result);
    printArray(result, 15, "");
    
    return 0;
}
