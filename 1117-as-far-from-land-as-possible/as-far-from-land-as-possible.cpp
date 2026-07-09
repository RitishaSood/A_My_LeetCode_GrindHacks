class Solution {
public:
    bool isValid(int r, int c, int n){
        if(r>=0 && r<n && c>=0 && c<n){
            return true;
        }
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        // we will traverse through the grid 
        // for all the 1 we will make the vfs traversal as we find the first o we mark it visited and pit 
        // in queue we will store r,c,step
        // max step also globally 
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        if(q.empty() || q.size() == n * n) {
            return -1;
        }
        vector<int> r = {0,-1,0,1};
        vector<int> c = {1,0,-1,0};
        int maxi = 0;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int step = out.first;
            maxi = max(step,maxi);
            int row = out.second.first;
            int col = out.second.second;
            vis[row][col] =1;
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];
                if(isValid(nr,nc,n) && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({step+1,{nr,nc}});
                }
            }

        }
        if(maxi) return maxi;
        else return -1;
        
    }
};