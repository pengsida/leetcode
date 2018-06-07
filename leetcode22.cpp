class Solution {
private:
    vector<string> ans;
    string word;
    
public:
    void _generate(int pos, int left, int right, int size, int n) {
        if (size == 0) {
            ans.push_back(word);
            return;
        }
        if (left < n) {
            word[pos] = '(';
            _generate(pos + 1, left + 1, right, size - 1, n);
        }
        if (right < left) {
            word[pos] = ')';
            _generate(pos + 1, left, right + 1, size - 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int size = n * 2;
        word = string(size, ' ');
        _generate(0, 0, 0, size, n);
        return ans;
    }
};
