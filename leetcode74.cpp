class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        if (matrix[0].empty())
            return false;
        int num_row = matrix.size();
        int num_col = matrix[0].size();
        
        int up = 0;
        int down = num_row - 1;
        while (up <= down) {
            int mid = (up + down) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                up = mid + 1;
            else
                down = mid - 1;
        }
        
        int cur;
        if (up >= num_row)
            cur = num_row - 1;
        else
            cur = (matrix[up][0] > target ? up - 1 : up);
        if (cur < 0)
            return false;

        int left = 0;
        int right = num_col - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[cur][mid] == target)
                return true;
            else if (matrix[cur][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
};
