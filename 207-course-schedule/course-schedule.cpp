class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt_valid_courses = 0;
        vector<vector<int>> adj(numCourses);
        for(auto &it:prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }

        // calculate in degress;
        vector<int> indegree(numCourses,0);
        for(auto &it : adj){
            for(auto &adjnodes : it){
               indegree[adjnodes]++;
            }
        }
        queue<int> q;
        for(int i =0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);

            }
        }
        vector<int> vis(numCourses,0);
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            vis[out]=1;
            cnt_valid_courses ++;
            for(auto &it : adj[out]){
                if(vis[it]==0){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
                }
            }
        }
        return cnt_valid_courses == numCourses;
        
        
    }
};