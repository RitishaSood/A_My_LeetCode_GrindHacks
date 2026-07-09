class Solution {
public:
    bool isValid(int r, int c, int n, int m){
        if(r >=0 && r<n && c>=0 && c<m){
            return true;
        }
        return false;
    } 
    bool dfs(int r, int c, int pr, int pc, char ch, vector<vector<int>>&vis, vector<vector<char>> &grid ){
        vis[r][c] =1;
        vector<int> rowarr = {0,-1,0,1};
        vector<int> colarr = {-1,0,1,0};
        for(int i=0; i<4; i++){
            int nr = r + rowarr[i];
            int nc = c + colarr[i];
            if(isValid(nr,nc,grid.size(),grid[0].size()) && vis[nr][nc] != 1 && grid[nr][nc] == ch){
                if(dfs(nr,nc,r,c,ch,vis,grid)){
                    return true;
                }

            }else if(isValid(nr,nc,grid.size(),grid[0].size()) && vis[nr][nc] == 1 && grid[nr][nc] == ch && nr != pr 
            && nc != pc){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == 0){
                    if(dfs(i,j,-1,-1,grid[i][j],vis,grid)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};