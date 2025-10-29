/**
 * Searching Algorithms
 * Common searching algorithms for junior developer interviews
 */

public class Searching {

    /**
     * Linear/Sequential Search
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
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
    public static int binarySearchIterative(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
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
    public static int binarySearchRecursive(int[] arr, int target) {
        return binarySearchRecursiveHelper(arr, target, 0, arr.length - 1);
    }

    private static int binarySearchRecursiveHelper(int[] arr, int target, int left, int right) {
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

    /**
     * Jump Search
     * Time Complexity: O(√n)
     * Space Complexity: O(1)
     * Note: Array must be sorted
     */
    public static int jumpSearch(int[] arr, int target) {
        int n = arr.length;
        int step = (int) Math.sqrt(n);
        int prev = 0;
        
        // Find the block where element is present
        while (arr[Math.min(step, n) - 1] < target) {
            prev = step;
            step += (int) Math.sqrt(n);
            if (prev >= n) {
                return -1;
            }
        }
        
        // Linear search in the identified block
        while (arr[prev] < target) {
            prev++;
            if (prev == Math.min(step, n)) {
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
    public static int interpolationSearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left <= right && target >= arr[left] && target <= arr[right]) {
            if (left == right) {
                if (arr[left] == target) {
                    return left;
                }
                return -1;
            }
            
            // Probing the position with keeping uniform distribution in mind
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

    // Helper method to print array
    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("============================================================");
        System.out.println("SEARCHING ALGORITHMS");
        System.out.println("============================================================");
        
        int[] sortedArr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
        int[] unsortedArr = {45, 23, 78, 12, 67, 5, 38, 16, 2, 56, 8};
        int target = 23;
        
        System.out.print("\nSorted Array: ");
        printArray(sortedArr);
        System.out.print("Unsorted Array: ");
        printArray(unsortedArr);
        System.out.println("Target Element: " + target + "\n");
        
        System.out.println("1. Linear Search (works on unsorted array):");
        System.out.println("------------------------------------------------------------");
        int result = linearSearch(unsortedArr, target);
        System.out.println("   Found at index: " + result);
        
        System.out.println("\n2. Binary Search - Iterative (requires sorted array):");
        System.out.println("------------------------------------------------------------");
        result = binarySearchIterative(sortedArr, target);
        System.out.println("   Found at index: " + result);
        
        System.out.println("\n3. Binary Search - Recursive (requires sorted array):");
        System.out.println("------------------------------------------------------------");
        result = binarySearchRecursive(sortedArr, target);
        System.out.println("   Found at index: " + result);
        
        System.out.println("\n4. Jump Search (requires sorted array):");
        System.out.println("------------------------------------------------------------");
        result = jumpSearch(sortedArr, target);
        System.out.println("   Found at index: " + result);
        
        System.out.println("\n5. Interpolation Search (requires sorted array):");
        System.out.println("------------------------------------------------------------");
        result = interpolationSearch(sortedArr, target);
        System.out.println("   Found at index: " + result);
        
        System.out.println("\n============================================================");
        int targetNotFound = 100;
        System.out.println("Searching for element not in array: " + targetNotFound);
        System.out.println("Linear Search: " + linearSearch(sortedArr, targetNotFound));
        System.out.println("Binary Search: " + binarySearchIterative(sortedArr, targetNotFound));
        System.out.println("============================================================");
    }
}
