#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    long long nthPrime(int n) {
        // 2 is added
        int count = 1;
        long long candidate = 1;

        while (count < n) {
            candidate += 2;
            if(isPrime(candidate)) count++;
        }

        return candidate;
    }

    bool isPrime(long long n) {
        if (n % 2 == 0) return false;
        if (n < 4) return true;
        if (n % 3 == 0) return false;
        if (n < 9) return true;
        
        int maxFactor = std::sqrt(n);
        int f = 5;
        while (f <= maxFactor) {
            // 6k - 1
            if (n % f == 0) return false;
            // 6k + 1
            if (n % (f + 2) == 0) return false;
            f += 6;
        }

        return true;
    }
};

int main() {
    Solution driver;
    long long ans = driver.nthPrime(10001);
    cout << ans << '\n'; 
    std::getchar();
}