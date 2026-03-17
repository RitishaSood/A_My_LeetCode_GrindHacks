class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: build heights
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        int ans = 0;
        // Step 2: process each row
        for(int i = 0; i < m; i++) {
            vector<int> temp = matrix[i];

            // sort in descending order
            sort(temp.begin(), temp.end(), greater<int>());

            // Step 3: calculate max area
            for(int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }
};