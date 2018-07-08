#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rec(m, vector<int>(n, 0));
        rec[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            rec[i][0] = rec[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            rec[0][j] = rec[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                rec[i][j] = min(rec[i - 1][j], rec[i][j - 1]);
                rec[i][j] = rec[i][j] + grid[i][j];
            }
        }
        return rec[m - 1][n - 1];
    }
};
