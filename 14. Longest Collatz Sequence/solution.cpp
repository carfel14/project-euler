#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCollatzSequence(int limit) {
        vector<int> numberToLength(limit + 1, 0);
        numberToLength[1] = 1;

        int longest = 1;
        int number = 1;

        for (int i = 2; i < limit; i++) {
            unsigned long long n = i;
            int length = 0;

            while (n != 1 && (n >= i || numberToLength[n] == 0)) {
                length++;
                n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
            }

            numberToLength[i] = length + numberToLength[n];

            if (numberToLength[i] > longest) {
                longest = numberToLength[i];
                number = i;
            }
        }

        return number;
    }
};

int main() {
    Solution driver;
    int ans = driver.longestCollatzSequence(1000000);
    cout << ans << '\n'; 
    getchar();
}