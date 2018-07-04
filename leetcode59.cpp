#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

public:
    void dfs(int num, int i, int j, int l, int r, int u, int d) {
        if (l > r || u > d)
            return;
        if (l == r) {
            for (int i = u; i <= d; i++)
                ans[i][l] = num++;
            return;
        }
        if (u == d) {
            for (int i = l; i <= r; i++)
                ans[u][i] = num++;
            return;
        }
        for (int i = l; i < r; i++)
            ans[u][i] = num++;
        for (int i = u; i < d; i++)
            ans[i][r] = num++;
        for (int i = r; i > l; i--)
            ans[d][i] = num++;
        for (int i = d; i > u; i--)
            ans[i][l] = num++;
        dfs(num, i + 1, j + 1, l + 1, r - 1, u + 1, d - 1);
    }

    vector<vector<int>> generateMatrix(int n) {
        ans = vector<vector<int>>(n, vector<int>(n, 0));
        dfs(1, 0, 0, 0, n - 1, 0, n - 1);
        return ans;
    }
};
