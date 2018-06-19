class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left > right)
            return ans;
        int tmp = (left + right) / 2;
        int tmp_left = tmp;
        while (tmp_left <= right) {
            int mid = (tmp_left + right) / 2;
            if (nums[mid] <= target)
                tmp_left = mid + 1;
            else
                right = mid - 1;
        }
        ans[1] = right;
        right = tmp;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        ans[0] = left;
        return ans;
    }
};
