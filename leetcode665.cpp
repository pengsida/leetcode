#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int pos) {
        for (int i = pos; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] <= nums[i])
                continue;
            int a = nums[i - 1];
            if (i - 1 == 0)
                nums[i - 1] = nums[i];
            else
                nums[i - 1] = nums[i - 2];
            if (check(nums, i))
                return true;
            nums[i - 1] = a;
            nums[i] = a;
            return check(nums, i + 1);
        }
        return true;
    }
};
