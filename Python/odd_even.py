"""
Odd/Even Checker - Multiple Methods
Determines whether a number is odd or even.
"""


def is_even_modulo(n):
    """
    Method 1: Using modulo operator (most common)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return n % 2 == 0


def is_even_bitwise(n):
    """
    Method 2: Using bitwise AND operation
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return (n & 1) == 0


def is_even_division(n):
    """
    Method 3: Using division and comparison
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return n // 2 * 2 == n


def is_even_string(n):
    """
    Method 4: Using string manipulation (last digit)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    last_digit = int(str(abs(n))[-1])
    return last_digit in [0, 2, 4, 6, 8]


def check_odd_even(n):
    """
    Comprehensive check returning detailed information
    """
    is_even = is_even_modulo(n)
    return "Even" if is_even else "Odd"


# Test examples
if __name__ == "__main__":
    print("Odd/Even Checker - Testing All Methods\n")
    print("=" * 60)
    
    test_numbers = [0, 1, 2, 15, 20, 37, 100, -5, -8]
    
    for num in test_numbers:
        print(f"\nNumber: {num}")
        print(f"  Method 1 (Modulo):    {check_odd_even(num)}")
        print(f"  Method 2 (Bitwise):   {'Even' if is_even_bitwise(num) else 'Odd'}")
        print(f"  Method 3 (Division):  {'Even' if is_even_division(num) else 'Odd'}")
        print(f"  Method 4 (String):    {'Even' if is_even_string(num) else 'Odd'}")
