#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> // For std::gcd in C++17

using namespace std;
using namespace std::chrono;

// Solution 1: Prime Factorization + Sieve (Your Approach)
class Solution1 {
public:
    long long smallestMultiple(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        long long smallest = 1;

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                for (int multiplier = 2; multiplier * i <= limit; multiplier++) {
                    isPrime[multiplier * i] = false;
                }
                int largestPowerOfI = i;
                while (largestPowerOfI * i <= limit) {
                    largestPowerOfI *= i;
                }
                smallest *= largestPowerOfI;
            }
        }
        return smallest;
    }
};

// Solution 2: Iterative LCM using GCD (Alternative Approach)
class Solution2 {
public:
    long long smallestMultiple(int limit) {
        long long lcm = 1;
        for (int i = 2; i <= limit; i++) {
            lcm = (lcm * i) / gcd(lcm, i);
        }
        return lcm;
    }

private:
    // Custom GCD function (if not using C++17)
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

// Benchmarking function
void benchmark(int limit, int iterations = 1000) {
    Solution1 sol1;
    Solution2 sol2;

    // Benchmark Solution 1
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        volatile long long result = sol1.smallestMultiple(limit); // volatile to prevent optimization
    }
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1).count();

    // Benchmark Solution 2
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        volatile long long result = sol2.smallestMultiple(limit);
    }
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2).count();

    // Print results
    cout << "Benchmark for limit = " << limit << " (" << iterations << " iterations)\n";
    cout << "Solution 1 (Prime Sieve): " << duration1 << " microseconds\n";
    cout << "Solution 2 (GCD-based):   " << duration2 << " microseconds\n";
    cout << "----------------------------------------\n";
}

int main() {
    // Benchmark for different limits
    benchmark(20);      // Small limit (Problem 5)
    benchmark(100);     // Medium limit
    benchmark(1000);    // Large limit
    benchmark(10000);   // Very large limit (may take time)
    benchmark(100000);

    std::getchar();

    return 0;
}