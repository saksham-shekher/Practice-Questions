/**
 * Factorial Calculation - Multiple Methods
 * Factorial of n (n!) is the product of all positive integers less than or equal to n.
 * Example: 5! = 5 × 4 × 3 × 2 × 1 = 120
 */

public class Factorial {

    /**
     * Method 1: Iterative approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long factorialIterative(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    /**
     * Method 2: Recursive approach
     * Time Complexity: O(n)
     * Space Complexity: O(n) - due to recursion stack
     */
    public static long factorialRecursive(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        return n * factorialRecursive(n - 1);
    }

    /**
     * Method 3: Using while loop
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long factorialWhile(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        
        long result = 1;
        int counter = n;
        while (counter > 1) {
            result *= counter;
            counter--;
        }
        return result;
    }

    /**
     * Method 4: Tail recursive approach
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static long factorialTailRecursive(int n) {
        if (n < 0) return -1;
        return factorialTailHelper(n, 1);
    }

    private static long factorialTailHelper(int n, long accumulator) {
        if (n == 0 || n == 1) return accumulator;
        return factorialTailHelper(n - 1, n * accumulator);
    }

    /**
     * Method 5: Using streams (Java 8+)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static long factorialStream(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        
        return java.util.stream.LongStream.rangeClosed(2, n)
                .reduce(1, (long x, long y) -> x * y);
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Factorial Calculation - Testing All Methods\n");
        System.out.println("============================================================");
        
        int[] testNumbers = {0, 1, 5, 10, 12, 15};
        
        for (int num : testNumbers) {
            System.out.println("\nFactorial of " + num + ":");
            System.out.println("  Method 1 (Iterative):      " + factorialIterative(num));
            System.out.println("  Method 2 (Recursive):      " + factorialRecursive(num));
            System.out.println("  Method 3 (While Loop):     " + factorialWhile(num));
            System.out.println("  Method 4 (Tail Recursive): " + factorialTailRecursive(num));
            System.out.println("  Method 5 (Stream):         " + factorialStream(num));
        }
    }
}
