#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& weights, int cap, int days) {
        int day = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > cap) {
                day += 1;
                sum = 0;
            }
            sum += weights[i];
        }
        return day;
    }

    int sum(vector<int>& weights) {
        int total = 0;
        for (int i = 0; i < weights.size(); i++) {
            total += weights[i];
        }
        return total;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int m = sum(weights);

        int low = *max_element(weights.begin(), weights.end());  // ✅ better lower bound
        int high = m;                                             // ✅ tighter upper bound
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (f(weights, mid, days) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
