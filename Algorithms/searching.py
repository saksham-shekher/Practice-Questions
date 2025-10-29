"""
Searching Algorithms
Common searching algorithms for junior developer interviews
"""


def linear_search(arr, target):
    """
    Linear/Sequential Search
    Time Complexity: O(n)
    Space Complexity: O(1)
    Description: Search for element by checking each element sequentially
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Return index if found
    return -1  # Return -1 if not found


def binary_search_iterative(arr, target):
    """
    Binary Search (Iterative)
    Time Complexity: O(log n)
    Space Complexity: O(1)
    Description: Divide and conquer on sorted array
    Note: Array must be sorted
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


def binary_search_recursive(arr, target, left=None, right=None):
    """
    Binary Search (Recursive)
    Time Complexity: O(log n)
    Space Complexity: O(log n) - due to recursion stack
    Description: Recursive implementation of binary search
    Note: Array must be sorted
    """
    if left is None:
        left = 0
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    mid = left + (right - left) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    else:
        return binary_search_recursive(arr, target, left, mid - 1)


def jump_search(arr, target):
    """
    Jump Search
    Time Complexity: O(√n)
    Space Complexity: O(1)
    Description: Jump ahead by fixed steps, then linear search
    Note: Array must be sorted
    """
    import math
    
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0
    
    # Find the block where element is present
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    
    # Linear search in the identified block
    while arr[prev] < target:
        prev += 1
        if prev == min(step, n):
            return -1
    
    if arr[prev] == target:
        return prev
    
    return -1


def interpolation_search(arr, target):
    """
    Interpolation Search
    Time Complexity: O(log log n) for uniformly distributed data
    Space Complexity: O(1)
    Description: Improved binary search for uniformly distributed sorted arrays
    Note: Array must be sorted
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right and target >= arr[left] and target <= arr[right]:
        if left == right:
            if arr[left] == target:
                return left
            return -1
        
        # Probing the position with keeping uniform distribution in mind
        pos = left + ((target - arr[left]) * (right - left) // 
                     (arr[right] - arr[left]))
        
        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1
    
    return -1


# Test examples
if __name__ == "__main__":
    print("=" * 60)
    print("SEARCHING ALGORITHMS")
    print("=" * 60)
    
    # Test array (sorted for binary search)
    sorted_arr = [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]
    unsorted_arr = [45, 23, 78, 12, 67, 5, 38, 16, 2, 56, 8]
    
    target = 23
    
    print(f"\nSorted Array: {sorted_arr}")
    print(f"Unsorted Array: {unsorted_arr}")
    print(f"Target Element: {target}\n")
    
    print("1. Linear Search (works on unsorted array):")
    print("-" * 60)
    result = linear_search(unsorted_arr, target)
    print(f"   Found at index: {result}")
    
    print("\n2. Binary Search - Iterative (requires sorted array):")
    print("-" * 60)
    result = binary_search_iterative(sorted_arr, target)
    print(f"   Found at index: {result}")
    
    print("\n3. Binary Search - Recursive (requires sorted array):")
    print("-" * 60)
    result = binary_search_recursive(sorted_arr, target)
    print(f"   Found at index: {result}")
    
    print("\n4. Jump Search (requires sorted array):")
    print("-" * 60)
    result = jump_search(sorted_arr, target)
    print(f"   Found at index: {result}")
    
    print("\n5. Interpolation Search (requires sorted array):")
    print("-" * 60)
    result = interpolation_search(sorted_arr, target)
    print(f"   Found at index: {result}")
    
    # Test with element not in array
    print("\n" + "=" * 60)
    target_not_found = 100
    print(f"Searching for element not in array: {target_not_found}")
    print(f"Linear Search: {linear_search(sorted_arr, target_not_found)}")
    print(f"Binary Search: {binary_search_iterative(sorted_arr, target_not_found)}")
    print("=" * 60)
