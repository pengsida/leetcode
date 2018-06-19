#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

public:
    void dfs(vector<int>& candidates, int pos, int sum, int target) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        if (pos == candidates.size())
            return;
        for (int i = pos; i < candidates.size();) {
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], target);
            path.pop_back();
            while (i + 1 != candidates.size() && candidates[i + 1] == candidates[i])
                i++;
            i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size();) {
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, candidates[i], target);
            path.pop_back();
            while (i + 1 != candidates.size() && candidates[i + 1] == candidates[i])
                i++;
            i++;
        }
        return ans;
    }
};
