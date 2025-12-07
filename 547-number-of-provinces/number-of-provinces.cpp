class Solution {
public:
   void bfs(queue<int> &q,vector<int> &vis ,int node,vector<vector<int>> &adj ){
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
    int Curnode=q.front();
    q.pop();
    for(auto it:adj[Curnode]){
        if(vis[it]!=1){
            q.push(it);
            vis[it]=1;
        }
    }
    
    }

   }

    int findCircleNum(vector<vector<int>>& isConnected) {
     // Converting the Adj Matrix to Adj List
     int V= isConnected.size();
    vector<vector<int>> adj(V);
    for(int i = 0 ;i<V;i++){
        for(int j = 0;j<V;j++){
            if(isConnected[i][j]==1&& i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        }
    vector<int> vis(V,0);
    queue<int> q;
    int count=0;

    for(int i = 0 ; i<V;i++){
        if(vis[i]==0){
            bfs(q,vis,i,adj);
            count++;
        }

    }
     return count;
    
    }
};
