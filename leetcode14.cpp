class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        int size = strs.size();
        int i = 0;
        while (1) {
            if (i == strs[0].length())
                return strs[0];
            auto w = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (i == strs[j].length())
                    return strs[j];
                if (w != strs[j][i])
                    return strs[j].substr(0, i);
            }
            i++;
        }
    }
};
