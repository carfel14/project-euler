#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int factorialDigitSum(int factorial) {
        const int LEN = 200;
        vector<int> digits(LEN, 0);
        digits[0] = 1;
        int maxIndex = 0;

        for (int i = 2; i <= factorial; i++) {
            int carry = 0;
            for (int j = maxIndex; j >= 0; j--) {
                int product = digits[j] * i + carry;
                digits[j] = product % 10;
                carry = product / 10;
            }
            
            while (carry) {
                digits.insert(digits.begin(), carry % 10);
                carry /= 10;
                maxIndex++;
            }
        }
        // cout << "maxIndex: " << maxIndex << endl;
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
    int ans = driver.factorialDigitSum(100);
    cout << ans << '\n'; 
    getchar();
}