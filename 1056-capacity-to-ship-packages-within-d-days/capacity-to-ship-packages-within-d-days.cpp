#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: calculates the number of days needed 
    // if the ship capacity is 'cap'
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

    // Helper function: returns total sum of weights
    int sum(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        return sum;
    }

    // Main function: binary search for minimum capacity
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        

        int low = *max_element(weights.begin(), weights.end());  // at least heaviest package
        int high = 5e4*500 ;                                            // at most total weight
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (f(weights, mid, days) <= days) {
                ans = mid;      // possible answer, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;  // need bigger capacity
            }
        }
        return ans;
    }
};
