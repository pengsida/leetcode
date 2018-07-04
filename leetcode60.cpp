#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int num = 1;
        for (int i = 1; i < n; i++)
            num = num * i;
        vector<bool> visit(n, false);
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            int nr = (k - 1) / num;
            k = k - nr * num;
            for (int j = 0; j < n; j++) {
                if (visit[j])
                    continue;
                if (nr-- != 0)
                    continue;
                ans[i] = (j + 1 + '0');
                visit[j] = true;
                break;
            }
            if (n - i - 1 == 0)
                break;
            num = num / (n - i - 1);
        }
        return ans;
    }
};
