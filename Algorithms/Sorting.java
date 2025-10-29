/**
 * Sorting Algorithms
 * Common sorting algorithms for junior developer interviews
 */

import java.util.Arrays;

public class Sorting {

    /**
     * Bubble Sort
     * Time Complexity: O(n²) worst/average, O(n) best
     * Space Complexity: O(1)
     */
    public static int[] bubbleSort(int[] arr) {
        int[] result = arr.clone();
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (result[j] > result[j + 1]) {
                    int temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) break;  // Optimization
        }
        return result;
    }

    /**
     * Selection Sort
     * Time Complexity: O(n²)
     * Space Complexity: O(1)
     */
    public static int[] selectionSort(int[] arr) {
        int[] result = arr.clone();
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (result[j] < result[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = result[i];
            result[i] = result[minIdx];
            result[minIdx] = temp;
        }
        return result;
    }

    /**
     * Insertion Sort
     * Time Complexity: O(n²) worst/average, O(n) best
     * Space Complexity: O(1)
     */
    public static int[] insertionSort(int[] arr) {
        int[] result = arr.clone();
        
        for (int i = 1; i < result.length; i++) {
            int key = result[i];
            int j = i - 1;
            
            while (j >= 0 && result[j] > key) {
                result[j + 1] = result[j];
                j--;
            }
            result[j + 1] = key;
        }
        return result;
    }

    /**
     * Merge Sort
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }
        
        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left, right);
    }

    private static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }
        
        while (i < left.length) {
            result[k++] = left[i++];
        }
        
        while (j < right.length) {
            result[k++] = right[j++];
        }
        
        return result;
    }

    /**
     * Quick Sort
     * Time Complexity: O(n log n) average, O(n²) worst
     * Space Complexity: O(log n)
     */
    public static int[] quickSort(int[] arr) {
        int[] result = arr.clone();
        quickSortHelper(result, 0, result.length - 1);
        return result;
    }

    private static void quickSortHelper(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        return i + 1;
    }

    /**
     * Heap Sort
     * Time Complexity: O(n log n)
     * Space Complexity: O(1)
     */
    public static int[] heapSort(int[] arr) {
        int[] result = arr.clone();
        int n = result.length;
        
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(result, n, i);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            int temp = result[0];
            result[0] = result[i];
            result[i] = temp;
            
            heapify(result, i, 0);
        }
        
        return result;
    }

    private static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            
            heapify(arr, n, largest);
        }
    }

    /**
     * Counting Sort
     * Time Complexity: O(n + k)
     * Space Complexity: O(k)
     */
    public static int[] countingSort(int[] arr) {
        if (arr.length == 0) return arr;
        
        int max = Arrays.stream(arr).max().getAsInt();
        int min = Arrays.stream(arr).min().getAsInt();
        int range = max - min + 1;
        
        int[] count = new int[range];
        int[] output = new int[arr.length];
        
        for (int num : arr) {
            count[num - min]++;
        }
        
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = arr.length - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }
        
        return output;
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("============================================================");
        System.out.println("SORTING ALGORITHMS");
        System.out.println("============================================================");
        
        int[] testArr = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 13};
        
        System.out.println("\nOriginal Array: " + Arrays.toString(testArr) + "\n");
        
        System.out.println("1. Bubble Sort:");
        System.out.println("   Result: " + Arrays.toString(bubbleSort(testArr)));
        
        System.out.println("\n2. Selection Sort:");
        System.out.println("   Result: " + Arrays.toString(selectionSort(testArr)));
        
        System.out.println("\n3. Insertion Sort:");
        System.out.println("   Result: " + Arrays.toString(insertionSort(testArr)));
        
        System.out.println("\n4. Merge Sort:");
        System.out.println("   Result: " + Arrays.toString(mergeSort(testArr)));
        
        System.out.println("\n5. Quick Sort:");
        System.out.println("   Result: " + Arrays.toString(quickSort(testArr)));
        
        System.out.println("\n6. Heap Sort:");
        System.out.println("   Result: " + Arrays.toString(heapSort(testArr)));
        
        System.out.println("\n7. Counting Sort:");
        System.out.println("   Result: " + Arrays.toString(countingSort(testArr)));
        
        System.out.println("\n============================================================");
        System.out.println("\nTime Complexity Summary:");
        System.out.println("------------------------------------------------------------");
        System.out.println("Bubble Sort:     O(n²) - Best for small datasets");
        System.out.println("Selection Sort:  O(n²) - Simple but inefficient");
        System.out.println("Insertion Sort:  O(n²) - Good for nearly sorted data");
        System.out.println("Merge Sort:      O(n log n) - Stable, predictable");
        System.out.println("Quick Sort:      O(n log n) avg - Fast in practice");
        System.out.println("Heap Sort:       O(n log n) - In-place sorting");
        System.out.println("Counting Sort:   O(n + k) - Great for small range");
        System.out.println("============================================================");
    }
}
