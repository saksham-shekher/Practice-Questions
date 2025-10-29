"""
Prime Number Checker - Multiple Methods
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
"""


def is_prime_basic(n):
    """
    Method 1: Basic approach - check all numbers up to n
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    for i in range(3, n, 2):
        if n % i == 0:
            return False
    
    return True


def is_prime_optimized(n):
    """
    Method 2: Optimized - check only up to sqrt(n)
    Time Complexity: O(sqrt(n))
    Space Complexity: O(1)
    """
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    
    return True


def is_prime_sqrt(n):
    """
    Method 3: Using square root
    Time Complexity: O(sqrt(n))
    Space Complexity: O(1)
    """
    import math
    
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    
    return True


def generate_primes_sieve(limit):
    """
    Method 4: Sieve of Eratosthenes (for generating multiple primes)
    Time Complexity: O(n log log n)
    Space Complexity: O(n)
    """
    if limit < 2:
        return []
    
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, limit + 1, i):
                is_prime[j] = False
    
    return [num for num in range(limit + 1) if is_prime[num]]


def first_n_primes(n):
    """
    Method 5: Generate first n prime numbers
    """
    primes = []
    num = 2
    
    while len(primes) < n:
        if is_prime_optimized(num):
            primes.append(num)
        num += 1
    
    return primes


# Test examples
if __name__ == "__main__":
    print("Prime Number Checker - Testing All Methods\n")
    print("=" * 60)
    
    test_numbers = [1, 2, 3, 4, 5, 10, 11, 17, 20, 29, 30, 97, 100]
    
    print("Individual Number Tests:")
    print("-" * 60)
    for num in test_numbers:
        print(f"Number {num:3d}: Method 1: {is_prime_basic(num)}, "
              f"Method 2: {is_prime_optimized(num)}, "
              f"Method 3: {is_prime_sqrt(num)}")
    
    print("\n" + "=" * 60)
    print("Sieve of Eratosthenes - Prime numbers up to 50:")
    print(generate_primes_sieve(50))
    
    print("\n" + "=" * 60)
    print("First 15 prime numbers:")
    print(first_n_primes(15))
