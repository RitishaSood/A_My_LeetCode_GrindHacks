class Solution {
public:


void dfs(vector<int> &vis ,int node,vector<vector<int>>& isConnected,int V ){
   
   vis[node]=1;
   for(int j = 0 ; j < V ; j++ ){
    if(isConnected[node][j]==1 && vis[j]==0){
        dfs(vis,j,isConnected,V);
    }
   }

   }

    int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<int> vis(V,0);
    
    int count=0;

    for(int i = 0 ; i<V;i++){
        if(vis[i]==0){
            dfs(vis,i,isConnected,V);
            count++;
        }
    }
    return count;
    }
};
