class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // formation of an adj list to store the order to finish the courses 
    vector<vector<int>> adj(numCourses);
    for(int i = 0 ; i<prerequisites.size();i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b].push_back(a);
    }
    //calculation of an indegree
    vector<int> inDegree(numCourses,0);
    for (int i = 0 ; i<numCourses ; i++){
    for(auto it: adj[i]){
        inDegree[it]++;
    }
    }
    //pushing 0 indegree to the queue 
    queue <int> q;
    for(int i = 0;i<numCourses;i++){
        if (inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int out = q.front();
        q.pop();
        topo.push_back(out);
        for(auto it : adj[out]){
            inDegree[it]--;
            if(inDegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()==numCourses){
        return topo;
    }else{
        return {};
    }
    }
};
