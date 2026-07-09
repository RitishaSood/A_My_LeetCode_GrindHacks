class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n) ;
        vector<int> indegree(n, 0);
        iota(ans.begin(),ans.end(),0);
        // vector<int> indegree;
        for(auto &it: richer){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        } 
        queue<int> q; 
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        } 
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            for(auto &it : adj[out]){
                if(quiet[ans[it]] > quiet[ans[out]]){
                    ans[it] = ans[out];
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;    
    }
};