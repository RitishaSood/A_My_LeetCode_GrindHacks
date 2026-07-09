class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        
        vector<set<int>> ancestorSets(n);
        
        while(!q.empty()) {
            auto out = q.front();
            q.pop();
            
            for(auto &it : adj[out]) {
                
                ancestorSets[it].insert(out);
                

                ancestorSets[it].insert(ancestorSets[out].begin(), ancestorSets[out].end());
                
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestorSets[i].begin(), ancestorSets[i].end());
        }
        
        return ans;
    }
};