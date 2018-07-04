#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        int i = 0;
        for (; i < size; i++) {
            auto& a = intervals[i];
            if (newInterval.end < a.start)
                continue;
            if (newInterval.start > a.end)
                continue;
            a.start = (a.start < newInterval.start ? a.start : newInterval.start);
            a.end = (a.end > newInterval.end ? a.end : newInterval.end);
            break;
        }
        if (i == size) {
            for (i = 0; i < size; i++) {
                if (intervals[i].start < newInterval.start)
                    continue;
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            intervals.push_back(newInterval);
            return intervals;
        }
        while (i + 1 < size) {
            auto& a = intervals[i];
            auto& b = intervals[i + 1];
            if (a.end < b.start)
                break;
            a.end = (a.end > b.end ? a.end : b.end);
            intervals.erase(intervals.begin() + i + 1);
            size--;
        }
        return intervals;
    }
};
