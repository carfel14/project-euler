#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int maximumPathSum() {
        // approach will be dp from bottom to top.
        vector<vector<int>> dp; // max score reaching the number
        // select max from bottomrow[i] and bottomrow[i + 1]
        readTriangle(dp);
        int rows = dp.size();
        // start from second row from bottom
        for (int i = rows - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]); 
            }
        }

        return dp[0][0];
    }

    void readTriangle(vector<vector<int>> &dp) {
        string path = "triangle.txt";
        ifstream file(path);
        string row;
        
        while (getline(file, row)) {
            stringstream ss(row);
            string num;
            vector<int> nums;
            while (getline(ss, num, ' ')){
                nums.push_back(stoi(num));
            }
            dp.push_back(nums);
        }
    }
};

int main() {
    Solution driver;
    int ans = driver.maximumPathSum();
    cout << ans << '\n'; 
    getchar();
}