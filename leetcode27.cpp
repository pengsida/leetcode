class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it != val)
                it++;
            else
                it = nums.erase(it);
        }
        return nums.size();
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[cur] = nums[i];
                cur++;
            }
        }
        return cur;
    }
};
