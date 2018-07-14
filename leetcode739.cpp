#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size, 0);
        stack<int> tmp;
        for (int i = 0; i < size; i++) {
            if (tmp.empty() || temperatures[tmp.top()] >= temperatures[i])
                tmp.push(i);
            else {
                ans[tmp.top()] = i - tmp.top();
                tmp.pop();
                i--;
            }
        }
        return ans;
    }
};
