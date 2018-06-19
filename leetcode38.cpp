class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string tmp = countAndSay(n - 1);
        int len = tmp.length();
        int count = 0;
        string ans;
        for (int i = 0; i < len; i++) {
            auto w = tmp[i];
            if (i + 1 == len || w != tmp[i + 1]) {
                ans.append(to_string(count + 1));
                ans.append(1, w);
                count = 0;
            } else
                count++;
        }
        return ans;
    }
};
