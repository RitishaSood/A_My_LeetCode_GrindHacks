class Solution {
public:
    void dfs(int node,  vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &mini){ 
        vis[node] = 1;
        for(auto &it:adj[node]){
            int adjnode = it.first;
            int adjwt = it.second;
            mini = min(mini, adjwt);
            if(vis[adjnode]==0){
                dfs(adjnode, adj, vis, mini);
            }


        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        // normal traversal may work 
        // int n = roads.size();
        // making of an adjList
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : roads){
            int u = it[0];
            int v= it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> vis(n+1,0);
        int mini = INT_MAX;
        dfs(1,adj,vis,mini);
        return mini;
        
    }
};