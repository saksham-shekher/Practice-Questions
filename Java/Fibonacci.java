/**
 * Fibonacci Sequence - Multiple Methods
 * The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * Each number is the sum of the two preceding ones.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Fibonacci {

    /**
     * Method 1: Iterative approach
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static List<Integer> fibonacciIterative(int n) {
        List<Integer> fibSequence = new ArrayList<>();
        if (n <= 0) return fibSequence;
        
        fibSequence.add(0);
        if (n == 1) return fibSequence;
        
        fibSequence.add(1);
        for (int i = 2; i < n; i++) {
            fibSequence.add(fibSequence.get(i-1) + fibSequence.get(i-2));
        }
        
        return fibSequence;
    }

    /**
     * Method 2: Recursive approach (not efficient for large n)
     * Time Complexity: O(2^n)
     * Space Complexity: O(n)
     */
    public static int fibRecursive(int n) {
        if (n <= 1) return n;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    public static List<Integer> fibonacciRecursive(int n) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(fibRecursive(i));
        }
        return result;
    }

    /**
     * Method 3: Using memoization (dynamic programming)
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static List<Integer> fibonacciMemoization(int n) {
        List<Integer> result = new ArrayList<>();
        int[] memo = new int[Math.max(n, 2)];
        
        for (int i = 0; i < n; i++) {
            result.add(fibMemo(i, memo));
        }
        return result;
    }

    private static int fibMemo(int n, int[] memo) {
        if (n <= 1) return n;
        if (memo[n] != 0) return memo[n];
        
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];
    }

    /**
     * Method 4: Using array/tabulation (bottom-up dynamic programming)
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static List<Integer> fibonacciTabulation(int n) {
        List<Integer> result = new ArrayList<>();
        if (n <= 0) return result;
        
        int[] fib = new int[Math.max(n, 2)];
        fib[0] = 0;
        fib[1] = 1;
        
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        for (int i = 0; i < n; i++) {
            result.add(fib[i]);
        }
        return result;
    }

    /**
     * Method 5: Space optimized iterative (only store last two numbers)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static List<Integer> fibonacciOptimized(int n) {
        List<Integer> result = new ArrayList<>();
        if (n <= 0) return result;
        
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            result.add(a);
            int next = a + b;
            a = b;
            b = next;
        }
        return result;
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Fibonacci Sequence - Testing All Methods\n");
        System.out.println("============================================================");
        
        int n = 10;
        System.out.println("Generating first " + n + " Fibonacci numbers:\n");
        
        System.out.println("1. Iterative Method:");
        System.out.println(fibonacciIterative(n));
        
        System.out.println("\n2. Recursive Method:");
        System.out.println(fibonacciRecursive(n));
        
        System.out.println("\n3. Memoization Method:");
        System.out.println(fibonacciMemoization(n));
        
        System.out.println("\n4. Tabulation Method:");
        System.out.println(fibonacciTabulation(n));
        
        System.out.println("\n5. Optimized Method:");
        System.out.println(fibonacciOptimized(n));
        
        System.out.println("\n============================================================");
        System.out.println("Generating first 15 Fibonacci numbers (Iterative):");
        System.out.println(fibonacciIterative(15));
    }
}
