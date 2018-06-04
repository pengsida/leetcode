class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int s1_len = s1.length();
        int s2_len = s2.length();
        int s3_len = s3.length();
        vector<vector<bool>> rec(s1_len + 1, vector<bool>(s2_len + 1, false));
        rec[0][0] = true;
        for (int i = 1; i < s1_len + 1; i++) {
            bool tmp = (s1[i - 1] == s3[i - 1]);
            if (!tmp)
                break;
            rec[i][0] = tmp;
        }
        for (int i = 1; i < s2_len + 1; i++) {
            bool tmp = (s2[i - 1] == s3[i - 1]);
            if (!tmp)
                break;
            rec[0][i] = tmp;
        }
        for (int i = 1; i < s1_len + 1; i++) {
            for (int j = 1; j < s2_len + 1; j++) {
                bool tmp = rec[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                tmp = tmp || (rec[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
                rec[i][j] = tmp;
            }
        }
        return rec[s1_len][s2_len];
    }
};
