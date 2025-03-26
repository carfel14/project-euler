#include <iostream>
#include <vector>
#include <math.h>
#include<limits.h>
using namespace std;

class Solution {
    public:
        long long largestPalindromeProduct() {
            int largest = INT_MIN;
            for (int i = 999; i >= 1; i--) {
                for (int j = 999; j >= 1; j--) {
                    int actual = i * j;
                    if (isPalyndrome(actual)) largest = max(largest, actual);
                }
            }

            return largest;
        }

        bool isPalyndrome(int n) {
            int original = n;
            int reversed = 0;

            while (n > 0) {
                reversed = reversed * 10 + n % 10;
                n /= 10;
            }
            
            return original == reversed;
        }


};

int main() {
    Solution driver;
    long long ans = driver.largestPalindromeProduct();

    std::cout << ans << '\n';
    std::getchar();
}
