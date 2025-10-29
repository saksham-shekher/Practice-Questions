/**
 * Searching Algorithms
 * Common searching algorithms for junior developer interviews
 */

#include <stdio.h>
#include <math.h>

/**
 * Linear/Sequential Search
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

/**
 * Binary Search (Iterative)
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Note: Array must be sorted
 */
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/**
 * Binary Search (Recursive)
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 * Note: Array must be sorted
 */
int binarySearchRecursiveHelper(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursiveHelper(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursiveHelper(arr, target, left, mid - 1);
    }
}

int binarySearchRecursive(int arr[], int n, int target) {
    return binarySearchRecursiveHelper(arr, target, 0, n - 1);
}

/**
 * Jump Search
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 * Note: Array must be sorted
 */
int jumpSearch(int arr[], int n, int target) {
    int step = (int)sqrt(n);
    int prev = 0;
    
    // Find the block where element is present
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Linear search in the identified block
    while (arr[prev] < target) {
        prev++;
        if (prev == (step < n ? step : n)) {
            return -1;
        }
    }
    
    if (arr[prev] == target) {
        return prev;
    }
    
    return -1;
}

/**
 * Interpolation Search
 * Time Complexity: O(log log n) for uniformly distributed data
 * Space Complexity: O(1)
 * Note: Array must be sorted
 */
int interpolationSearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) {
                return left;
            }
            return -1;
        }
        
        // Probing the position
        int pos = left + ((target - arr[left]) * (right - left) / 
                        (arr[right] - arr[left]));
        
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
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
    printf("============================================================\n");
    printf("SEARCHING ALGORITHMS\n");
    printf("============================================================\n");
    
    int sortedArr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int unsortedArr[] = {45, 23, 78, 12, 67, 5, 38, 16, 2, 56, 8};
    int n = 11;
    int target = 23;
    
    printf("\nSorted Array: ");
    printArray(sortedArr, n);
    printf("Unsorted Array: ");
    printArray(unsortedArr, n);
    printf("Target Element: %d\n\n", target);
    
    printf("1. Linear Search (works on unsorted array):\n");
    printf("------------------------------------------------------------\n");
    int result = linearSearch(unsortedArr, n, target);
    printf("   Found at index: %d\n", result);
    
    printf("\n2. Binary Search - Iterative (requires sorted array):\n");
    printf("------------------------------------------------------------\n");
    result = binarySearchIterative(sortedArr, n, target);
    printf("   Found at index: %d\n", result);
    
    printf("\n3. Binary Search - Recursive (requires sorted array):\n");
    printf("------------------------------------------------------------\n");
    result = binarySearchRecursive(sortedArr, n, target);
    printf("   Found at index: %d\n", result);
    
    printf("\n4. Jump Search (requires sorted array):\n");
    printf("------------------------------------------------------------\n");
    result = jumpSearch(sortedArr, n, target);
    printf("   Found at index: %d\n", result);
    
    printf("\n5. Interpolation Search (requires sorted array):\n");
    printf("------------------------------------------------------------\n");
    result = interpolationSearch(sortedArr, n, target);
    printf("   Found at index: %d\n", result);
    
    printf("\n============================================================\n");
    int targetNotFound = 100;
    printf("Searching for element not in array: %d\n", targetNotFound);
    printf("Linear Search: %d\n", linearSearch(sortedArr, n, targetNotFound));
    printf("Binary Search: %d\n", binarySearchIterative(sortedArr, n, targetNotFound));
    printf("============================================================\n");
    
    return 0;
}
