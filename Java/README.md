# Java Practice Questions

This folder contains basic programming solutions in Java for junior developer roles.

## Palindrome Checker (Palindrome.java)

A comprehensive palindrome checking solution with multiple implementation methods.

### Methods Included:

1. **StringBuilder Reverse** - Uses StringBuilder's reverse method
2. **Two Pointer Method** - Efficient approach using two pointers from both ends
3. **Recursive Method** - Implements palindrome checking using recursion
4. **Character Array Method** - Converts string to char array for comparison
5. **StringBuffer Method** - Uses StringBuffer for reversing the string

### Compiling and Running:

```bash
javac Palindrome.java
java Palindrome
```

### Time and Space Complexity:

- Most methods: O(n) time complexity
- Two Pointer method: O(1) space complexity (most efficient)
- Others: O(n) space complexity

### Example Usage:

```java
boolean result = Palindrome.isPalindromeTwoPointer("racecar");
System.out.println(result);  // Output: true
```
