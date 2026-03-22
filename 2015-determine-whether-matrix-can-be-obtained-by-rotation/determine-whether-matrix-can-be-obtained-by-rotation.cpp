class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> &grid ){
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> temp(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                temp[j][n - i - 1] = grid[i][j]; 
            }
        }
        return temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < 4; i++){
            bool flag = true;

            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(mat[j][k] != target[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }

            if(flag) return true;

            mat = rotate(mat); 
        }
        return false;
    }
};