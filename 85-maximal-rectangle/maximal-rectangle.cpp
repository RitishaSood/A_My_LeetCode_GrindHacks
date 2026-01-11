class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    // INTUITION 
    // Basically we first calculate the max rectangle in a row and then we calculate the combines in the current row of column
    // Quite simillar to builing an histogram and then checking for the emax area 
      if (matrix.empty() || matrix[0].empty())
            return 0;
    int row =matrix.size();
    int col = matrix[0].size();
    
    int maxArea = 0;
     
    vector<int> heights(col,0);
    for(int i = 0 ; i<row;i++){
        for(int j = 0;j<col;j++){
            if(matrix[i][j]=='1'){
                heights[j]+=1;
            }else{
                heights[j]=0;
            }
        }
       maxArea = max(maxArea,LargestAreaPossible(heights));
    }
    return maxArea;
    }
    private:
     int LargestAreaPossible(vector<int>& heights){
        heights.push_back(0);
        stack<int> st; //To store Indexes
        int Area=0; 
        for(int i = 0;i<heights.size();i++){
        while(!st.empty()&&heights[st.top()]>heights[i]){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            Area = max(Area,height*width);
        }
        st.push(i);
        }
        heights.pop_back(); 
        return Area;
     }
};