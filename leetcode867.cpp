#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int N) {
        int tmp = 0;
        int t = N;
        while (N != 0) {
            tmp = tmp * 10 + N % 10;
            N = N / 10;
        }
        return tmp == t;
    }

    bool isPrime(int N) {
        if (N == 1)
            return false;
        int tmp = sqrt(N);
        for (int i = 2; i <= tmp; i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }

    int nextPalindrome(int N) {
        string tmp = to_string(N);
        int len = tmp.length();
        int left = (len - 1) / 2;
        int right = left + 1;
        if (len % 2 != 0)
            right = left;
        while (left >= 0) {
            if (tmp[left] == '9' && tmp[right] == '9') {
                left--;
                right++;
            } else {
                tmp[left] = tmp[left] + 1;
                if (left != right)
                    tmp[right] = tmp[right] + 1;
                for (int i = left + 1; i < right; i++)
                    tmp[i] = '0';
                break;
            }
        }
        if (left == -1)
            return N + 2;
        else
            return stoi(tmp);
    }

    int primePalindrome(int N) {
        if (!isPalindrome(N)) {
            string tmp = to_string(N);
            int len = tmp.length();
            for (int i = 0; i < len / 2; i++)
                tmp[len - i - 1] = tmp[i];
            int t = stoi(tmp);
            while (t <= N)
                t = nextPalindrome(t);
            N = t;
        }
        while (!isPrime(N))
            N = nextPalindrome(N);
        return N;
    }
};
