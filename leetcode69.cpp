#include <iostream>

using namespace std;

class Solution {
public:
    double sqrt(double target) {
        if (target == 0)
            return 0;
        double x0 = 1;
        while (1) {
            double fx = x0 * x0 - target;
            double _fx = 2 * x0;
            double tmp = fx / _fx;
            if (abs(tmp) < 5e-7)
                break;
            x0 = x0 - tmp;
        }
        return x0;
    }

    int mySqrt(int x) {
        return sqrt(x);
    }
};
