#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int nextMonotone(int n) {
        string tmp = to_string(n);
        int size = tmp.length();
        int k = size - 1;
        for (int i = size - 1; i >= 1; i--) {
            if (tmp[i] < tmp[i - 1]) {
                tmp[i - 1] = tmp[i - 1] - 1;
                while (k >= i)
                    tmp[k--] = '9';
            }
        }
        return stoi(tmp);
    }

    int monotoneIncreasingDigits(int N) {
        return nextMonotone(N);
    }
};
