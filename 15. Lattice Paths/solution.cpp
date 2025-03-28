#include <iostream>
using namespace std;

class Solution {
public:
    long long latticePaths(int gridDimension) {
        // C(2n n)
        // 2n steps, n choices of going right (or down)
       return binomialCoefficient(2 * gridDimension, gridDimension);
    }

    long long binomialCoefficient(int n, int k) {
        // C(n, k) = n! / (k! * (n-k)!)
        long long res = 1;
        // we compute (n-k)! in the denominator, cancelling the (n-k term) in the denominator
        // and we just divide vy k!
        for (int i = 0; i < k; i++) {
            //
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};

int main() {
    Solution driver;
    long long ans = driver.latticePaths(20);
    cout << ans << '\n'; 
    getchar();
}