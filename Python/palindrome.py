"""
Palindrome Checker - Multiple Methods
A palindrome is a word, phrase, number, or other sequence of characters 
that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).
"""


def is_palindrome_reverse(s):
    """
    Method 1: Using string reversal
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    # Remove spaces and convert to lowercase
    s = s.replace(" ", "").lower()
    return s == s[::-1]


def is_palindrome_two_pointer(s):
    """
    Method 2: Using two pointers (efficient)
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    # Remove spaces and convert to lowercase
    s = s.replace(" ", "").lower()
    left = 0
    right = len(s) - 1
    
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    
    return True


def is_palindrome_recursive(s):
    """
    Method 3: Using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) - due to recursion stack
    """
    # Remove spaces and convert to lowercase
    s = s.replace(" ", "").lower()
    
    # Helper recursive function
    def check_palindrome(s, left, right):
        if left >= right:
            return True
        if s[left] != s[right]:
            return False
        return check_palindrome(s, left + 1, right - 1)
    
    return check_palindrome(s, 0, len(s) - 1)


def is_palindrome_builtin(s):
    """
    Method 4: Using built-in reversed() function
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    # Remove spaces and convert to lowercase
    s = s.replace(" ", "").lower()
    return s == ''.join(reversed(s))


def is_palindrome_list_compare(s):
    """
    Method 5: Using list comparison
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    # Remove spaces and convert to lowercase
    s = s.replace(" ", "").lower()
    return list(s) == list(reversed(s))


# Test examples
if __name__ == "__main__":
    test_cases = [
        "racecar",
        "hello",
        "A man a plan a canal Panama",
        "madam",
        "python",
        "12321",
        "12345"
    ]
    
    print("Palindrome Checker - Testing All Methods\n")
    print("-" * 60)
    
    for test in test_cases:
        print(f"\nTesting: '{test}'")
        print(f"  Method 1 (Reverse):      {is_palindrome_reverse(test)}")
        print(f"  Method 2 (Two Pointer):  {is_palindrome_two_pointer(test)}")
        print(f"  Method 3 (Recursive):    {is_palindrome_recursive(test)}")
        print(f"  Method 4 (Built-in):     {is_palindrome_builtin(test)}")
        print(f"  Method 5 (List Compare): {is_palindrome_list_compare(test)}")
