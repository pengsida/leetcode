#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct comp {
        vector<int>& tmp;
        comp(vector<int>& a): tmp(a) {}

        bool operator()(int a, int b) {
            return tmp[a] < tmp[b];
        }
    };

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        vector<int> tmp(size, 0);
        for (int i = 0; i < size; i++)
            tmp[i] = i;
        sort(tmp.begin(), tmp.end(), comp(B));
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int left = 0;
        int right = 0;
        while (right < size) {
            while(right < size && A[right] <= B[left])
                right++;
            if (right >= size)
                return A;
            swap(A[left], A[right]);
            left++;
            right++;
        }
        for (int i = 0; i < size; i++)
            B[tmp[i]] = A[i];
        return B;
    }
};
