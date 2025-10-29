/**
 * Pattern Printing Programs
 * Common patterns asked in junior developer coding interviews
 */

#include <stdio.h>

/**
 * Pattern 1: Square Pattern
 */
void printSquarePattern(int n) {
    printf("\n1. Square Pattern (%dx%d):\n", n, n);
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 2: Right-Angled Triangle
 */
void printRightTriangle(int n) {
    printf("\n2. Right-Angled Triangle (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 3: Inverted Right-Angled Triangle
 */
void printInvertedRightTriangle(int n) {
    printf("\n3. Inverted Right-Angled Triangle (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 4: Pyramid
 */
void printPyramid(int n) {
    printf("\n4. Pyramid (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        // Print stars
        for (int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 5: Inverted Pyramid
 */
void printInvertedPyramid(int n) {
    printf("\n5. Inverted Pyramid (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = n; i > 0; i--) {
        // Print spaces
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        // Print stars
        for (int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 6: Diamond
 */
void printDiamond(int n) {
    printf("\n6. Diamond (%d rows):\n", n);
    printf("----------------------------------------\n");
    // Upper half (pyramid)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        for (int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    // Lower half (inverted pyramid)
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        for (int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

/**
 * Pattern 7: Hollow Square
 */
void printHollowSquare(int n) {
    printf("\n7. Hollow Square (%dx%d):\n", n, n);
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/**
 * Pattern 8: Number Pattern
 */
void printNumberPattern(int n) {
    printf("\n8. Number Pattern (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

/**
 * Pattern 9: Number Pyramid
 */
void printNumberPyramid(int n) {
    printf("\n9. Number Pyramid (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        for (int k = 0; k < i; k++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

/**
 * Pattern 10: Floyd's Triangle
 */
void printFloydTriangle(int n) {
    printf("\n10. Floyd's Triangle (%d rows):\n", n);
    printf("----------------------------------------\n");
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

/**
 * Pattern 11: Pascal's Triangle
 */
void printPascalTriangle(int n) {
    printf("\n11. Pascal's Triangle (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        // Calculate and print values
        int num = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", num);
            num = num * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

/**
 * Pattern 12: Alphabet Pattern
 */
void printAlphabetPattern(int n) {
    printf("\n12. Alphabet Pattern (%d rows):\n", n);
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", 65 + j);
        }
        printf("\n");
    }
}

// Test all patterns
int main() {
    printf("============================================================\n");
    printf("PATTERN PRINTING PROGRAMS FOR JUNIOR DEVELOPERS\n");
    printf("============================================================\n");
    
    int n = 5;  // Size of patterns
    
    printSquarePattern(n);
    printRightTriangle(n);
    printInvertedRightTriangle(n);
    printPyramid(n);
    printInvertedPyramid(n);
    printDiamond(n);
    printHollowSquare(n);
    printNumberPattern(n);
    printNumberPyramid(n);
    printFloydTriangle(n);
    printPascalTriangle(n);
    printAlphabetPattern(n);
    
    printf("\n============================================================\n");
    printf("All patterns generated successfully!\n");
    printf("============================================================\n");
    
    return 0;
}
