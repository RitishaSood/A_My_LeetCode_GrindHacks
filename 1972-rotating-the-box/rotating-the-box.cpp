class Solution {
public:
void applyGravity(vector<char>& row) {
    int n = row.size();
    // This pointer tracks where the next stone '#' should land
    int lowest_available = n - 1; 

    for (int i = n - 1; i >= 0; i--) {
        if (row[i] == '#') {
            // Found a stone: swap it with the lowest available empty spot
            swap(row[i], row[lowest_available]);
            lowest_available--;
        } 
        else if (row[i] == '*') {
            // Found an obstacle: stones cannot pass this, 
            // so the next available spot must be above it.
            lowest_available = i - 1;
        }
        // If row[i] == '.', we do nothing; lowest_available stays where it is
        // until a stone is found to fill it.
    }
}
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> rotated(m,vector<char> (n));
        for(auto &it : boxGrid){
            applyGravity(it);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
             rotated[j][i] = boxGrid[i][j];
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n/2;j++){
                swap(rotated[i][j],rotated[i][n-j-1]);
            }
        }
        return rotated;
        
    }
};