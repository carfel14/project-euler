#include <iostream>

class Solution {
    public:
        int multiplesOf3And5 (int limit) {
            return arithmeticSum(3, limit) 
            + arithmeticSum(5, limit)
            - arithmeticSum(15, limit);
        }

        int arithmeticSum(int a, int n) {
            // number of terms
            int k = (n - 1) / a;
            return a * k * (k + 1) / 2;
        }
};

int main() {
    Solution driver;
    int ans = driver.multiplesOf3And5(1000);

    std::cout << ans << std::endl;
    std::getchar();
}
