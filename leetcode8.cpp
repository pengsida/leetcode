class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int len = str.length();
        int i = 0;
        while (i < len && str[i] == ' ')
            i++;
        if (i == len)
            return 0;
        bool neg = false;
        if (!(str[i] >= '0' && str[i] <= '9')) {
            if (str[i] != '-' && str[i] != '+')
                return 0;
            neg = (str[i] == '-');
            i++;
        }
        int ans = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            int tmp = ans * 10 + (str[i] - '0');
            if (tmp / 10 != ans)
                return neg ? INT_MIN : INT_MAX;
            ans = tmp;
            i++;
        }
        return neg ? -ans : ans;
    }
};
