#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long nthPrime(int n) {
        vector<bool> isPrime(10000000, true);
        isPrime[0] = isPrime[1] = false;
        int count = 0;

        for (int i = 2; count < n; i++) {
            if (isPrime[i]) {
                for (int multiplier = 2; multiplier * i <= 10000000; multiplier++) {
                    isPrime[multiplier * i] = false;
                }
                if (++count == n) return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution driver;
    long long ans = driver.nthPrime(10001);
    cout << ans << '\n'; 
    std::getchar();
}