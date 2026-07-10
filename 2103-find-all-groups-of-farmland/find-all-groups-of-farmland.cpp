class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(land[i][j] == 1 && (i==0 || land[i-1][j] == 0)&&(j==0 || land[i][j-1] == 0)){
                    int r = i;
                    int c = j;
                    while( r < n && land[r][j] == 1){
                        r++;
                    }
                    while(c<m &&land[i][c] == 1){
                        c++;
                    }
                    ans.push_back({i,j,r-1,c-1});
                }
            }
        }
        return ans;
        
    }
};