class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            vis[out]=1;
            for(auto &it : rooms[out]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }

        }
        for(auto it: vis){
            if(it==0){
              return false;
            }
        }
        return true;
        
    }
};