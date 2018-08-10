#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m + n);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                tmp[k++] = nums1[i++];
            else
                tmp[k++] = nums2[j++];
        }
        while (i < m)
            tmp[k++] = nums1[i++];
        while (j < n)
            tmp[k++] = nums2[j++];
        k = 0;
        while (k < m + n) {
            nums1[k] = tmp[k];
            k++;
        }
    }
};
