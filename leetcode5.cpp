class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int size = s.length();
        int rec_l = 0;
        int max_len = 1;
        for (int i = 0; i < size;) {
            int left = i;
            int right = i;
            while (right < size - 1 && s[right + 1] == s[right])
                right++;
            i = right + 1;
            while (right < size - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if (right - left + 1 > max_len) {
                rec_l = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(rec_l, max_len);
    }
};
