class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int, greater<int>> st; // keep distinct sums in descending order

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // size 0 rhombus (single cell)
                st.insert(grid[r][c]);

                for (int k = 1; ; k++) {

                    if (r - k < 0 || r + k >= m || c - k < 0 || c + k >= n)
                        break;

                    int sum = 0;

                    int i = r - k, j = c;

                    // top -> right
                    while (i < r && j < c + k) {
                        sum += grid[i][j];
                        i++; j++;
                    }

                    // right -> bottom
                    while (i < r + k && j > c) {
                        sum += grid[i][j];
                        i++; j--;
                    }

                    // bottom -> left
                    while (i > r && j > c - k) {
                        sum += grid[i][j];
                        i--; j--;
                    }

                    // left -> top
                    while (i > r - k && j < c) {
                        sum += grid[i][j];
                        i--; j++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (int x : st) {
            ans.push_back(x);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};