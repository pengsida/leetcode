#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> rec;
        for (auto s : s1)
            rec[s]++;
        int left = 0;
        int right = 0;
        int size1 = s1.length();
        int size = s2.length();

        while (right < size) {
            auto w = s2[right];
            auto cur = rec.find(w);
            if (cur == rec.end()) {
                while (left < right)
                    rec.find(s2[left++])->second++;
                right++;
                left = right;
                continue;
            }
            if (cur->second == 0) {
                while (left < right) {
                    rec.find(s2[left++])->second++;
                    if (cur->second != 0)
                        break;
                }
                continue;
            }
            cur->second--;
            right++;
            if (right - left == size1)
                return true;
        }
        return false;
    }
};
