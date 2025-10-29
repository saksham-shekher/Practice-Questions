/**
 * Odd/Even Checker - Multiple Methods
 * Determines whether a number is odd or even.
 */

public class OddEven {

    /**
     * Method 1: Using modulo operator (most common)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isEvenModulo(int n) {
        return n % 2 == 0;
    }

    /**
     * Method 2: Using bitwise AND operation
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isEvenBitwise(int n) {
        return (n & 1) == 0;
    }

    /**
     * Method 3: Using division and comparison
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isEvenDivision(int n) {
        return (n / 2) * 2 == n;
    }

    /**
     * Method 4: Using string manipulation (last digit)
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isEvenString(int n) {
        String numStr = String.valueOf(Math.abs(n));
        char lastDigit = numStr.charAt(numStr.length() - 1);
        return "02468".indexOf(lastDigit) != -1;
    }

    /**
     * Comprehensive check returning string
     */
    public static String checkOddEven(int n) {
        return isEvenModulo(n) ? "Even" : "Odd";
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Odd/Even Checker - Testing All Methods\n");
        System.out.println("============================================================");
        
        int[] testNumbers = {0, 1, 2, 15, 20, 37, 100, -5, -8};
        
        for (int num : testNumbers) {
            System.out.println("\nNumber: " + num);
            System.out.println("  Method 1 (Modulo):    " + checkOddEven(num));
            System.out.println("  Method 2 (Bitwise):   " + (isEvenBitwise(num) ? "Even" : "Odd"));
            System.out.println("  Method 3 (Division):  " + (isEvenDivision(num) ? "Even" : "Odd"));
            System.out.println("  Method 4 (String):    " + (isEvenString(num) ? "Even" : "Odd"));
        }
    }
}
