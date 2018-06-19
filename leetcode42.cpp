#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int max_id = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > height[max_id])
                max_id = i;
        }
        int ans = 0;
        for (int i = 0; i < max_id; i++) {
            int tmp = 0;
            auto h = height[i];
            while (height[i + 1] < h) {
                tmp = tmp + h - height[i + 1];
                i++;
            }
            ans += tmp;
        }
        for (int i = height.size() - 1; i > max_id; i--) {
            int tmp = 0;
            auto h = height[i];
            while (height[i - 1] < h) {
                tmp = tmp + h - height[i - 1];
                i--;
            }
            ans += tmp;
        }
        return ans;
    }
};
