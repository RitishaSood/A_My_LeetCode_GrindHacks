class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> sum(rows, vector<int>(cols, 0));
        vector<vector<int>> countX(rows, vector<int>(cols, 0));

        int ans = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                sum[i][j] = val;
                countX[i][j] = (grid[i][j] == 'X');

                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j-1];
                    countX[i][j] += countX[i][j-1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }

                if(sum[i][j] == 0 && countX[i][j] > 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};