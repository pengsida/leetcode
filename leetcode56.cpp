#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

using namespace std;

class Solution {
private:
    struct comp {
        bool operator()(Interval& a, Interval& b) const {
            return a.start < b.start;
        }
    };

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        int i = 0;
        int size = intervals.size();
        while (i + 1 < size) {
            auto& a = intervals[i];
            auto& b = intervals[i + 1];
            if (a.end >= b.start) {
                a.end = (a.end > b.end ? a.end : b.end);
                intervals.erase(intervals.begin() + i + 1);
                size--;
            } else
                i++;
        }
        return intervals;
    }
};
