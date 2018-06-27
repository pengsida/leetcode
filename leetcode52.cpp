#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int ans = 0;
    vector<vector<bool>> visit;
    vector<pair<int, int>> rec;

    int find(int i, int j, int left, int n) {
        for (int k = i; k < n; k++) {
            if (visit[k][j])
                continue;
            rec[left++] = make_pair(k, j);
        }
        for (int k = 1; ; k++) {
            if (i + k >= n || j + k >= n)
                break;
            if (visit[i + k][j + k])
                continue;
            rec[left++] = make_pair(i + k, j + k);
        }
        for (int k = 1; ; k++) {
            if (i + k >= n || j - k < 0)
                break;
            if (visit[i + k][j - k])
                continue;
            rec[left++] = make_pair(i + k, j - k);
        }
        return left;
    }

    void fill(int left, int right, bool state) {
        while (left != right) {
            auto& it = rec[left++];
            visit[it.first][it.second] = state;
        }
    }

    void dfs(int i, int n, int left, int target) {
        if (target == 0) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (visit[i][j])
                continue;
            int right = find(i, j, left, n);
            fill(left, right, true);
            dfs(i + 1, n, right, target - 1);
            fill(left, right, false);
        }
    }

public:
    int totalNQueens(int n) {
        visit = vector<vector<bool>>(n, vector<bool>(n, false));
        rec = vector<pair<int, int>>(n * n, make_pair(0, 0));
        dfs(0, n, 0, n);
        return ans;
    }
};
