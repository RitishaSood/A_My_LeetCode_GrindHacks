class Solution {
private:
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int node, vector<int> &ans, stack<int>&st, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto adjnode : adj[node]){
            if(vis[adjnode] == 0){
                if(!dfs(adj, vis, adjnode, ans,st,pathVis)){
                    return false;
                }
            }else if(pathVis[adjnode]==1){
                return false;
            }
        }
        st.push(node);
        pathVis[node] = 0;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // using dfs to find topo sort
        vector<int> vis(numCourses,0);
        vector<int> ans;
        // make adj lis
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> pathVis(numCourses,0);
        for(int i =0; i<numCourses; i++){
            if(vis[i]==0){
                if(!dfs(adj,vis,i,ans,st,pathVis)){
                    return { };
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

    }
};