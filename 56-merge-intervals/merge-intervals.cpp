class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        // Step 1: sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: iterate and merge
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (ans.empty() || ans.back()[1] < start) {
                // no overlap → add interval
                ans.push_back({start, end});
            } else {
                // overlap → merge
                ans.back()[1] = max(ans.back()[1], end);
            }
        }

        return ans;
    }
};