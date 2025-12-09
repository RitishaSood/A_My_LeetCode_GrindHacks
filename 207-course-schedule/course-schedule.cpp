class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //first form an adj list 
       vector< vector<int>> adj(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
            

        }
        vector<int> inDegree(numCourses,0);
        //calculation of the inDegree
        for(int i = 0 ; i<numCourses ; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        queue <int> q;
        for(int i = 0 ; i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> Topo;
        while(!q.empty()){
            int out = q.front();
            q.pop();
            Topo.push_back(out);
            for(auto it : adj[out]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(Topo.size()==numCourses){
            return true;
        }else{
            return false;
        }
    }
};
