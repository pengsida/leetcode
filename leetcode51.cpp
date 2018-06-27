#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> visit;
    vector<pair<int, int>> rec;

    int find(int i, int j, int cur, int n) {
        for (int k = i; k < n; k++) {
            if (visit[k][j])
                continue;
            rec[cur++] = make_pair(k, j);
        }
        for (int k = 1; ; k++) {
            if (i + k >= n || j + k >= n)
                break;
            if (visit[i + k][j + k])
                continue;
            rec[cur++] = make_pair(i + k, j + k);
        }
        for (int k = 1; ; k++) {
            if (i + k >= n || j - k < 0)
                break;
            if (visit[i + k][j - k])
                continue;
            rec[cur++] = make_pair(i + k, j - k);
        }
        return cur;
    }

    void fill(int left, int right, bool state) {
        int size = rec.size();
        for (; left < right; left++) {
            auto& it = rec[left];
            visit[it.first][it.second] = state;
        }
    }

    void dfs(int i, int n, int left, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (visit[i][j])
                continue;
            int right = find(i, j, left, n);
            path[i][j] = 'Q';
            fill(left, right, true);
            dfs(i + 1, n, right, target - 1);
            path[i][j] = '.';
            fill(left, right, false);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        visit = vector<vector<bool>>(n, vector<bool>(n, false));
        path = vector<string>(n, string(n, '.'));
        rec = vector<pair<int, int>>(n * n, make_pair(0, 0));
        dfs(0, n, 0, n);
        return ans;
    }
};
