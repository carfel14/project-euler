#include <iostream>
#include <vector>
using namespace std;

class Solution {
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

int main() {
    Solution driver;
    long long ans = driver.smallestMultiple(20);
    cout << ans << '\n'; 
    std::getchar();
}