#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ans;

public:
    void spiralOrder(vector<vector<int>>& matrix, int u, int l, int d, int r) {
        if (u > d || l > r)
            return;
        if (u == d) {
            while (l <= r)
                ans.push_back(matrix[u][l++]);
            return;
        }
        if (l == r) {
            while (u <= d)
                ans.push_back(matrix[u++][l]);
            return;
        }

        for (int k = l; k < r; k++)
            ans.push_back(matrix[u][k]);
        for (int k = u; k < d; k++)
            ans.push_back(matrix[k][r]);
        for (int k = r; k > l; k--)
            ans.push_back(matrix[d][k]);
        for (int k = d; k > u; k--)
            ans.push_back(matrix[k][l]);

        spiralOrder(matrix, u + 1, l + 1, d - 1, r - 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return ans;
        int row = matrix.size();
        int col = matrix[0].size();
        spiralOrder(matrix, 0, 0, row - 1, col - 1);
        return ans;
    }
};
