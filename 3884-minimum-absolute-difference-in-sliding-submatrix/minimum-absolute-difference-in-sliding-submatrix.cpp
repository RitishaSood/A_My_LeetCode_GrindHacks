class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    //step 1: calculate the resultant matrix size
    int rows = grid.size();
    int cols = grid[0].size();
    int r = rows-k+1;
    int c = cols-k+1;
    vector<vector<int>>ans(r,vector<int>(c));
    for(int i = 0;i<r;i++){
        for(int j = 0 ; j<c ;j++){
            vector<int> temp;
            for(int l = i ; l< i+k ; l++){
                for(int m = j ; m <j+k ;m++){
                temp.push_back(grid[l][m]);
                }
            }
            sort(temp.begin(),temp.end());
            
            int mini = INT_MAX;

            for(int x = 1; x < temp.size(); x++) {
                if(temp[x]==temp[x-1]) continue;
                mini = min(mini, abs(temp[x] - temp[x-1]));
                
            }
            if(mini == INT_MAX) mini = 0;
            ans[i][j] = mini;
        }
    }
    return ans;
        
    }
};