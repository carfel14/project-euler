#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int amicableNumbers(int limit) {
        // plan: compute score for every number and save into a map with the sum and the count, then calculate number of pairs with (count * (count - 1)) / 2
        unordered_map<int, int> numberToSum;
        int sumOfAmicableNumbers = 0;
        for (int i = 1; i <= limit; i++) {
            int divisorsSum = properDivisorsSum(i);
            
            if (numberToSum.find(divisorsSum) != numberToSum.end()) {
                if (numberToSum[divisorsSum] == i) {
                    // cout << i << " " << divisorsSum << endl;
                    sumOfAmicableNumbers += (i + divisorsSum);
                }
            }
            numberToSum[i] = divisorsSum;
        }

        return sumOfAmicableNumbers;
    }

    int properDivisorsSum(int n) {
        int sum = 1;
        int squareRoot = sqrt(n);
        for (int divisor = 2; divisor <= squareRoot; divisor++) {
            if ((n % divisor) == 0) {
                sum += divisor;
                int quotient = n / divisor;
                if (quotient != divisor) { 
                    sum += quotient;
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution driver;
    int ans = driver.amicableNumbers(10000);
    cout << ans << '\n'; 
    getchar();
}