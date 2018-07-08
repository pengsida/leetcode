#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string _addBinary(string& a, string& b) {
        int m = a.length();
        int n = b.length();
        if (m < n)
            return _addBinary(b, a);
        int add = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[m - 1] == '1' && b[i] == '1') {
                a[m - 1] = '0' + add;
                add = 1;
            } else if (a[m - 1] == '0' && b[i] == '0') {
                a[m - 1] = '0' + add;
                add = 0;
            } else {
                if (add == 1)
                    a[m - 1] = '0';
                else
                    a[m - 1] = '1';
            }
            m--;
        }
        if (add == 0)
            return a;
        if (m < 0) {
            a.insert(a.begin(), '1');
            return a;
        }
        while (m >= 1) {
            if (a[m - 1] == '0') {
                a[m - 1] = '1';
                return a;
            }
            else
                a[m - 1] = '0';
            m--;
        }
        if (m == 0)
            a.insert(a.begin(), '1');
        return a;
    }

    string addBinary(string a, string b) {
        return _addBinary(a, b);
    }
};
