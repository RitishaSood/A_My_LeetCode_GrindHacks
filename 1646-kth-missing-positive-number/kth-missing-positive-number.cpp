#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int current = 1;
        int i = 0;
        int n = arr.size();

        // Loop until we find k missing numbers
        while (missingCount < k) {
            // If current number is missing from arr
            if (i >= n || arr[i] != current) {
                missingCount++;
                if (missingCount == k) {
                    return current;
                }
            } else {
                // Move to next number in array if matched
                i++;
            }
            current++;
        }
        return -1; // theoretically unreachable
    }
};
