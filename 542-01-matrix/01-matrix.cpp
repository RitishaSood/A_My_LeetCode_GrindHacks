class Solution {
public:
    bool isValid(int r, int c, int n , int m){
        if(r < n && r>=0 && c <m && c>=0){
            return true;
        }
        return false;

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // we put all the zero in the queue
        // as we move out and encounter 1 we mark it visited make it 1 step and move on
        // we are using the bfs traversal for nearest distance
        int n = mat.size(); 
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue <pair<pair<int,int>,int>> q;
        for(int i =0; i<n; i++){
            for(int j =0;j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int row[] = {0,0,1,-1};
        int col[] = {1,-1,0,0};
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int noderow = out.first.first;
            int nodecol = out.first.second;
            int nodedis = out.second;
            ans[noderow][nodecol] = nodedis;
            for(int i =0; i<4;i++){
                int nr = noderow + row[i];
                int nc = nodecol + col[i];
                if(isValid(nr,nc,n,m) && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},nodedis+1});
                }
            }
        }
        return ans;
        
    }
};