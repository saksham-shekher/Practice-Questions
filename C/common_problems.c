/**
 * Additional Common Problems for Junior Developers
 * Includes: Array Reversal, String Reversal, Sum of Digits, Maximum/Minimum, Array Sum
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ============= ARRAY REVERSAL =============

/**
 * Reverse array using two pointers (in-place)
 */
void reverseArrayTwoPointer(int arr[], int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    
    int left = 0, right = n - 1;
    while (left < right) {
        int temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
}

/**
 * Reverse array using loop (creating new array)
 */
void reverseArrayLoop(int arr[], int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = arr[n - 1 - i];
    }
}

// ============= STRING REVERSAL =============

/**
 * Reverse string using two pointers
 */
void reverseStringTwoPointer(char *str, char *result) {
    int len = strlen(str);
    strcpy(result, str);
    
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
}

/**
 * Reverse string using loop
 */
void reverseStringLoop(char *str, char *result) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
}

// ============= SUM OF DIGITS =============

/**
 * Calculate sum of digits using mathematical operations
 */
int sumOfDigitsMath(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/**
 * Calculate sum of digits using recursion
 */
int sumOfDigitsRecursive(int n) {
    n = abs(n);
    if (n == 0) return 0;
    return (n % 10) + sumOfDigitsRecursive(n / 10);
}

// ============= FIND MAX/MIN =============

/**
 * Find maximum using loop
 */
int findMaxLoop(int arr[], int n) {
    if (n == 0) return -1;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

/**
 * Find minimum using loop
 */
int findMinLoop(int arr[], int n) {
    if (n == 0) return -1;
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

// ============= ARRAY SUM =============

/**
 * Calculate sum using loop
 */
int arraySumLoop(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

/**
 * Calculate sum using recursion
 */
int arraySumRecursive(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + arraySumRecursive(arr, n - 1);
}

// Helper function to print array
void printArray(int arr[], int n, const char *prefix) {
    printf("%s", prefix);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test examples
int main() {
    printf("Additional Common Problems - Testing\n\n");
    printf("============================================================\n");
    
    // Test Array Reversal
    printf("\n1. ARRAY REVERSAL:\n");
    printf("------------------------------------------------------------\n");
    int testArray[] = {1, 2, 3, 4, 5};
    int n = sizeof(testArray) / sizeof(testArray[0]);
    int result[10];
    
    printArray(testArray, n, "Original array: ");
    reverseArrayTwoPointer(testArray, n, result);
    printArray(result, n, "Two Pointer:    ");
    reverseArrayLoop(testArray, n, result);
    printArray(result, n, "Loop:           ");
    
    // Test String Reversal
    printf("\n2. STRING REVERSAL:\n");
    printf("------------------------------------------------------------\n");
    char testString[] = "Hello World";
    char strResult[100];
    
    printf("Original string: '%s'\n", testString);
    reverseStringTwoPointer(testString, strResult);
    printf("Two Pointer:     '%s'\n", strResult);
    reverseStringLoop(testString, strResult);
    printf("Loop:            '%s'\n", strResult);
    
    // Test Sum of Digits
    printf("\n3. SUM OF DIGITS:\n");
    printf("------------------------------------------------------------\n");
    int testNumbers[] = {12345, 999, 1010};
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    for (int i = 0; i < numTests; i++) {
        int num = testNumbers[i];
        printf("Number %d: Math method = %d, Recursive method = %d\n",
            num, sumOfDigitsMath(num), sumOfDigitsRecursive(num));
    }
    
    // Test Find Max/Min
    printf("\n4. FIND MAXIMUM & MINIMUM:\n");
    printf("------------------------------------------------------------\n");
    int testArray2[] = {45, 12, 78, 23, 90, 5, 67};
    int n2 = sizeof(testArray2) / sizeof(testArray2[0]);
    printArray(testArray2, n2, "Array: ");
    printf("Maximum: %d\n", findMaxLoop(testArray2, n2));
    printf("Minimum: %d\n", findMinLoop(testArray2, n2));
    
    // Test Array Sum
    printf("\n5. ARRAY SUM:\n");
    printf("------------------------------------------------------------\n");
    int testArray3[] = {10, 20, 30, 40, 50};
    int n3 = sizeof(testArray3) / sizeof(testArray3[0]);
    printArray(testArray3, n3, "Array: ");
    printf("Loop sum:      %d\n", arraySumLoop(testArray3, n3));
    printf("Recursive sum: %d\n", arraySumRecursive(testArray3, n3));
    
    return 0;
}
