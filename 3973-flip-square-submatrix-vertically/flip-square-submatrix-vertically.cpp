class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    vector<vector<int>> newgrid = grid;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = x ; i <= x+k-1;i++){
        for(int j = y ; j < y+k ; j++){
         newgrid[i][j] = grid[x+k-1-(i-x)][j];
        }
    }
    return newgrid;
    }
};