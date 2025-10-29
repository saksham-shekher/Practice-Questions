# C Practice Questions

This folder contains basic programming solutions in C for junior developer roles.

## Palindrome Checker (palindrome.c)

A comprehensive palindrome checking solution with multiple implementation methods.

### Methods Included:

1. **String Reversal Method** - Creates a reversed copy and compares with original
2. **Two Pointer Method** - Efficient approach using two pointers from both ends
3. **Recursive Method** - Implements palindrome checking using recursion
4. **Character Array Method** - Direct character comparison without creating copies
5. **Dynamic Memory Method** - Uses dynamic memory allocation for cleaned string

### Compiling and Running:

```bash
gcc palindrome.c -o palindrome
./palindrome
```

### Time and Space Complexity:

- Most methods: O(n) time complexity
- Two Pointer & Char Array methods: O(1) space complexity (most efficient)
- Others: O(n) space complexity

### Features:

- Handles spaces in strings
- Case-insensitive comparison
- Multiple implementation approaches for learning purposes

### Example Usage:

All methods are demonstrated in the main() function with various test cases.
