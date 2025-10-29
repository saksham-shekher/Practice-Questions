/**
 * Pattern Printing Programs
 * Common patterns asked in junior developer coding interviews
 */

public class Patterns {

    /**
     * Pattern 1: Square Pattern
     */
    public static void printSquarePattern(int n) {
        System.out.println("\n1. Square Pattern (" + n + "x" + n + "):");
        System.out.println("----------------------------------------");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 2: Right-Angled Triangle
     */
    public static void printRightTriangle(int n) {
        System.out.println("\n2. Right-Angled Triangle (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 3: Inverted Right-Angled Triangle
     */
    public static void printInvertedRightTriangle(int n) {
        System.out.println("\n3. Inverted Right-Angled Triangle (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 4: Pyramid
     */
    public static void printPyramid(int n) {
        System.out.println("\n4. Pyramid (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            // Print stars
            for (int k = 0; k < i; k++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 5: Inverted Pyramid
     */
    public static void printInvertedPyramid(int n) {
        System.out.println("\n5. Inverted Pyramid (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = n; i > 0; i--) {
            // Print spaces
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            // Print stars
            for (int k = 0; k < i; k++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 6: Diamond
     */
    public static void printDiamond(int n) {
        System.out.println("\n6. Diamond (" + n + " rows):");
        System.out.println("----------------------------------------");
        // Upper half (pyramid)
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            for (int k = 0; k < i; k++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        // Lower half (inverted pyramid)
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            for (int k = 0; k < i; k++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 7: Hollow Square
     */
    public static void printHollowSquare(int n) {
        System.out.println("\n7. Hollow Square (" + n + "x" + n + "):");
        System.out.println("----------------------------------------");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }

    /**
     * Pattern 8: Number Pattern
     */
    public static void printNumberPattern(int n) {
        System.out.println("\n8. Number Pattern (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 9: Number Pyramid
     */
    public static void printNumberPyramid(int n) {
        System.out.println("\n9. Number Pyramid (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            for (int k = 0; k < i; k++) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    /**
     * Pattern 10: Floyd's Triangle
     */
    public static void printFloydTriangle(int n) {
        System.out.println("\n10. Floyd's Triangle (" + n + " rows):");
        System.out.println("----------------------------------------");
        int num = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print(num + " ");
                num++;
            }
            System.out.println();
        }
    }

    /**
     * Pattern 11: Pascal's Triangle
     */
    public static void printPascalTriangle(int n) {
        System.out.println("\n11. Pascal's Triangle (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 0; i < n; i++) {
            // Print spaces
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print("  ");
            }
            // Calculate and print values
            int num = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(num + " ");
                num = num * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }

    /**
     * Pattern 12: Alphabet Pattern
     */
    public static void printAlphabetPattern(int n) {
        System.out.println("\n12. Alphabet Pattern (" + n + " rows):");
        System.out.println("----------------------------------------");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print((char)(65 + j) + " ");
            }
            System.out.println();
        }
    }

    // Test all patterns
    public static void main(String[] args) {
        System.out.println("============================================================");
        System.out.println("PATTERN PRINTING PROGRAMS FOR JUNIOR DEVELOPERS");
        System.out.println("============================================================");
        
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
        
        System.out.println("\n============================================================");
        System.out.println("All patterns generated successfully!");
        System.out.println("============================================================");
    }
}
