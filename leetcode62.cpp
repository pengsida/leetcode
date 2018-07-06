#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

public:
    int uniquePaths(int m, int n) {
        ans = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            ans[i][0] = 1;
        for (int j = 0; j < n; j++)
            ans[0][j] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j != 0)
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
        return ans[m - 1][n - 1];
    }
};
