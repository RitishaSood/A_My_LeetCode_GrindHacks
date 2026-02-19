#include <vector>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations = 0;
        
        long long prev = nums[n - 1];  // rightmost element
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= prev) {
                prev = nums[i];
            } else {
                // compute required parts
                long long parts = (nums[i] + prev - 1) / prev;  // ceil division
                operations += (parts - 1);
                
                // update prev to maximum allowed value
                prev = nums[i] / parts;
            }
        }
        
        return operations;
    }
};