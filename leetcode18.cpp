class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < size - 3; i++) {
            for (int j = i + 1; j < size - 2; j++) {
                int l = j + 1;
                int r = size - 1;
                int sum = nums[i] + nums[j] - target;
                while (l < r) {
                    int tmp = sum + nums[l] + nums[r];
                    if (tmp < 0)
                        l++;
                    else if (tmp > 0)
                        r--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l + 1] == nums[l])
                            l++;
                        l++;
                    }
                }
                while (j + 1 < size - 2 && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < size - 3 && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};
