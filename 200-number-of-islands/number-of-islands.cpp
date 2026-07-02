class Solution{
public:
     bool isValid(int r,int c,int n,int m){
            if(r>=0 && r<n && c>= 0 && c<m){
                return true;
            }
            return false;

        }
    int numIslands(vector<vector<char>> &grid){
        // Lets Aplly bfs and traverse ;
        queue<pair<int,int>> q;
       
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> r = {1,0,-1,0};
        vector<int> c = {0,1,0,-1};
        int count=0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] != 1){
                    count++;
                   vis[i][j] = 1;
                   q.push({i,j});
                   while(!q.empty()){
                    auto [row,col] = q.front();
                    q.pop();
                    for(int k = 0; k<4;k++){
                        int nr = row + r[k];
                        int nc = col + c[k];
                        if(isValid(nr,nc,n,m) && grid[nr][nc] == '1' && vis[nr][nc] != 1){
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                   }
                }

            }
        }
        return count;
    }
};
