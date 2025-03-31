#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string lexicographicPermutations() {
        // Assumptions: 
        // 10! = 3628800
        // you can get n lexicographic order by constantly dividing
        // ex: dividing between 10 to get what should be the first digit, then, dividing between 9 and so on
        int factorials[10]; 
        factorials[0] = 1;
        for (int i = 1; i < 10; i++) factorials[i] = factorials[i - 1] * i;

        int n = 1000000 - 1; // 0-based index
        vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        string ans = "";

        for (int i = 9; i >= 0; i--) {
            int index = n / factorials[i];  
            ans += to_string(digits[index]); 
            digits.erase(digits.begin() + index);
            n %= factorials[i]; 
        }

        return ans;
    }
};

int main() {
    Solution driver;
    string ans = driver.lexicographicPermutations();
    cout << ans << '\n'; 
    getchar();
}