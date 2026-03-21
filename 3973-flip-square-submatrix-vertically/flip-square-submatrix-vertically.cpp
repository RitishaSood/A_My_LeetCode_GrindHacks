class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    vector<vector<int>> newgrid = grid;
    int n = grid.size();
    int m = grid[0].size();
    // for(int i = x ; i <= x+k-1;i++){
    //     for(int j = y ; j < y+k ; j++){
    //      newgrid[i][j] = grid[x+k-1-(i-x)][j];
    //     }
    // }
    for(int i = 0; i<k/2;i++){
        for(int j = 0 ; j<k;j++){
            swap(grid[x+i][y+j],grid[x+k-1-i][j+y]);

        }
    }
    return grid;
    }
};