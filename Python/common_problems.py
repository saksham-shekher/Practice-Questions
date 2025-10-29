"""
Additional Common Problems for Junior Developers
Includes: Array Reversal, String Reversal, Sum of Digits, Maximum/Minimum, Array Sum
"""


# ============= ARRAY REVERSAL =============
def reverse_array_builtin(arr):
    """Reverse array using built-in reversed()"""
    return list(reversed(arr))


def reverse_array_slicing(arr):
    """Reverse array using slicing"""
    return arr[::-1]


def reverse_array_two_pointer(arr):
    """Reverse array using two pointers (in-place)"""
    arr_copy = arr.copy()
    left, right = 0, len(arr_copy) - 1
    while left < right:
        arr_copy[left], arr_copy[right] = arr_copy[right], arr_copy[left]
        left += 1
        right -= 1
    return arr_copy


# ============= STRING REVERSAL =============
def reverse_string_slicing(s):
    """Reverse string using slicing"""
    return s[::-1]


def reverse_string_reversed(s):
    """Reverse string using reversed()"""
    return ''.join(reversed(s))


def reverse_string_loop(s):
    """Reverse string using loop"""
    result = ""
    for char in s:
        result = char + result
    return result


# ============= SUM OF DIGITS =============
def sum_of_digits_string(n):
    """Calculate sum of digits using string conversion"""
    return sum(int(digit) for digit in str(abs(n)))


def sum_of_digits_math(n):
    """Calculate sum of digits using mathematical operations"""
    n = abs(n)
    total = 0
    while n > 0:
        total += n % 10
        n //= 10
    return total


# ============= FIND MAX/MIN =============
def find_max_builtin(arr):
    """Find maximum using built-in max()"""
    return max(arr) if arr else None


def find_max_loop(arr):
    """Find maximum using loop"""
    if not arr:
        return None
    max_val = arr[0]
    for num in arr:
        if num > max_val:
            max_val = num
    return max_val


def find_min_builtin(arr):
    """Find minimum using built-in min()"""
    return min(arr) if arr else None


def find_min_loop(arr):
    """Find minimum using loop"""
    if not arr:
        return None
    min_val = arr[0]
    for num in arr:
        if num < min_val:
            min_val = num
    return min_val


# ============= ARRAY SUM =============
def array_sum_builtin(arr):
    """Calculate sum using built-in sum()"""
    return sum(arr)


def array_sum_loop(arr):
    """Calculate sum using loop"""
    total = 0
    for num in arr:
        total += num
    return total


def array_sum_reduce(arr):
    """Calculate sum using reduce"""
    from functools import reduce
    return reduce(lambda x, y: x + y, arr, 0)


# Test examples
if __name__ == "__main__":
    print("Additional Common Problems - Testing\n")
    print("=" * 60)
    
    # Test Array Reversal
    print("\n1. ARRAY REVERSAL:")
    print("-" * 60)
    test_array = [1, 2, 3, 4, 5]
    print(f"Original array: {test_array}")
    print(f"Built-in:       {reverse_array_builtin(test_array)}")
    print(f"Slicing:        {reverse_array_slicing(test_array)}")
    print(f"Two Pointer:    {reverse_array_two_pointer(test_array)}")
    
    # Test String Reversal
    print("\n2. STRING REVERSAL:")
    print("-" * 60)
    test_string = "Hello World"
    print(f"Original string: '{test_string}'")
    print(f"Slicing:         '{reverse_string_slicing(test_string)}'")
    print(f"Reversed():      '{reverse_string_reversed(test_string)}'")
    print(f"Loop:            '{reverse_string_loop(test_string)}'")
    
    # Test Sum of Digits
    print("\n3. SUM OF DIGITS:")
    print("-" * 60)
    test_numbers = [12345, 999, 1010]
    for num in test_numbers:
        print(f"Number {num}: String method = {sum_of_digits_string(num)}, "
              f"Math method = {sum_of_digits_math(num)}")
    
    # Test Find Max/Min
    print("\n4. FIND MAXIMUM & MINIMUM:")
    print("-" * 60)
    test_array = [45, 12, 78, 23, 90, 5, 67]
    print(f"Array: {test_array}")
    print(f"Maximum (built-in): {find_max_builtin(test_array)}")
    print(f"Maximum (loop):     {find_max_loop(test_array)}")
    print(f"Minimum (built-in): {find_min_builtin(test_array)}")
    print(f"Minimum (loop):     {find_min_loop(test_array)}")
    
    # Test Array Sum
    print("\n5. ARRAY SUM:")
    print("-" * 60)
    test_array = [10, 20, 30, 40, 50]
    print(f"Array: {test_array}")
    print(f"Built-in sum(): {array_sum_builtin(test_array)}")
    print(f"Loop:           {array_sum_loop(test_array)}")
    print(f"Reduce:         {array_sum_reduce(test_array)}")
