class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x != 0) {
            int tmp = ans * 10 + x % 10;
            if (tmp / 10 != ans)
                return 0;
            ans = tmp;
            x = x / 10;
        }
        return ans;
    }
};
