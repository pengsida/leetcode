class Solution {
private:
    unordered_map<char, char> rec;
    
public:
    Solution() {
        rec['('] = ' ';
        rec['['] = ' ';
        rec['{'] = ' ';
        rec['}'] = '{';
        rec[']'] = '[';
        rec[')'] = '(';
    }
    
    bool isValid(string s) {
        stack<char> ans;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            auto w = s[i];
            auto r = rec[w];
            if (r == ' ') {
                ans.push(w);
                continue;
            }
            if (ans.empty())
                return false;
            if (ans.top() != r)
                return false;
            else
                ans.pop();
        }
        return ans.empty();
    }
};
