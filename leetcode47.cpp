#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<bool> visit;
    vector<vector<int>> ans;

    void _permute(vector<int>& nums, vector<int>& path, int pos) {
        int len = nums.size();
        if (pos == len) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visit[i])
                continue;
            visit[i] = true;
            path[pos] = nums[i];
            _permute(nums, path, pos + 1);
            visit[i] = false;
            while (i + 1 != len && nums[i + 1] == nums[i])
                i++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        visit = vector<bool>(len, false);
        vector<int> path(len, 0);
        sort(nums.begin(), nums.end());
        _permute(nums, path, 0);
        return ans;
    }
};
