class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]] == 0)
                k--;  // found new distinct number
            freq[nums[right]]++;

            // shrink window if too many distinct
            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;  // one distinct removed
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }
};
