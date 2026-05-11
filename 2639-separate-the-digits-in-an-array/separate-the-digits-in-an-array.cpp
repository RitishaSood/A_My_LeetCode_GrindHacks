class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
      for (int i = 0;i<nums.size();i++){
        int num = nums[i];
        stack<int> st;
        while(num){
            int digit = num %10;
            num = num/10;
            st.push(digit);
        }
        while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
        }

      }
      return ans;  
    }
};