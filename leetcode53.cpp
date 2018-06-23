#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = 0;
        int ans = nums[0];
        int size = nums.size();
        int tmp = 0;
        while (right < size) {
            tmp = tmp + nums[right];
            if (tmp > ans)
                ans = tmp;
            if (tmp < 0)
                tmp = 0;
            right++;
        }
        return ans;
    }
};
