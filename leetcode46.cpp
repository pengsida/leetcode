#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> visit;

    void _permute(vector<int>& nums, vector<int>& path, int pos) {
        if (pos == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i])
                continue;
            visit[i] = true;
            path[pos] = nums[i];
            _permute(nums, path, pos + 1);
            visit[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<int> path(len, 0);
        visit = vector<bool>(len, false);
        for (int i = 0; i < len; i++) {
            visit[i] = true;
            path[0] = nums[i];
            _permute(nums, path, 1);
            visit[i] = false;
        }
        return ans;
    }
};
