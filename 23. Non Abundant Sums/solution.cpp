#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
// 297604028 is not the solution
class Solution {
public:
    long long nonAbundantSum() {
        vector<int> abundantNumbers = findAbundantNumbers();
        vector<bool> isSum(28124, false); 

        // Precompute all sums of two abundant numbers
        for (int i = 0; i < abundantNumbers.size(); i++) {
            for (int j = i; j < abundantNumbers.size(); j++) {
                int sum = abundantNumbers[i] + abundantNumbers[j];
                if (sum <= 28123) {
                    isSum[sum] = true;
                } else {
                    break;
                }
            }
        }

        long long total = 0;
        for (int i = 1; i <= 28123; i++) {
            if (!isSum[i]) {
                total += i;
            }
        }

        return total;
    }

    vector<int> findAbundantNumbers() {
        vector<int> abundantNumbers;
        for (int i = 12; i <= 28123; i++) {
            if (properDivisorsSum(i) > i) {
                abundantNumbers.push_back(i);
            }
        } 

        return abundantNumbers;
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

    bool isSumOfTwoAbundantNumbers(int n, vector<int> &abundantNumbers) {
        int i = 0, j = abundantNumbers.size() - 1;
        
        while (i <= j) {
            int sum = abundantNumbers[i] + abundantNumbers[j];

            if (sum == n) {
                return true;
            } else if (sum > n) {
                j--;
            } else if (sum < n) {
                i++;
            }
        }

        return false;
    }
};

int main() {
    Solution driver;
    long long ans = driver.nonAbundantSum();
    cout << ans << '\n'; 
    getchar();
}