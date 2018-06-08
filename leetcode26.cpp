class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int prev = nums[0];
        auto it = nums.begin();
        it++;
        while (it != nums.end()) {
            if (*it == prev)
                it = nums.erase(it);
            else {
                prev = *it;
                it++;
            }
        }
        return nums.size();
    }
};
