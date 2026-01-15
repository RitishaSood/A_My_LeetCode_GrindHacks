#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i = idx; i < nums.size(); i++) {
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};
