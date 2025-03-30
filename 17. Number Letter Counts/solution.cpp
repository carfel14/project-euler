#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberLetterCounts() {
        // count first 1000 numbers letters
        // count of letters in single digits 1-9
        vector<int> singleDigitCount = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
        // count from twenty to ninety. 0 for 0 double digits starting with 10 will be handled separately
        vector<int> doubleDigitCount {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
        // count of letters in double digits 10-19
        vector<int> tenCount = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
        // the hundreds use the single digits prefixes + "hundred"

        int count = 0;
        for (int i = 1; i <= 999; i++) {
            int numberCount = 0;
            int unidad = i % 10;
            int decena = (i % 100) / 10;
            int centena = (i % 1000) / 100;

            if (decena == 1) {
                numberCount += tenCount[unidad];
            } else {
                numberCount += singleDigitCount[unidad];
                numberCount += doubleDigitCount[decena];
            }

            if (centena > 0) {
                // account for the words "hundred" (7), "and" (3)
                numberCount += 10;
                numberCount += singleDigitCount[centena];
                if (decena == 0 && unidad == 0) {
                    // one hundred, two hundred and so on.. doesn't include and
                    numberCount -= 3;
                }
            }
            // cout << i << " " << numberCount << endl;
            count += numberCount;
        }
        // word one thousand
        count += 11;
       
        return count;
    }
};

int main() {
    Solution driver;
    int ans = driver.numberLetterCounts();
    cout << ans << '\n'; 
    getchar();
}