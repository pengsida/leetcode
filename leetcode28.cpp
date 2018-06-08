class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int h_len = haystack.length();
        int n_len = needle.length();
        for (int i = 0; i < h_len; i++) {
            if (haystack[i] != needle[0])
                continue;
            int j = 1;
            while (i + j < h_len && j < n_len && haystack[i + j] == needle[j])
                j++;
            if (j == n_len)
                return i;
        }
        return -1;
    }
};
