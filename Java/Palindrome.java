/**
 * Palindrome Checker - Multiple Methods
 * A palindrome is a word, phrase, number, or other sequence of characters
 * that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).
 */

public class Palindrome {

    /**
     * Method 1: Using StringBuilder reverse
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean isPalindromeReverse(String s) {
        // Remove spaces and convert to lowercase
        s = s.replaceAll("\\s+", "").toLowerCase();
        String reversed = new StringBuilder(s).reverse().toString();
        return s.equals(reversed);
    }

    /**
     * Method 2: Using two pointers (efficient)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isPalindromeTwoPointer(String s) {
        // Remove spaces and convert to lowercase
        s = s.replaceAll("\\s+", "").toLowerCase();
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    /**
     * Method 3: Using recursion
     * Time Complexity: O(n)
     * Space Complexity: O(n) - due to recursion stack
     */
    public static boolean isPalindromeRecursive(String s) {
        // Remove spaces and convert to lowercase
        s = s.replaceAll("\\s+", "").toLowerCase();
        return checkPalindromeRecursive(s, 0, s.length() - 1);
    }

    private static boolean checkPalindromeRecursive(String s, int left, int right) {
        if (left >= right) {
            return true;
        }
        if (s.charAt(left) != s.charAt(right)) {
            return false;
        }
        return checkPalindromeRecursive(s, left + 1, right - 1);
    }

    /**
     * Method 4: Using character array comparison
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean isPalindromeCharArray(String s) {
        // Remove spaces and convert to lowercase
        s = s.replaceAll("\\s+", "").toLowerCase();
        char[] chars = s.toCharArray();
        int n = chars.length;

        for (int i = 0; i < n / 2; i++) {
            if (chars[i] != chars[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Method 5: Using StringBuffer
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean isPalindromeStringBuffer(String s) {
        // Remove spaces and convert to lowercase
        s = s.replaceAll("\\s+", "").toLowerCase();
        StringBuffer sb = new StringBuffer(s);
        return s.equals(sb.reverse().toString());
    }

    // Test examples
    public static void main(String[] args) {
        String[] testCases = {
            "racecar",
            "hello",
            "A man a plan a canal Panama",
            "madam",
            "java",
            "12321",
            "12345"
        };

        System.out.println("Palindrome Checker - Testing All Methods\n");
        System.out.println("------------------------------------------------------------");

        for (String test : testCases) {
            System.out.println("\nTesting: '" + test + "'");
            System.out.println("  Method 1 (Reverse):       " + isPalindromeReverse(test));
            System.out.println("  Method 2 (Two Pointer):   " + isPalindromeTwoPointer(test));
            System.out.println("  Method 3 (Recursive):     " + isPalindromeRecursive(test));
            System.out.println("  Method 4 (Char Array):    " + isPalindromeCharArray(test));
            System.out.println("  Method 5 (StringBuffer):  " + isPalindromeStringBuffer(test));
        }
    }
}
