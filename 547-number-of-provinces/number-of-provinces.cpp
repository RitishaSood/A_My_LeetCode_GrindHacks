class Solution {
private: 
    void bfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            for(auto &it : adj[out]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        for(int i =0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(i==j)continue;
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        int count =0;
        vector<int> vis(v,0);
        for(int i = 0; i<v; i++){
            if(vis[i]==0){
                count++;
                bfs(adj,vis,i);
            }
        }
        return count;

        
    }
};