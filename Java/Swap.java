/**
 * Number Swapping - Multiple Methods
 * Demonstrates different techniques to swap two variables.
 */

public class Swap {

    /**
     * Method 1: Using temporary variable (most common and readable)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static void swapWithTemp(int a, int b) {
        System.out.println("Before swap: a = " + a + ", b = " + b);
        int temp = a;
        a = b;
        b = temp;
        System.out.println("After swap:  a = " + a + ", b = " + b);
    }

    /**
     * Method 2: Using arithmetic operations (without temp variable)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     * Note: May cause overflow with very large numbers
     */
    public static void swapWithArithmetic(int a, int b) {
        System.out.println("Before swap: a = " + a + ", b = " + b);
        a = a + b;
        b = a - b;
        a = a - b;
        System.out.println("After swap:  a = " + a + ", b = " + b);
    }

    /**
     * Method 3: Using XOR operation
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static void swapWithXOR(int a, int b) {
        System.out.println("Before swap: a = " + a + ", b = " + b);
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        System.out.println("After swap:  a = " + a + ", b = " + b);
    }

    /**
     * Method 4: Using multiplication and division
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     * Note: Doesn't work if either number is 0
     */
    public static void swapWithMultiplication(int a, int b) {
        if (a == 0 || b == 0) {
            System.out.println("Cannot use multiplication method with zero");
            return;
        }
        System.out.println("Before swap: a = " + a + ", b = " + b);
        a = a * b;
        b = a / b;
        a = a / b;
        System.out.println("After swap:  a = " + a + ", b = " + b);
    }

    /**
     * Method 5: Using array (return both values)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int[] swapWithArray(int a, int b) {
        System.out.println("Before swap: a = " + a + ", b = " + b);
        int[] result = {b, a};
        System.out.println("After swap:  a = " + result[0] + ", b = " + result[1]);
        return result;
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Number Swapping - Testing All Methods\n");
        System.out.println("============================================================");
        
        System.out.println("\n1. Swap using Temporary Variable:");
        System.out.println("------------------------------------------------------------");
        swapWithTemp(10, 20);
        
        System.out.println("\n2. Swap using Arithmetic Operations:");
        System.out.println("------------------------------------------------------------");
        swapWithArithmetic(5, 15);
        
        System.out.println("\n3. Swap using XOR:");
        System.out.println("------------------------------------------------------------");
        swapWithXOR(7, 14);
        
        System.out.println("\n4. Swap using Multiplication:");
        System.out.println("------------------------------------------------------------");
        swapWithMultiplication(3, 9);
        
        System.out.println("\n5. Swap using Array:");
        System.out.println("------------------------------------------------------------");
        swapWithArray(100, 200);
    }
}
