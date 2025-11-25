class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;  // One way to have sum 0 before starting

        int prefix = 0, result = 0;

        for (int x : nums) {
            prefix += x;

            if (count.find(prefix - goal) != count.end()) {
                result += count[prefix - goal];
            }

            count[prefix]++;
        }

        return result;
    }
};
