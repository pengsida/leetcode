class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty())
            return string("");
        int len = s.length();
        vector<string> rec(numRows, "");
        int row = 0;
        int delta = 1;
        for (int i = 0; i < len; i++) {
            rec[row].append(1, s[i]);
            if (numRows == 1)
                continue;
            if (row == 0)
                delta = 1;
            else if (row == numRows - 1)
                delta = -1;
            row += delta;
        }
        return accumulate(rec.begin(), rec.end(), string(""));
    }
};
