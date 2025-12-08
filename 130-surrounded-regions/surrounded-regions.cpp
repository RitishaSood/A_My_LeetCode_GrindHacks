class Solution {
public:
    bool isValid(int i , int j , int m , int n){
        if((i>=0&&i<m)&&(j>=0&&j<n)){
            return true;
        }else{
            return false;
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j,vector<vector<int>> &vis) {
    if(isValid(i,j,board.size(),board[0].size()) && board[i][j]=='O'){
    vis[i][j]=1;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int k = 0 ; k<4;k++){
        int nrow = i + delrow[k];
        int ncol = j + delcol[k];
        if(isValid(nrow,ncol,board.size(),board[0].size())&&vis[nrow][ncol]!=1){
            dfs(board,nrow,ncol,vis);
        }
    }}
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();//rows
        int n = board[0].size();//cols
        vector<vector<int>> vis(m,(vector<int>(n,0)));

for (int j = 0; j < n; j++) {
    dfs(board, 0, j, vis);
    dfs(board, m-1, j, vis);
}


for (int i = 0; i < m; i++) {
    dfs(board, i, 0, vis);
    dfs(board, i, n-1, vis);
}

       vector<vector<char>> ans;
       for(int i = 0 ; i<m;i++){
        for(int j = 0 ;j<n;j++){
            //if(board[i][j]=='X'){
             //   board[i][j]='X';
           // }
            if(vis[i][j]!=1){
                board[i][j]='X';
            }
            if(vis[i][j]==1){
                board[i][j]='O';
            }
        }
       }
       
    }
};
//Coding Mistake to Remember
//Take care to pass ,n-1,m-1 not n and m
//Take care of variables i,j,k
//for char use ''and not"""
//Always apply isValid Condition
