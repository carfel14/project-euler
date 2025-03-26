#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int specialPythagoreanTriplet() {
        int goal = 1000;
        int a = 3, b = 4, c = 5;
        int multiplier = 1;
        while (multiplier * (a + b + c) <= 1000) {
            if (multiplier * (a + b + c) == 1000) return a * b *c;
            multiplier++;
        }

        return -1;
    }
};

int main() {
    Solution driver;
    int ans = driver.specialPythagoreanTriplet();
    cout << ans << '\n'; 
    std::getchar();
}