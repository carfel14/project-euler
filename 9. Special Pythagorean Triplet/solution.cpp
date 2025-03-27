#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int specialPythagoreanTriplet() {
        for (int a = 500; a > 0; a--) {
            for (int b = 500; b > 0; b--) {
                int c = 1000 - a - b;
                if (isTriplet(a, b, c)) {
                    cout << a << ' ' << b << ' ' << c << endl;
                    return a * b * c;
                }
                    
            }
        }
        return -1;
    }

    bool isTriplet(int a, int b, int c) {
        return (a * a + b * b == c * c);
    }
};

int main() {
    Solution driver;
    int ans = driver.specialPythagoreanTriplet();
    cout << ans << '\n'; 
    std::getchar();
}