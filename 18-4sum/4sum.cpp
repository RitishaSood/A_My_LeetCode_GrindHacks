class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicates for j
                long long target2 = (long long)target - nums[i] - nums[j]; // avoid overflow
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum2 = nums[left] + nums[right];
                    if (sum2 == target2) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        //skip duplicates for left
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        //skip duplicates for right
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } 
                    else if (sum2 < target2) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
