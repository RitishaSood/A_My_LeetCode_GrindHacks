class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;      // prefix sum 0 occurs once initially

        int prefix = 0, result = 0;

        for (int x : nums) {
            prefix += (x % 2);   // convert odd → 1, even → 0

            if (count.find(prefix - k) != count.end()) {
                result += count[prefix - k];
            }

            count[prefix]++;
        }

        return result;
    }
};
