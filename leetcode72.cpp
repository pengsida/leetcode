#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> rec(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
            rec[i][0] = i;
        for (int j = 1; j < n + 1; j++)
            rec[0][j] = j;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int tmp = min(rec[i - 1][j], rec[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1])
                    tmp = min(tmp, rec[i - 1][j - 1]);
                else
                    tmp = min(tmp, rec[i - 1][j - 1] + 1);
                rec[i][j] = tmp;
            }
        }
        return rec[m][n];
    }
};
