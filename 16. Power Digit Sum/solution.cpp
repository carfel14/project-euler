#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int powerDigitSum(int power) {
        vector<int> digits(1000, 0);
        digits[0] = 1;

        int maxIndex = 0;
        while (power-- > 0) {
            int current = 0;
            bool carrying = false;
            int currentIndex = maxIndex;

            while (current <= currentIndex) {
                digits[current] *= 2;
                // add carry post-multiplication
                if (carrying) {
                    digits[current]++;
                    carrying = false;
                }

                if (digits[current] >= 10) {
                    carrying = true;
                    digits[current] -= 10;
                    // if new digit, extend maxIndex
                    if (current == maxIndex) {
                        maxIndex++;
                        digits[maxIndex]++;
                    } 
                        
                }
                
                current++;
            }
        }
 
        // reconstruct sum of digits
        int sum = 0;
        for (int i = 0; i <= maxIndex; i++) {
            sum += digits[i];
        }

        return sum;
    }
};

int main() {
    Solution driver;
    int ans = driver.powerDigitSum(1000);
    cout << ans << '\n'; 
    getchar();
}