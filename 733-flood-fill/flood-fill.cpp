class Solution {
public:
    bool isValid (int r, int c, int n, int m){
        if(r <n && r>=0 && c <m && c >= 0){
            return true;
        }
        return false;
    } 
    void dfs(int r, int c,vector<vector<int>>& image, int colour, int old, vector<vector<int>> &vis){
        vis[r][c] = 1;
        image[r][c] = colour;
        int row[]={1,0,0,-1};
        int col[]={0,-1,1,0};
        for(int k=0; k<4;k++){
            int nr = r + row[k];
            int nc = c + col[k];
            if(isValid(nr,nc,image.size(),image[0].size()) && vis[nr][nc]!=1 && image[nr][nc] == old){
                dfs(nr,nc,image,colour,old,vis);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    dfs(sr,sc,image,color,image[sr][sc],vis);
    return image;
        
    }
};