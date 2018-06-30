#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<char> rec;

public:
    bool dfs(vector<int>& nums, int pos) {
        if (rec[pos] == '1')
            return true;
        if (rec[pos] == '2')
            return false;

        int step = nums[pos];
        for (int i = step; i > 0; i--) {
            if (i + pos >= nums.size() - 1) {
                rec[pos] = '1';
                return true;
            }
            if (dfs(nums, pos + i)) {
                rec[pos] = '1';
                return true;
            }
        }
        rec[pos] = '2';
        return false;
    }

    bool canJump(vector<int>& nums) {
        int size = nums.size();
        rec = vector<char>(size, '0');
        rec[size - 1] = '1';
        if (nums.empty())
            return false;
        dfs(nums, 0);
        return rec[0] == '1';
    }
};
