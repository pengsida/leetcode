class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int min_dlt = (nums[0] + nums[1] + nums[size - 1]) - target;
        for (int i = 0; i < size - 2; i++) {
            int l = i + 1;
            int r = size - 1;
            int t = nums[i] - target;
            while (l < r) {
                int tmp = t + nums[l] + nums[r];
                if (abs(tmp) < abs(min_dlt))
                    min_dlt = tmp;
                if (tmp < 0)
                    l++;
                else if (tmp > 0)
                    r--;
                else
                    return target;
            }
        }
        return min_dlt + target;
    }
};
