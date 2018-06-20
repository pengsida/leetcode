#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)  {
        vector<int> rec;
        int ans = 0;
        int nr_left = 0;
        for (auto w : s) {
            if (w == '(') {
                rec.push_back(-1);
                nr_left++;
                continue;
            }
            nr_left--;
            if (nr_left < 0) {
                rec.clear();
                nr_left = 0;
                continue;
            }
            if (rec.back() == -1) {
                rec.pop_back();
                if (rec.empty() || rec.back() == -1)
                    rec.push_back(2);
                else
                    rec.back() = rec.back() + 2;
            } else {
                int tmp = rec.back() + 2;
                rec.pop_back();
                rec.pop_back();
                if (rec.empty() || rec.back() == -1)
                    rec.push_back(tmp);
                else
                    rec.back() = rec.back() + tmp;
            }
            if (rec.back() > ans)
                ans = rec.back();
        }
        return ans;
    }
};
