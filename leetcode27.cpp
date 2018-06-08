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
