#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    long long largeSum() {
        const int LEN = 50;
        vector<string> numberStrings;
        ifstream file("numbers.txt");
        string str;

        while (getline(file, str)) {
            numberStrings.push_back(str);
        }

        vector<int> digits(LEN + 10, 0);

        for (int i = LEN - 1; i >= 0; i--) {
            int columnSum = 0;
            for (auto &number: numberStrings) {
                columnSum += number[i] - '0';
            }
            int pos = (LEN - 1 - i) + 2;
            digits[pos] += columnSum;

            int current = pos;
            while (digits[current] >= 10) {    
                digits[current + 1] += digits[current] / 10;
                digits[current] %= 10;
                current++;
            }
        }

        int startingIndex = 0;

        int firstNonZero = digits.size() - 1;
        while (firstNonZero >= 0 && digits[firstNonZero] == 0) {
            firstNonZero--;
        }

        long long number = 0;
        for (int i = firstNonZero; i >= firstNonZero - 9; i--) {
            number = number * 10 + digits[i];
        }

        return number;
    }
};

int main() {
    Solution driver;
    long long ans = driver.largeSum();
    cout << ans << '\n'; 
    std::getchar();
}