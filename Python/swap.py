"""
Number Swapping - Multiple Methods
Demonstrates different techniques to swap two variables.
"""


def swap_with_temp(a, b):
    """
    Method 1: Using temporary variable (most common and readable)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    print(f"Before swap: a = {a}, b = {b}")
    temp = a
    a = b
    b = temp
    print(f"After swap:  a = {a}, b = {b}")
    return a, b


def swap_with_tuple(a, b):
    """
    Method 2: Using Python tuple unpacking (Pythonic way)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    print(f"Before swap: a = {a}, b = {b}")
    a, b = b, a
    print(f"After swap:  a = {a}, b = {b}")
    return a, b


def swap_with_arithmetic(a, b):
    """
    Method 3: Using arithmetic operations (without temp variable)
    Time Complexity: O(1)
    Space Complexity: O(1)
    Note: May cause overflow with very large numbers
    """
    print(f"Before swap: a = {a}, b = {b}")
    a = a + b
    b = a - b
    a = a - b
    print(f"After swap:  a = {a}, b = {b}")
    return a, b


def swap_with_xor(a, b):
    """
    Method 4: Using XOR operation (works for integers)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    print(f"Before swap: a = {a}, b = {b}")
    a = a ^ b
    b = a ^ b
    a = a ^ b
    print(f"After swap:  a = {a}, b = {b}")
    return a, b


def swap_with_multiplication(a, b):
    """
    Method 5: Using multiplication and division
    Time Complexity: O(1)
    Space Complexity: O(1)
    Note: Doesn't work if either number is 0
    """
    if a == 0 or b == 0:
        print("Cannot use multiplication method with zero")
        return a, b
    
    print(f"Before swap: a = {a}, b = {b}")
    a = a * b
    b = a // b
    a = a // b
    print(f"After swap:  a = {a}, b = {b}")
    return a, b


# Test examples
if __name__ == "__main__":
    print("Number Swapping - Testing All Methods\n")
    print("=" * 60)
    
    print("\n1. Swap using Temporary Variable:")
    print("-" * 60)
    swap_with_temp(10, 20)
    
    print("\n2. Swap using Tuple Unpacking (Pythonic):")
    print("-" * 60)
    swap_with_tuple(100, 200)
    
    print("\n3. Swap using Arithmetic Operations:")
    print("-" * 60)
    swap_with_arithmetic(5, 15)
    
    print("\n4. Swap using XOR:")
    print("-" * 60)
    swap_with_xor(7, 14)
    
    print("\n5. Swap using Multiplication:")
    print("-" * 60)
    swap_with_multiplication(3, 9)
