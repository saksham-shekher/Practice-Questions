# Python Practice Questions

This folder contains basic programming solutions in Python for junior developer roles.

## Palindrome Checker (palindrome.py)

A comprehensive palindrome checking solution with multiple implementation methods.

### Methods Included:

1. **String Reversal Method** - Uses Python's slice notation to reverse the string
2. **Two Pointer Method** - Efficient approach using two pointers from both ends
3. **Recursive Method** - Implements palindrome checking using recursion
4. **Built-in Reversed Method** - Uses Python's built-in `reversed()` function
5. **List Comparison Method** - Converts string to list and compares

### Running the Code:

```bash
python palindrome.py
```

### Time and Space Complexity:

- Most methods: O(n) time complexity
- Two Pointer method: O(1) space complexity (most efficient)
- Others: O(n) space complexity

### Example Usage:

```python
from palindrome import is_palindrome_two_pointer

result = is_palindrome_two_pointer("racecar")
print(result)  # Output: True
```
