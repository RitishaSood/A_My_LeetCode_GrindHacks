class Solution {
public:
    int count = 0;
    void solve(int row, int n,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {
        // If all queens are placed
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check if column and diagonals are free
            if (!col[c] && !diag1[row + c] && !diag2[row - c + n - 1]) {
                // Place queen
                col[c] = true;
                diag1[row + c] = true;
                diag2[row - c + n - 1] = true;
                // Move to next row
                solve(row + 1, n, col, diag1, diag2);
                // Backtrack (remove queen)
                col[c] = false;
                diag1[row + c] = false;
                diag2[row - c + n - 1] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // row + col
        vector<bool> diag2(2 * n - 1, false); // row - col
        solve(0, n, col, diag1, diag2);
        return count;
    }
};
