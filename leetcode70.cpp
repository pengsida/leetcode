#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int prev1 = 1;
        int prev2 = 2;
        n -= 2;
        while (n != 0) {
            int tmp = prev1;
            prev1 = prev2;
            prev2 = tmp + prev2;
            n--;
        }
        return prev2;
    }
};
