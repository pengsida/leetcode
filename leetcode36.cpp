class Solution {
public:
    bool valid(unordered_set<char>& tmp, char w) {
        if (w == '.')
            return true;
        return tmp.insert(w).second;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> tmp;
            for (int j = 0; j < 9; j++) {
                auto w = board[i][j];
                if (!valid(tmp, w))
                    return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            unordered_set<char> tmp;
            for (int i = 0; i < 9; i++) {
                auto w = board[i][j];
                if (!valid(tmp, w))
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> tmp;
            int orow = 3 * (i / 3);
            int ocol = 3 * (i % 3);
            for (int j = 0; j < 9; j++) {
                int r = orow + (j / 3);
                int c = ocol + (j % 3);
                auto w = board[r][c];
                if (!valid(tmp, w))
                    return false;
            }
        }
        return true;
    }
};
