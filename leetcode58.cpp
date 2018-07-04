class Solution {
public:
    int lengthOfLastWord(string s) {
        int left = 0;
        int right = 0;
        int last = 0;
        for(auto w : s) {
            if (w == ' ') {
                last = right == left ? last : right - left;
                left = right + 1;
            }
            right++;
        }
        return right == left ? last : right - left;
    }
};
