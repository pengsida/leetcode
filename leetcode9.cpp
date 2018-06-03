class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        if (x < 0 || x % 10 == 0)
            return false;
        int tmp = x;
        int ans = 0;
        while (tmp != 0) {
            ans = ans * 10 + (tmp % 10);
            tmp = tmp / 10;
        }
        return (x == ans);
    }
};
