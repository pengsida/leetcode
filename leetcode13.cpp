class Solution {
private:
    unordered_map<char, int> rec;
    
public:
    Solution() {
        rec['I'] = 1;
        rec['V'] = 5;
        rec['X'] = 10;
        rec['L'] = 50;
        rec['C'] = 100;
        rec['D'] = 500;
        rec['M'] = 1000;
    }
    
public:
    int romanToInt(string s) {
        int s_len = s.length();
        int ans = 0;
        for (int i = 0; i < s_len;) {
            int cur = rec[s[i]];
            if (i + 1 == s_len)
                return ans + cur;
            int next = rec[s[i + 1]];
            if (cur < next) {
                ans = ans + (next - cur);
                i = i + 2;
            } else {
                ans = ans + cur;
                i++;
            }
        }
        return ans;
    }
};
