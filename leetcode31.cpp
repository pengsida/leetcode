class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int p_idx = -1;
        int size = nums.size();
        for (int i = size - 1; i >= 1; i--) {
            if (nums[i - 1] >= nums[i])
                continue;
            p_idx = i - 1;
            break;
        }
        if (p_idx == -1) {
            reverse(nums, 0, size - 1);
            return;
        } 
        int c_idx;
        for (int i = size - 1; i > p_idx; i--) {
            if (nums[i] <= nums[p_idx])
                continue;
            c_idx = i;
            break;
        }
        swap(nums[p_idx], nums[c_idx]);
        reverse(nums, p_idx + 1, size - 1);
    }
};
