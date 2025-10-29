"""
Factorial Calculation - Multiple Methods
Factorial of n (n!) is the product of all positive integers less than or equal to n.
Example: 5! = 5 × 4 × 3 × 2 × 1 = 120
"""


def factorial_iterative(n):
    """
    Method 1: Iterative approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    
    result = 1
    for i in range(2, n + 1):
        result *= i
    
    return result


def factorial_recursive(n):
    """
    Method 2: Recursive approach
    Time Complexity: O(n)
    Space Complexity: O(n) - due to recursion stack
    """
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    
    return n * factorial_recursive(n - 1)


def factorial_builtin(n):
    """
    Method 3: Using built-in math.factorial
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    import math
    if n < 0:
        return None
    return math.factorial(n)


def factorial_reduce(n):
    """
    Method 4: Using functools.reduce
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    from functools import reduce
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    
    return reduce(lambda x, y: x * y, range(1, n + 1))


def factorial_while(n):
    """
    Method 5: Using while loop
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    
    result = 1
    counter = n
    while counter > 1:
        result *= counter
        counter -= 1
    
    return result


# Test examples
if __name__ == "__main__":
    print("Factorial Calculation - Testing All Methods\n")
    print("=" * 60)
    
    test_numbers = [0, 1, 5, 10, 12]
    
    for num in test_numbers:
        print(f"\nFactorial of {num}:")
        print(f"  Method 1 (Iterative):  {factorial_iterative(num)}")
        print(f"  Method 2 (Recursive):  {factorial_recursive(num)}")
        print(f"  Method 3 (Built-in):   {factorial_builtin(num)}")
        print(f"  Method 4 (Reduce):     {factorial_reduce(num)}")
        print(f"  Method 5 (While Loop): {factorial_while(num)}")
