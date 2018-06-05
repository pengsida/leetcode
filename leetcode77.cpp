class Solution {
public:
    vector<vector<int>> _combine(int l, int n, int k) {
        vector<vector<int>> ans;
        if (k == 1) {
            for (int i = l; i <= n - k + 1; i++)
                ans.push_back(vector<int>(1, i));
            return ans;
        }
        
        for (int i = l; i <= n - k + 1; i++) {
            auto tmp = _combine(i + 1, n, k - 1);
            for (auto t : tmp) {
                ans.push_back(vector<int>(1, i));
                ans.back().insert(ans.back().end(), t.begin(), t.end());
            }
        }
        return ans;
    }
        
    vector<vector<int>> combine(int n, int k) {
        return _combine(1, n, k);
    }
};
