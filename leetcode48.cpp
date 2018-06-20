class Solution {
public:
    void rotate(int&a, int& b, int& c, int& d) {
        swap(a, b);
        swap(a, c);
        swap(a, d);
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int times = n / 2;
        for (int i = 0; i < times; i++) {
            for (int j = 0; j < n - i * 2 - 1; j++) {
                int row1 = i;
                int col1 = i + j;
                int row2 = col1;
                int col2 = n - i - 1;
                int row3 = col2;
                int col3 = n - i - 1 - j;
                int row4 = col3;
                int col4 = i;
                rotate(matrix[row1][col1], matrix[row2][col2], matrix[row3][col3], matrix[row4][col4]);
            }
        }
    }
};
