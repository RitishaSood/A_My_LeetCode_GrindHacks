class Solution {
public:
    bool bfs (int V,vector<vector<int>> &adj,vector<int> &vis,int node,vector<int> &col){
        queue <pair<int,int>> q;
        col[node]=1;
        q.push({node,1});
        vis[node]=1;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int ParentNode = out.first;
            int ParentColor = out.second;
            
            for(auto it : adj[ParentNode]){
                if(vis[it]!=1){
                    q.push({it,!ParentColor});
                    vis[it]=1;
                    col[it]=!ParentColor;
                }else if(ParentColor == col[it] ){
                    return false;
                }
            }
        }
        return true;
    }
bool isBipartite(vector<vector<int>> &graph) {
      int V = graph.size();
      vector<int> vis(V,0);
        vector<int> col(V,0);
        
      for(int i = 0 ; i<V;i++){
        if(vis[i]!=1){
           if(!bfs(V,graph,vis,i,col)){
            return false;
           }
        }
      }  
      return true;
    }
};
