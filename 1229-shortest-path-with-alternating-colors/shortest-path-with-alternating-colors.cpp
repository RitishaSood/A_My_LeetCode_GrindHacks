class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // formation of adj list 
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &it : redEdges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back({v,0});
        }

        for(auto &it : blueEdges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back({v,1});
        }
        vector<vector<bool>> vis(n,vector(2,false));
        queue<pair<int,pair<int,int>>> q;
        for(auto &it : adjList[0]){
            int node = it.first;
            int col = it.second;
            q.push({1,{node,col}});
        }
        vector<int> ans(n,-1);
        ans[0]=0;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int step = out.first;
            int node = out.second.first;
            int col = out.second.second;
            vis[node][col] =1;
            if(ans[node]==-1){
            ans[node] = step;
            }
            for(auto &it : adjList[node]){
                if(vis[it.first][it.second] == 0){
                    if(it.second != col){
                        vis[it.first][it.second] =1;
                        q.push({step+1,{it.first,it.second}});
                    }
                }
            }

        }
        return ans;
        
    }
};