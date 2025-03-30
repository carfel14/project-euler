#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countingSundays() {
        // calculate days from 1 Jan 1901 to 31 Dec 2000
        int totalDays = 100 * 365;
        // A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
        totalDays += 100 / 4;
        // if 1 Jan 1900 is monday, find 1 Jan 1901
        // 0 is monday, 1 is tuesday... 6 is sunday
        vector<int> daysInMonth = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // actualDay will be 1
        int actualDay = 365 % 7;
        int sundayCount = 0;

        for (int year = 1; year <= 100; year++) {
            for (int i = 0; i < daysInMonth.size(); i++) {
                int increment;
                if (i != 1) {
                    increment = daysInMonth[i];
                } else {
                    increment = year % 4 == 0 ? 29 : 28;
                }
                actualDay = (actualDay + increment) % 7;
                
                if (actualDay == 6) sundayCount++;
            }
        }


        return sundayCount;
    }
};

int main() {
    Solution driver;
    int ans = driver.countingSundays();
    cout << ans << '\n'; 
    getchar();
}