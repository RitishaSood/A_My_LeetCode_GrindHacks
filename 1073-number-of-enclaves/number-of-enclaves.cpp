class Solution {
public:
        bool isValid(int i , int j , int m , int n){
        if((i>=0&&i<m)&&(j>=0&&j<n)){
            return true;
        }else{
            return false;
        }
    }
    void dfs(vector<vector<int>> &grid, int i, int j,vector<vector<int>> &vis) {
    if(isValid(i,j,grid.size(),grid[0].size()) && grid[i][j]==1){
    vis[i][j]=2;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int k = 0 ; k<4;k++){
        int nrow = i + delrow[k];
        int ncol = j + delcol[k];
        if(isValid(nrow,ncol,grid.size(),grid[0].size())&&vis[nrow][ncol]!=2){
            dfs(grid,nrow,ncol,vis);
        }
    }}
    }

    int numEnclaves(vector<vector<int>>& grid) {
            int m = grid.size();//rows
        int n = grid[0].size();//cols
        vector<vector<int>> vis(m,(vector<int>(n,0)));

        for (int j = 0; j < n; j++) {
          dfs(grid, 0, j, vis);
           dfs(grid, m-1, j, vis);
           }


        for (int i = 0; i < m; i++) {
           dfs(grid, i, 0, vis);
           dfs(grid, i, n-1, vis);
          }
      int count=0;
      for(int i = 1;i<m-1;i++){
        for(int j = 1;j<n-1;j++){
            if(grid[i][j]==1&&vis[i][j]!=2){
                count++;
            }
        }}
        return count;
      }
};
