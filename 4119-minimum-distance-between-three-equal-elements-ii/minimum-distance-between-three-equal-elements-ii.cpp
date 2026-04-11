class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mpp;
        
        // Store indices max 3 per number
        for (int i = 0; i < nums.size(); i++) {
           mpp[nums[i]].push_back(i);
        }

        int mind = INT_MAX;

        // Calculate distance
        for (auto &it : mpp) {
            vector<int> &v = it.second;

                if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    int dis = 2 * (v[i + 2] - v[i]);
                    mind = min(mind, dis);
                }
        }

       
    }
     return (mind == INT_MAX) ? -1 : mind;
    }
};