class Solution {
private:
    void bfs( vector<vector<int>> &adj,int node, vector<int> &vis){
      queue <int> q;
      //vector<int > bfs;
      vis[node]=1;
      
      q.push(node);
      while(!q.empty()){
        int ONode = q.front();
        q.pop();
         
       // bfs.push_back(ONode);
        
        
        for(auto it : adj[ONode]){
            if(!vis[it]){
              vis[it]=1;
              q.push(it);

            }
        } 
      }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int V = isConnected.size();
        vector<vector<int>> adj(V);
        //Step 1 to convert the matrix into Adj list 
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0 ; j<isConnected[0].size();j++){
             if(isConnected[i][j]==1&&i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
             }
            }}
        //to chcek for province 
       
        vector<int> vis(V,0);
    int cnt = 0;
    for(int i =0 ; i<V;i++){
    if(vis[i]==0){
       int node = i;
       cnt ++;
       bfs(adj,node,vis);
       }
    }
    return cnt ;
        }
    
};