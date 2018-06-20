#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> visit;
    int ans = 0;

    bool valid(vector<vector<int>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        if (i >= row || i < 0)
            return false;
        if (j >= col || j < 0)
            return false;
        if (visit[i][j] || grid[i][j] == 0)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& sum) {
        sum++;
        if (sum > ans)
            ans = sum;
        visit[i][j] = true;
        if (valid(grid, i - 1, j))
            dfs(grid, i - 1, j, sum);
        if (valid(grid, i + 1, j))
            dfs(grid, i + 1, j, sum);
        if (valid(grid, i, j - 1))
            dfs(grid, i, j - 1, sum);
        if (valid(grid, i, j + 1))
            dfs(grid, i, j + 1, sum);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        visit = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0)
                    continue;
                if (visit[i][j])
                    continue;
                int sum = 0;
                dfs(grid, i, j, sum);
            }
        }
        return ans;
    }
};
