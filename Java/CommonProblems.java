/**
 * Additional Common Problems for Junior Developers
 * Includes: Array Reversal, String Reversal, Sum of Digits, Maximum/Minimum, Array Sum
 */

import java.util.Arrays;

public class CommonProblems {

    // ============= ARRAY REVERSAL =============
    
    /**
     * Reverse array using two pointers (in-place)
     */
    public static int[] reverseArrayTwoPointer(int[] arr) {
        int[] result = arr.clone();
        int left = 0, right = result.length - 1;
        
        while (left < right) {
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }
        return result;
    }

    /**
     * Reverse array using loop (creating new array)
     */
    public static int[] reverseArrayLoop(int[] arr) {
        int[] result = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = arr[arr.length - 1 - i];
        }
        return result;
    }

    // ============= STRING REVERSAL =============
    
    /**
     * Reverse string using StringBuilder
     */
    public static String reverseStringBuilder(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    /**
     * Reverse string using character array
     */
    public static String reverseStringCharArray(String s) {
        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;
        
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
        return new String(chars);
    }

    /**
     * Reverse string using loop
     */
    public static String reverseStringLoop(String s) {
        String result = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            result += s.charAt(i);
        }
        return result;
    }

    // ============= SUM OF DIGITS =============
    
    /**
     * Calculate sum of digits using string conversion
     */
    public static int sumOfDigitsString(int n) {
        int sum = 0;
        String numStr = String.valueOf(Math.abs(n));
        for (char digit : numStr.toCharArray()) {
            sum += Character.getNumericValue(digit);
        }
        return sum;
    }

    /**
     * Calculate sum of digits using mathematical operations
     */
    public static int sumOfDigitsMath(int n) {
        n = Math.abs(n);
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // ============= FIND MAX/MIN =============
    
    /**
     * Find maximum using loop
     */
    public static int findMaxLoop(int[] arr) {
        if (arr.length == 0) return Integer.MIN_VALUE;
        int max = arr[0];
        for (int num : arr) {
            if (num > max) max = num;
        }
        return max;
    }

    /**
     * Find minimum using loop
     */
    public static int findMinLoop(int[] arr) {
        if (arr.length == 0) return Integer.MAX_VALUE;
        int min = arr[0];
        for (int num : arr) {
            if (num < min) min = num;
        }
        return min;
    }

    // ============= ARRAY SUM =============
    
    /**
     * Calculate sum using loop
     */
    public static int arraySumLoop(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }

    /**
     * Calculate sum using streams (Java 8+)
     */
    public static int arraySumStream(int[] arr) {
        return Arrays.stream(arr).sum();
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Additional Common Problems - Testing\n");
        System.out.println("============================================================");
        
        // Test Array Reversal
        System.out.println("\n1. ARRAY REVERSAL:");
        System.out.println("------------------------------------------------------------");
        int[] testArray = {1, 2, 3, 4, 5};
        System.out.println("Original array: " + Arrays.toString(testArray));
        System.out.println("Two Pointer:    " + Arrays.toString(reverseArrayTwoPointer(testArray)));
        System.out.println("Loop:           " + Arrays.toString(reverseArrayLoop(testArray)));
        
        // Test String Reversal
        System.out.println("\n2. STRING REVERSAL:");
        System.out.println("------------------------------------------------------------");
        String testString = "Hello World";
        System.out.println("Original string: '" + testString + "'");
        System.out.println("StringBuilder:   '" + reverseStringBuilder(testString) + "'");
        System.out.println("Char Array:      '" + reverseStringCharArray(testString) + "'");
        System.out.println("Loop:            '" + reverseStringLoop(testString) + "'");
        
        // Test Sum of Digits
        System.out.println("\n3. SUM OF DIGITS:");
        System.out.println("------------------------------------------------------------");
        int[] testNumbers = {12345, 999, 1010};
        for (int num : testNumbers) {
            System.out.printf("Number %d: String method = %d, Math method = %d%n",
                num, sumOfDigitsString(num), sumOfDigitsMath(num));
        }
        
        // Test Find Max/Min
        System.out.println("\n4. FIND MAXIMUM & MINIMUM:");
        System.out.println("------------------------------------------------------------");
        int[] testArray2 = {45, 12, 78, 23, 90, 5, 67};
        System.out.println("Array: " + Arrays.toString(testArray2));
        System.out.println("Maximum: " + findMaxLoop(testArray2));
        System.out.println("Minimum: " + findMinLoop(testArray2));
        
        // Test Array Sum
        System.out.println("\n5. ARRAY SUM:");
        System.out.println("------------------------------------------------------------");
        int[] testArray3 = {10, 20, 30, 40, 50};
        System.out.println("Array: " + Arrays.toString(testArray3));
        System.out.println("Loop sum:   " + arraySumLoop(testArray3));
        System.out.println("Stream sum: " + arraySumStream(testArray3));
    }
}
