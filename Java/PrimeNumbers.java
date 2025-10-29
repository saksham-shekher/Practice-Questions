/**
 * Prime Number Checker - Multiple Methods
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 */

import java.util.ArrayList;
import java.util.List;

public class PrimeNumbers {

    /**
     * Method 1: Basic approach - check all numbers up to n
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isPrimeBasic(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        for (int i = 3; i < n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    /**
     * Method 2: Optimized - check only up to sqrt(n)
     * Time Complexity: O(sqrt(n))
     * Space Complexity: O(1)
     */
    public static boolean isPrimeOptimized(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    /**
     * Method 3: Using square root
     * Time Complexity: O(sqrt(n))
     * Space Complexity: O(1)
     */
    public static boolean isPrimeSqrt(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    /**
     * Method 4: Sieve of Eratosthenes (for generating multiple primes)
     * Time Complexity: O(n log log n)
     * Space Complexity: O(n)
     */
    public static List<Integer> generatePrimesSieve(int limit) {
        List<Integer> primes = new ArrayList<>();
        if (limit < 2) return primes;
        
        boolean[] isPrime = new boolean[limit + 1];
        for (int i = 2; i <= limit; i++) {
            isPrime[i] = true;
        }
        
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) primes.add(i);
        }
        return primes;
    }

    /**
     * Method 5: Generate first n prime numbers
     */
    public static List<Integer> firstNPrimes(int n) {
        List<Integer> primes = new ArrayList<>();
        int num = 2;
        
        while (primes.size() < n) {
            if (isPrimeOptimized(num)) {
                primes.add(num);
            }
            num++;
        }
        return primes;
    }

    // Test examples
    public static void main(String[] args) {
        System.out.println("Prime Number Checker - Testing All Methods\n");
        System.out.println("============================================================");
        
        int[] testNumbers = {1, 2, 3, 4, 5, 10, 11, 17, 20, 29, 30, 97, 100};
        
        System.out.println("Individual Number Tests:");
        System.out.println("------------------------------------------------------------");
        for (int num : testNumbers) {
            System.out.printf("Number %3d: Method 1: %5s, Method 2: %5s, Method 3: %5s%n",
                num, isPrimeBasic(num), isPrimeOptimized(num), isPrimeSqrt(num));
        }
        
        System.out.println("\n============================================================");
        System.out.println("Sieve of Eratosthenes - Prime numbers up to 50:");
        System.out.println(generatePrimesSieve(50));
        
        System.out.println("\n============================================================");
        System.out.println("First 15 prime numbers:");
        System.out.println(firstNPrimes(15));
    }
}
