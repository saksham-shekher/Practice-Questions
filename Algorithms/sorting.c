/**
 * Sorting Algorithms
 * Common sorting algorithms for junior developer interviews
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Helper function to swap elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Bubble Sort
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;  // Optimization
    }
}

/**
 * Selection Sort
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

/**
 * Insertion Sort
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * Merge Sort - Helper function to merge
 */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

/**
 * Merge Sort
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

/**
 * Quick Sort - Helper function to partition
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/**
 * Quick Sort
 * Time Complexity: O(n log n) average
 * Space Complexity: O(log n)
 */
void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

/**
 * Heap Sort - Helper function
 */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/**
 * Heap Sort
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/**
 * Counting Sort
 * Time Complexity: O(n + k)
 * Space Complexity: O(k)
 */
void countingSort(int arr[], int n) {
    if (n == 0) return;
    
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    
    free(count);
    free(output);
}

// Test examples
int main() {
    printf("============================================================\n");
    printf("SORTING ALGORITHMS\n");
    printf("============================================================\n");
    
    int original[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 13};
    int n = sizeof(original) / sizeof(original[0]);
    
    printf("\nOriginal Array: ");
    printArray(original, n);
    printf("\n");
    
    // Test each sorting algorithm
    int testArr[20];
    
    memcpy(testArr, original, n * sizeof(int));
    bubbleSort(testArr, n);
    printf("1. Bubble Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    selectionSort(testArr, n);
    printf("\n2. Selection Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    insertionSort(testArr, n);
    printf("\n3. Insertion Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    mergeSort(testArr, n);
    printf("\n4. Merge Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    quickSort(testArr, n);
    printf("\n5. Quick Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    heapSort(testArr, n);
    printf("\n6. Heap Sort:\n   Result: ");
    printArray(testArr, n);
    
    memcpy(testArr, original, n * sizeof(int));
    countingSort(testArr, n);
    printf("\n7. Counting Sort:\n   Result: ");
    printArray(testArr, n);
    
    printf("\n============================================================\n");
    printf("\nTime Complexity Summary:\n");
    printf("------------------------------------------------------------\n");
    printf("Bubble Sort:     O(n²) - Best for small datasets\n");
    printf("Selection Sort:  O(n²) - Simple but inefficient\n");
    printf("Insertion Sort:  O(n²) - Good for nearly sorted data\n");
    printf("Merge Sort:      O(n log n) - Stable, predictable\n");
    printf("Quick Sort:      O(n log n) avg - Fast in practice\n");
    printf("Heap Sort:       O(n log n) - In-place sorting\n");
    printf("Counting Sort:   O(n + k) - Great for small range\n");
    printf("============================================================\n");
    
    return 0;
}
