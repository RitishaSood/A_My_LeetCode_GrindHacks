class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make directed edges 
        // add to adj 
        // perform topo sort 
        // if(result is equal to np. of nodes), yes possible 
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            // adj[v].push_back(u);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }

        }
        int cnt =0;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            cnt++;
            for(auto &it:adj[out]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }
        return cnt == numCourses;
        
    }
};