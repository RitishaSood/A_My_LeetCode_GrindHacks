#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, cur = 1;

        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) m[top][i] = cur++;
            top++;
            for(int i = top; i <= bottom; i++) m[i][right] = cur++;
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--) m[bottom][i] = cur++;
                bottom--;
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--) m[i][left] = cur++;
                left++;
            }
        }
        return m;
    }
};
