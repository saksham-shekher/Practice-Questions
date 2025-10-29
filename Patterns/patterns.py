"""
Pattern Printing Programs
Common patterns asked in junior developer coding interviews
"""


def print_square_pattern(n):
    """
    Pattern 1: Square Pattern
    * * * * *
    * * * * *
    * * * * *
    * * * * *
    * * * * *
    """
    print(f"\n1. Square Pattern ({n}x{n}):")
    print("-" * 40)
    for i in range(n):
        for j in range(n):
            print("*", end=" ")
        print()


def print_right_triangle(n):
    """
    Pattern 2: Right-Angled Triangle
    *
    * *
    * * *
    * * * *
    * * * * *
    """
    print(f"\n2. Right-Angled Triangle ({n} rows):")
    print("-" * 40)
    for i in range(1, n + 1):
        for j in range(i):
            print("*", end=" ")
        print()


def print_inverted_right_triangle(n):
    """
    Pattern 3: Inverted Right-Angled Triangle
    * * * * *
    * * * *
    * * *
    * *
    *
    """
    print(f"\n3. Inverted Right-Angled Triangle ({n} rows):")
    print("-" * 40)
    for i in range(n, 0, -1):
        for j in range(i):
            print("*", end=" ")
        print()


def print_pyramid(n):
    """
    Pattern 4: Pyramid
        *
       * *
      * * *
     * * * *
    * * * * *
    """
    print(f"\n4. Pyramid ({n} rows):")
    print("-" * 40)
    for i in range(1, n + 1):
        # Print spaces
        for j in range(n - i):
            print(" ", end=" ")
        # Print stars
        for k in range(i):
            print("*", end=" ")
        print()


def print_inverted_pyramid(n):
    """
    Pattern 5: Inverted Pyramid
    * * * * *
     * * * *
      * * *
       * *
        *
    """
    print(f"\n5. Inverted Pyramid ({n} rows):")
    print("-" * 40)
    for i in range(n, 0, -1):
        # Print spaces
        for j in range(n - i):
            print(" ", end=" ")
        # Print stars
        for k in range(i):
            print("*", end=" ")
        print()


def print_diamond(n):
    """
    Pattern 6: Diamond
        *
       * *
      * * *
     * * * *
    * * * * *
     * * * *
      * * *
       * *
        *
    """
    print(f"\n6. Diamond ({n} rows):")
    print("-" * 40)
    # Upper half (pyramid)
    for i in range(1, n + 1):
        for j in range(n - i):
            print(" ", end=" ")
        for k in range(i):
            print("*", end=" ")
        print()
    # Lower half (inverted pyramid)
    for i in range(n - 1, 0, -1):
        for j in range(n - i):
            print(" ", end=" ")
        for k in range(i):
            print("*", end=" ")
        print()


def print_hollow_square(n):
    """
    Pattern 7: Hollow Square
    * * * * *
    *       *
    *       *
    *       *
    * * * * *
    """
    print(f"\n7. Hollow Square ({n}x{n}):")
    print("-" * 40)
    for i in range(n):
        for j in range(n):
            if i == 0 or i == n - 1 or j == 0 or j == n - 1:
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print()


def print_number_pattern(n):
    """
    Pattern 8: Number Pattern
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    """
    print(f"\n8. Number Pattern ({n} rows):")
    print("-" * 40)
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            print(j, end=" ")
        print()


def print_number_pyramid(n):
    """
    Pattern 9: Number Pyramid
        1
       2 2
      3 3 3
     4 4 4 4
    5 5 5 5 5
    """
    print(f"\n9. Number Pyramid ({n} rows):")
    print("-" * 40)
    for i in range(1, n + 1):
        for j in range(n - i):
            print(" ", end=" ")
        for k in range(i):
            print(i, end=" ")
        print()


def print_floyd_triangle(n):
    """
    Pattern 10: Floyd's Triangle
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
    """
    print(f"\n10. Floyd's Triangle ({n} rows):")
    print("-" * 40)
    num = 1
    for i in range(1, n + 1):
        for j in range(i):
            print(num, end=" ")
            num += 1
        print()


def print_pascal_triangle(n):
    """
    Pattern 11: Pascal's Triangle
         1
        1 1
       1 2 1
      1 3 3 1
     1 4 6 4 1
    """
    print(f"\n11. Pascal's Triangle ({n} rows):")
    print("-" * 40)
    for i in range(n):
        # Print spaces
        for j in range(n - i - 1):
            print(" ", end=" ")
        # Calculate and print values
        num = 1
        for j in range(i + 1):
            print(num, end=" ")
            num = num * (i - j) // (j + 1)
        print()


def print_alphabet_pattern(n):
    """
    Pattern 12: Alphabet Pattern
    A
    A B
    A B C
    A B C D
    A B C D E
    """
    print(f"\n12. Alphabet Pattern ({n} rows):")
    print("-" * 40)
    for i in range(n):
        for j in range(i + 1):
            print(chr(65 + j), end=" ")
        print()


# Test all patterns
if __name__ == "__main__":
    print("=" * 60)
    print("PATTERN PRINTING PROGRAMS FOR JUNIOR DEVELOPERS")
    print("=" * 60)
    
    n = 5  # Size of patterns
    
    print_square_pattern(n)
    print_right_triangle(n)
    print_inverted_right_triangle(n)
    print_pyramid(n)
    print_inverted_pyramid(n)
    print_diamond(n)
    print_hollow_square(n)
    print_number_pattern(n)
    print_number_pyramid(n)
    print_floyd_triangle(n)
    print_pascal_triangle(n)
    print_alphabet_pattern(n)
    
    print("\n" + "=" * 60)
    print("All patterns generated successfully!")
    print("=" * 60)
