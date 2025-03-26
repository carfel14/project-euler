#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int evenFibonacciNumbers (int limit) {
            int a = 1, b = 2;
            int ans = 0;
            while (b <= limit) {
                if (b % 2 == 0) ans += b;
                int temp = b;
                b = b + a;
                a = temp;
            }
            return ans;
        }


};

int main() {
    Solution driver;
    int ans = driver.evenFibonacciNumbers(4000000);

    std::cout << ans << '\n';
    std::getchar();
}
