#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

public:
    void dfs(vector<int>& candidates, int pos, int sum, int target) {
        if (pos == candidates.size())
            return;
        int tmp = sum;
        sum = sum + candidates[pos];
        path.push_back(candidates[pos]);
        if (sum == target)
            ans.push_back(path);
        else if (sum < target)
            dfs(candidates, pos, sum, target);
        path.pop_back();
        dfs(candidates, pos + 1, tmp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return ans;
    }
};
