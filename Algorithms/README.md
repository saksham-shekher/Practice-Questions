# Algorithms - Searching and Sorting

This folder contains implementations of common searching and sorting algorithms for junior developer interviews.

## Available Files

### Searching Algorithms
- **Python** - `searching.py`
- **Java** - `Searching.java`
- **C** - `searching.c`

### Sorting Algorithms
- **Python** - `sorting.py`
- **Java** - `Sorting.java`
- **C** - `sorting.c`

## Searching Algorithms

### 1. Linear Search
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
- **Use Case:** Unsorted arrays, small datasets
- **Description:** Sequential search through each element

### 2. Binary Search (Iterative & Recursive)
- **Time Complexity:** O(log n)
- **Space Complexity:** O(1) iterative, O(log n) recursive
- **Use Case:** Sorted arrays
- **Description:** Divide and conquer approach

### 3. Jump Search
- **Time Complexity:** O(√n)
- **Space Complexity:** O(1)
- **Use Case:** Sorted arrays, better than linear
- **Description:** Jump ahead by fixed steps

### 4. Interpolation Search
- **Time Complexity:** O(log log n) for uniform distribution
- **Space Complexity:** O(1)
- **Use Case:** Sorted, uniformly distributed data
- **Description:** Improved binary search using interpolation

## Sorting Algorithms

### 1. Bubble Sort
- **Time Complexity:** O(n²) average/worst, O(n) best
- **Space Complexity:** O(1)
- **Use Case:** Small datasets, educational purposes
- **Description:** Repeatedly swap adjacent elements

### 2. Selection Sort
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)
- **Use Case:** Small datasets, minimal memory writes
- **Description:** Find minimum and place at beginning

### 3. Insertion Sort
- **Time Complexity:** O(n²) average/worst, O(n) best
- **Space Complexity:** O(1)
- **Use Case:** Nearly sorted data, small datasets
- **Description:** Build sorted array one element at a time

### 4. Merge Sort
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)
- **Use Case:** Stable sort needed, linked lists
- **Description:** Divide and conquer with merging

### 5. Quick Sort
- **Time Complexity:** O(n log n) average, O(n²) worst
- **Space Complexity:** O(log n)
- **Use Case:** General purpose, large datasets
- **Description:** Divide and conquer using pivot

### 6. Heap Sort
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1)
- **Use Case:** In-place sorting, guaranteed O(n log n)
- **Description:** Build max heap and extract elements

### 7. Counting Sort
- **Time Complexity:** O(n + k) where k is range
- **Space Complexity:** O(k)
- **Use Case:** Small range of integers
- **Description:** Count occurrences of each element

## Running the Code

### Python
```bash
# Searching
python searching.py

# Sorting
python sorting.py
```

### Java
```bash
# Searching
javac Searching.java
java Searching

# Sorting
javac Sorting.java
java Sorting
```

### C
```bash
# Searching
gcc searching.c -o searching -lm
./searching

# Sorting
gcc sorting.c -o sorting
./sorting
```

## Quick Reference Table

### When to Use Which Search?

| Algorithm | Best For | Requirement |
|-----------|----------|-------------|
| Linear | Unsorted, small datasets | None |
| Binary | Sorted, large datasets | Sorted array |
| Jump | Sorted, medium datasets | Sorted array |
| Interpolation | Uniformly distributed | Sorted, uniform |

### When to Use Which Sort?

| Algorithm | Best For | Stable? |
|-----------|----------|---------|
| Bubble | Learning, small data | Yes |
| Selection | Minimal memory writes | No |
| Insertion | Nearly sorted | Yes |
| Merge | Stable sort needed | Yes |
| Quick | General purpose | No |
| Heap | In-place, guaranteed | No |
| Counting | Small range integers | Yes |

## Learning Path for Junior Developers

1. **Start with:** Linear Search, Bubble Sort, Selection Sort
2. **Move to:** Binary Search, Insertion Sort
3. **Master:** Merge Sort, Quick Sort
4. **Advanced:** Heap Sort, Jump Search, Interpolation Search
5. **Specialized:** Counting Sort

## Interview Tips

- Understand time and space complexity
- Know when to use each algorithm
- Practice implementing without looking
- Explain trade-offs between algorithms
- Consider edge cases (empty array, single element, duplicates)

## Common Interview Questions

1. Implement binary search iteratively and recursively
2. Sort an array using quick sort
3. Find kth largest element (use heap or quick select)
4. Merge two sorted arrays (use merge from merge sort)
5. Find duplicates in an array (use sorting)
