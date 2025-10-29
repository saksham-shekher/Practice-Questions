"""
Fibonacci Sequence - Multiple Methods
The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
Each number is the sum of the two preceding ones.
"""


def fibonacci_iterative(n):
    """
    Method 1: Iterative approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    
    fib_sequence = [0, 1]
    for i in range(2, n):
        fib_sequence.append(fib_sequence[i-1] + fib_sequence[i-2])
    
    return fib_sequence


def fibonacci_recursive(n):
    """
    Method 2: Recursive approach (not efficient for large n)
    Time Complexity: O(2^n)
    Space Complexity: O(n)
    """
    def fib(num):
        if num <= 1:
            return num
        return fib(num - 1) + fib(num - 2)
    
    return [fib(i) for i in range(n)]


def fibonacci_memoization(n):
    """
    Method 3: Recursive with memoization (dynamic programming)
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    memo = {}
    
    def fib(num):
        if num in memo:
            return memo[num]
        if num <= 1:
            return num
        memo[num] = fib(num - 1) + fib(num - 2)
        return memo[num]
    
    return [fib(i) for i in range(n)]


def fibonacci_generator(n):
    """
    Method 4: Using generator (memory efficient)
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    def fib_gen():
        a, b = 0, 1
        while True:
            yield a
            a, b = b, a + b
    
    gen = fib_gen()
    return [next(gen) for _ in range(n)]


def fibonacci_formula(n):
    """
    Method 5: Using Binet's formula (golden ratio)
    Time Complexity: O(n)
    Space Complexity: O(1)
    Note: May have floating point precision issues
    """
    import math
    phi = (1 + math.sqrt(5)) / 2
    
    result = []
    for i in range(n):
        fib_n = round((phi**i) / math.sqrt(5))
        result.append(fib_n)
    
    return result


# Test examples
if __name__ == "__main__":
    print("Fibonacci Sequence - Testing All Methods\n")
    print("=" * 60)
    
    n = 10
    print(f"Generating first {n} Fibonacci numbers:\n")
    
    print("1. Iterative Method:")
    print(fibonacci_iterative(n))
    
    print("\n2. Recursive Method:")
    print(fibonacci_recursive(n))
    
    print("\n3. Memoization Method:")
    print(fibonacci_memoization(n))
    
    print("\n4. Generator Method:")
    print(fibonacci_generator(n))
    
    print("\n5. Formula Method (Binet's):")
    print(fibonacci_formula(n))
    
    print("\n" + "=" * 60)
    print(f"Generating first 15 Fibonacci numbers (Iterative):")
    print(fibonacci_iterative(15))
