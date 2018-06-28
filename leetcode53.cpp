#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = 0;
        int ans = nums[0];
        int size = nums.size();
        int tmp = 0;
        while (right < size) {
            tmp = tmp + nums[right];
            if (tmp > ans)
                ans = tmp;
            if (tmp < 0)
                tmp = 0;
            right++;
        }
        return ans;
    }
};

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void divide_and_comquer(vector<int>& nums, int left, int right, int& mx, int& lmx, int& rmx, int& tol) {
        if (left == right) {
            mx = lmx = rmx = tol = nums[left];
        } else {
            int mid = (left + right) / 2;
            int mx1, lmx1, rmx1, tol1;
            int mx2, lmx2, rmx2, tol2;
            divide_and_comquer(nums, left, mid, mx1, lmx1, rmx1, tol1);
            divide_and_comquer(nums, mid + 1, right, mx2, lmx2, rmx2, tol2);
            tol = tol1 + tol2;
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, tol1 + lmx2);
            rmx = max(rmx2, tol2 + rmx1);
        }
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int mx, lmx, rmx, tol;
        divide_and_comquer(nums, 0, nums.size() - 1, mx, lmx, rmx, tol);
        return mx;
    }
};
