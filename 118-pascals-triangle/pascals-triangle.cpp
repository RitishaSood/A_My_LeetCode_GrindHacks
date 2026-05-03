class Solution {
public:
    vector<int> generaterow(int row_no){
        int n = row_no - 1;
        int ans = 1;
        vector<int> temp;
        temp.push_back(ans);
        for(int i = 0;i<n;i++){
            ans *= n-i;
            ans /= i+1;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
        
    }
};