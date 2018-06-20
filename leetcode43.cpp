#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> nums1(len1, 0);
        vector<int> nums2(len2, 0);
        for (int i = len1 - 1; i >= 0; i--)
            nums1[len1 - 1 - i] = num1[i] - '0';
        for (int i = len2 - 1; i >= 0; i--)
            nums2[len2 - 1 - i] = num2[i] - '0';
        vector<int> ans;
        ans.reserve(len1 + len2);
        int cur = 0;
        int add = 0;
        for (int i = 0; i < len1; i++) {
            int tmp = nums1[i];
            for (int j = 0; j < len2; j++) {
                cur = tmp * nums2[j] + add;
                if (cur >= 10) {
                    add = cur / 10;
                    cur = cur % 10;
                } else
                    add = 0;
                int k = i + j;
                if (k >= ans.size())
                    ans.push_back(cur);
                else {
                    cur += ans[k];
                    if (cur >= 10) {
                        cur = cur % 10;
                        add++;
                    }
                    ans[k] = cur;
                }
            }
            if (add > 0)
                ans.push_back(add);
        }
        string ret;
        int size = ans.size();
        ret.reserve(size);
        for (int i = size - 1; i >= 0; i--)
            ret.append(1, ans[i] + '0');
        return ret;
    }
};
