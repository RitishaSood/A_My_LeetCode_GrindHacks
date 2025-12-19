class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;   // use long long to handle INT_MIN
        double result = 1.0;
        // If power is negative, invert x
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        while (power > 0) {
            // If power is odd, multiply result
            if (power % 2 == 1) {
                result *= x;
            }
            // Square the base
            x *= x;
            power /= 2;
        }
        return result;
    }
};
