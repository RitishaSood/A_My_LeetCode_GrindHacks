class Solution {
public:
    bool bfs(int node, int col, vector<int> &vis, vector<vector<int>> &graph){
        queue<int> q;
        q.push(node);
        vis[node]= col;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int node = out;
        
            // int col = out.second;
            for(auto &it : graph[node]){
                if(vis[it] == -1){
                    vis[it] = !vis[node];
                    q.push(it);
                }else if(vis[it] == vis[node]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!bfs(i,0,vis,graph)){
                    return false;
                }
            }
        }
        return true;
        
    }
};