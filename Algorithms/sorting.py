"""
Sorting Algorithms
Common sorting algorithms for junior developer interviews
"""


def bubble_sort(arr):
    """
    Bubble Sort
    Time Complexity: O(n²) worst/average, O(n) best
    Space Complexity: O(1)
    Description: Repeatedly swap adjacent elements if they're in wrong order
    """
    n = len(arr)
    arr = arr.copy()  # Don't modify original
    
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:  # Optimization: stop if no swaps
            break
    
    return arr


def selection_sort(arr):
    """
    Selection Sort
    Time Complexity: O(n²)
    Space Complexity: O(1)
    Description: Find minimum element and place it at beginning
    """
    n = len(arr)
    arr = arr.copy()
    
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr


def insertion_sort(arr):
    """
    Insertion Sort
    Time Complexity: O(n²) worst/average, O(n) best
    Space Complexity: O(1)
    Description: Build sorted array one element at a time
    """
    arr = arr.copy()
    
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    
    return arr


def merge_sort(arr):
    """
    Merge Sort
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    Description: Divide and conquer - split, sort, merge
    """
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    return merge(left, right)


def merge(left, right):
    """Helper function for merge sort"""
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def quick_sort(arr):
    """
    Quick Sort
    Time Complexity: O(n log n) average, O(n²) worst
    Space Complexity: O(log n)
    Description: Divide and conquer using pivot element
    """
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)


def counting_sort(arr):
    """
    Counting Sort
    Time Complexity: O(n + k) where k is range of input
    Space Complexity: O(k)
    Description: Count occurrences of each element
    Note: Works best for small range of integers
    """
    if not arr:
        return arr
    
    max_val = max(arr)
    min_val = min(arr)
    range_size = max_val - min_val + 1
    
    count = [0] * range_size
    output = [0] * len(arr)
    
    # Count occurrences
    for num in arr:
        count[num - min_val] += 1
    
    # Cumulative count
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    
    # Build output array
    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i] - min_val] - 1] = arr[i]
        count[arr[i] - min_val] -= 1
    
    return output


def heap_sort(arr):
    """
    Heap Sort
    Time Complexity: O(n log n)
    Space Complexity: O(1)
    Description: Build max heap and extract elements
    """
    arr = arr.copy()
    n = len(arr)
    
    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Extract elements from heap
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
    
    return arr


def heapify(arr, n, i):
    """Helper function for heap sort"""
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


# Test examples
if __name__ == "__main__":
    print("=" * 60)
    print("SORTING ALGORITHMS")
    print("=" * 60)
    
    test_arr = [64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 13]
    
    print(f"\nOriginal Array: {test_arr}\n")
    
    print("1. Bubble Sort:")
    print(f"   Result: {bubble_sort(test_arr)}")
    
    print("\n2. Selection Sort:")
    print(f"   Result: {selection_sort(test_arr)}")
    
    print("\n3. Insertion Sort:")
    print(f"   Result: {insertion_sort(test_arr)}")
    
    print("\n4. Merge Sort:")
    print(f"   Result: {merge_sort(test_arr)}")
    
    print("\n5. Quick Sort:")
    print(f"   Result: {quick_sort(test_arr)}")
    
    print("\n6. Counting Sort:")
    print(f"   Result: {counting_sort(test_arr)}")
    
    print("\n7. Heap Sort:")
    print(f"   Result: {heap_sort(test_arr)}")
    
    print("\n" + "=" * 60)
    
    # Performance comparison with different sizes
    print("\nTime Complexity Summary:")
    print("-" * 60)
    print("Bubble Sort:     O(n²) - Best for small datasets")
    print("Selection Sort:  O(n²) - Simple but inefficient")
    print("Insertion Sort:  O(n²) - Good for nearly sorted data")
    print("Merge Sort:      O(n log n) - Stable, predictable")
    print("Quick Sort:      O(n log n) avg - Fast in practice")
    print("Counting Sort:   O(n + k) - Great for small range")
    print("Heap Sort:       O(n log n) - In-place sorting")
    print("=" * 60)
