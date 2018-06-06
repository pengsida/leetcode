class Solution {
private:
    vector<string> rec = vector<string>(10);
    string word;
    vector<string> ans;
    
public:
    Solution() {
        rec[2] = "abc";
        rec[3] = "def";
        rec[4] = "ghi";
        rec[5] = "jkl";
        rec[6] = "mno";
        rec[7] = "pqrs";
        rec[8] = "tuv";
        rec[9] = "wxyz";
    }
    
    void _combination(string& digits, int pos) {
        if (pos < 0) {
            ans.push_back(word);
            return;
        }
        auto& letters = rec[digits[pos] - '0'];
        for (auto letter : letters) {
            word[pos] = letter;
            _combination(digits, pos - 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ans;
        int size = digits.length();
        word = string(size, ' ');
        _combination(digits, size - 1);
        return ans;
    }
};
