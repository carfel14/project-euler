#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long summationOfPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        long long sum = 0;

        for (int i = 2; i < limit; i++) {
            if (isPrime[i]) {
                for (int multiplier = 2; multiplier * i <= limit; multiplier++) {
                    isPrime[multiplier * i] = false;
                }
                sum += i;
            }
        }
        return sum;
    }
};

int main() {
    Solution driver;
    long long ans = driver.summationOfPrimes(2000000);
    cout << ans << '\n'; 
    std::getchar();
}