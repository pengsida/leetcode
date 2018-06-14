class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] >= target)
                return i;
        }
        return size;
    }
};

class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right + 1;
    }
};
