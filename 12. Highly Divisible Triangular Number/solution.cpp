#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    long long highlyDivisibleTriangularNumber(int divisors) {
        long long i = 1;
        long long triangularNumber = 1;

        while (countDivisors(triangularNumber) < divisors) {
            i++;
            triangularNumber = ((i + 1) * (i) ) / 2;
        }

        return triangularNumber;
    }

    int countDivisors(int n) {
        if (n == 1) return 1;
    
        int count = 1; 
    
        if (n % 2 == 0) {
            int exponent = 0;
            while (n % 2 == 0) {
                exponent++;
                n /= 2;
            }
            count *= (exponent + 1);
        }
    
        // Check for odd divisors from 3 to sqrt(n)
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                int exponent = 0;
                while (n % i == 0) {
                    exponent++;
                    n /= i;
                }
                count *= (exponent + 1);
            }
        }
    
        // If remaining n is a prime number > 2
        if (n > 1) {
            count *= 2;
        }
    
        return count;
    }
};

int main() {
    Solution driver;
    long long ans = driver.highlyDivisibleTriangularNumber(500);
    cout << ans << '\n'; 
    std::getchar();
}