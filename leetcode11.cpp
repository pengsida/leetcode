class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int tmp = (r - l) * min(height[l], height[r]);
            if (tmp > ans)
                ans = tmp;
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
