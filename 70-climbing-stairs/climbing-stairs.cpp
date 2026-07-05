class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int first = 1, second = 2;
        int temp;
        for (int i = 3; i <= n; ++i) {
             temp = first + second;
            first = second;
            second = temp;
        }
        return temp;
    }
};