class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if (r < 0 || r >= grid2.size() || c < 0 || c >= grid2[0].size() || grid2[r][c] == 0) {
            return true;
        }
        grid2[r][c] = 0;
        bool currentValid = (grid1[r][c] == 1);
        bool down = dfs(grid1, grid2, r + 1, c);
        bool up = dfs(grid1, grid2, r - 1, c);
        bool right = dfs(grid1, grid2, r, c + 1);
        bool left = dfs(grid1, grid2, r, c - 1);
        return currentValid && down && up && right && left;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int subIslandCount = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};