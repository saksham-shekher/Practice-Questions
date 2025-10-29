/**
 * Prime Number Checker - Multiple Methods
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * Method 1: Basic approach - check all numbers up to n
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int isPrimeBasic(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/**
 * Method 2: Optimized - check only up to sqrt(n)
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(1)
 */
int isPrimeOptimized(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

/**
 * Method 3: Using square root
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(1)
 */
int isPrimeSqrt(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/**
 * Method 4: Sieve of Eratosthenes (for generating multiple primes)
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n)
 */
void generatePrimesSieve(int limit, int primes[], int *count) {
    if (limit < 2) {
        *count = 0;
        return;
    }
    
    int *isPrime = (int*)malloc((limit + 1) * sizeof(int));
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    
    *count = 0;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes[(*count)++] = i;
        }
    }
    
    free(isPrime);
}

/**
 * Method 5: Generate first n prime numbers
 */
void firstNPrimes(int n, int primes[]) {
    int count = 0;
    int num = 2;
    
    while (count < n) {
        if (isPrimeOptimized(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

// Helper function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test examples
int main() {
    printf("Prime Number Checker - Testing All Methods\n\n");
    printf("============================================================\n");
    
    int testNumbers[] = {1, 2, 3, 4, 5, 10, 11, 17, 20, 29, 30, 97, 100};
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    printf("Individual Number Tests:\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < numTests; i++) {
        int num = testNumbers[i];
        printf("Number %3d: Method 1: %s, Method 2: %s, Method 3: %s\n",
            num, 
            isPrimeBasic(num) ? "true " : "false",
            isPrimeOptimized(num) ? "true " : "false",
            isPrimeSqrt(num) ? "true " : "false");
    }
    
    printf("\n============================================================\n");
    printf("Sieve of Eratosthenes - Prime numbers up to 50:\n");
    int primes[1000];
    int count;
    generatePrimesSieve(50, primes, &count);
    printArray(primes, count);
    
    printf("\n============================================================\n");
    printf("First 15 prime numbers:\n");
    firstNPrimes(15, primes);
    printArray(primes, 15);
    
    return 0;
}
