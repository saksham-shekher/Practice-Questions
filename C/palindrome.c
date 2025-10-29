/**
 * Palindrome Checker - Multiple Methods
 * A palindrome is a word, phrase, number, or other sequence of characters
 * that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Helper function to remove spaces and convert to lowercase
 */
void cleanString(char* str, char* cleaned) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            cleaned[j++] = tolower(str[i]);
        }
    }
    cleaned[j] = '\0';
}

/**
 * Method 1: Using string reversal
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int isPalindromeReverse(char* str) {
    char cleaned[1000];
    cleanString(str, cleaned);
    
    int len = strlen(cleaned);
    char reversed[1000];
    
    for (int i = 0; i < len; i++) {
        reversed[i] = cleaned[len - 1 - i];
    }
    reversed[len] = '\0';
    
    return strcmp(cleaned, reversed) == 0;
}

/**
 * Method 2: Using two pointers (efficient)
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int isPalindromeTwoPointer(char* str) {
    char cleaned[1000];
    cleanString(str, cleaned);
    
    int left = 0;
    int right = strlen(cleaned) - 1;
    
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

/**
 * Method 3: Using recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n) - due to recursion stack
 */
int checkPalindromeRecursive(char* str, int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (str[left] != str[right]) {
        return 0;
    }
    return checkPalindromeRecursive(str, left + 1, right - 1);
}

int isPalindromeRecursive(char* str) {
    char cleaned[1000];
    cleanString(str, cleaned);
    return checkPalindromeRecursive(cleaned, 0, strlen(cleaned) - 1);
}

/**
 * Method 4: Using character array comparison
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int isPalindromeCharArray(char* str) {
    char cleaned[1000];
    cleanString(str, cleaned);
    
    int len = strlen(cleaned);
    
    for (int i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Method 5: Using dynamic memory allocation
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int isPalindromeDynamic(char* str) {
    // Clean the string
    int len = strlen(str);
    char* cleaned = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            cleaned[j++] = tolower(str[i]);
        }
    }
    cleaned[j] = '\0';
    
    int cleanedLen = strlen(cleaned);
    int isPalindrome = 1;
    
    for (int i = 0; i < cleanedLen / 2; i++) {
        if (cleaned[i] != cleaned[cleanedLen - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    
    free(cleaned);
    return isPalindrome;
}

// Test examples
int main() {
    char* testCases[] = {
        "racecar",
        "hello",
        "A man a plan a canal Panama",
        "madam",
        "clang",
        "12321",
        "12345"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    printf("Palindrome Checker - Testing All Methods\n\n");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < numTests; i++) {
        printf("\nTesting: '%s'\n", testCases[i]);
        printf("  Method 1 (Reverse):       %s\n", isPalindromeReverse(testCases[i]) ? "true" : "false");
        printf("  Method 2 (Two Pointer):   %s\n", isPalindromeTwoPointer(testCases[i]) ? "true" : "false");
        printf("  Method 3 (Recursive):     %s\n", isPalindromeRecursive(testCases[i]) ? "true" : "false");
        printf("  Method 4 (Char Array):    %s\n", isPalindromeCharArray(testCases[i]) ? "true" : "false");
        printf("  Method 5 (Dynamic):       %s\n", isPalindromeDynamic(testCases[i]) ? "true" : "false");
    }
    
    return 0;
}
