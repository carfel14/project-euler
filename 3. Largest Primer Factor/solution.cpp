#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        long long largestPrimeFactor (long long n) {
            long long lastPrimeFactor = -1;
            while (n % 2 == 0) {
                n /= 2;
                lastPrimeFactor = 2;
            }
            // skip over even numbers
            for (long long i = 3; n > 1; i += 2) {
                while (n % i == 0) {
                    n /= i;
                    lastPrimeFactor = i;
                } 
            }
            return lastPrimeFactor;
        }


};

int main() {
    Solution driver;
    // int ans = driver.largestPrimeFactor(13195);
    long long ans = driver.largestPrimeFactor(600851475143);

    std::cout << ans << '\n';
    std::getchar();
}
