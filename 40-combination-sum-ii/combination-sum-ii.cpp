#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& c, int target, int start) {
        if(target == 0) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < c.size(); i++) {
            if(i > start && c[i] == c[i-1]) continue;
            if(c[i] > target) break;
            path.push_back(c[i]);
            dfs(c, target - c[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};
