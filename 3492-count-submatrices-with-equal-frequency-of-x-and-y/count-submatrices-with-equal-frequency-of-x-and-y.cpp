class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> pref(rows, vector<int>(cols, 0));

        int count = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                pref[i][j] = val;

                if(i > 0) pref[i][j] += pref[i-1][j];
                if(j > 0) pref[i][j] += pref[i][j-1];
                if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];

                // check equal X and Y AND at least one X
                if(pref[i][j] == 0){
                    // ensure at least one X exists
                    // easiest way: check total cells not zero
                    // OR track separately
                    bool hasX = false;

                    for(int x = 0; x <= i && !hasX; x++){
                        for(int y = 0; y <= j; y++){
                            if(grid[x][y] == 'X'){
                                hasX = true;
                                break;
                            }
                        }
                    }

                    if(hasX) count++;
                }
            }
        }

        return count;
    }
};