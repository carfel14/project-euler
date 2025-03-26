#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long SumSquareDifference(int limit) {
        long long sum = ((limit + 1) * limit) / 2;
        long long squareOfTheSum = sum * sum;
        long long sumOfTheSquares = 0;

        for (int i = 1; i <= limit; i++) {
            sumOfTheSquares += i * i;
        }

        return squareOfTheSum - sumOfTheSquares;
    }
};

int main() {
    Solution driver;
    long long ans = driver.SumSquareDifference(100);
    cout << ans << '\n'; 
    std::getchar();
}