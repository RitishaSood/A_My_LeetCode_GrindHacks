class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> onlyInNums1;
        vector<int> onlyInNums2;
        // Find elements only in nums1
        for (int x : set1) {
            if (!set2.count(x)) {
                onlyInNums1.push_back(x);
            }
        }
        // Find elements only in nums2
        for (int x : set2) {
            if (!set1.count(x)) {
                onlyInNums2.push_back(x);
            }
        }
        return {onlyInNums1, onlyInNums2};
    }
};
