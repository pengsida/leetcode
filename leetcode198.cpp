#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_prev = 0;
        int prev = 0;
        for (auto cur : nums) {
            int tmp = prev;
            prev = max(prev_prev + cur, tmp);
            prev_prev = tmp;
        }
        return prev;
    }
};
