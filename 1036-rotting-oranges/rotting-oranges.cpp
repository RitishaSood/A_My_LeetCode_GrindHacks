class Solution {
public:
    bool isValid(int r, int c, int n , int m){
        if(r < n && r>=0 && c <m && c>=0){
            return true;
        }
        return false;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int totalOranges = 0;
        int count_Rotten_after_conversion =0;
        // bfs
        int steps = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q; // orange , steps
        
        for(int i =0; i<n;i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==2){
                    totalOranges++;
                    q.push({{i,j},steps});
                    vis[i][j]=1;

                }else if(grid[i][j]==1){
                    totalOranges++;
                }

            }
        }
        
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            count_Rotten_after_conversion++;
            int row = out.first.first;
            int col = out.first.second;
            steps = out.second;
            int rowadder[]={0,1,-1,0};
            int coladder[]={1,0,0,-1};
            for(int i =0; i<4;i++){
                int nr = row+rowadder[i];
                int nc = col +coladder[i];
                if(isValid(nr,nc,n,m) && grid[nr][nc]==1 && vis[nr][nc] ==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        if(count_Rotten_after_conversion != totalOranges) {
            return -1;
        }
        return steps;
        
    }
};