class Solution {
public:
    bool isValid(int r, int c, int n, int m){
        if(r<n && r>=0 && c<m && c>=0){
            return true;
        }
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int step = out.first;
            int row = out.second.first;
            int col = out.second.second;
            
            vector<int> r = {0,-1,1,0};
            vector<int> c = {1,0,0,-1};
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];
                if(isValid(nr,nc,n,m) && height[nr][nc] ==-1){
                    height[nr][nc] = step+1;
                    q.push({step+1,{nr,nc}});
                }
            }
        }
        return height;
        
    }
};