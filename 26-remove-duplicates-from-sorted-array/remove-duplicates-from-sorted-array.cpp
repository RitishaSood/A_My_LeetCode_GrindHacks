class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       /* // BRUTE FORCE SOLUTION 
        int n = nums.size();
        set<int> st;
        for(int i = 0 ; i<n;i++){
            st.insert(nums[i]);
        }
        int index = 0;
        for(auto it : st){
            nums[index]=it;
            index++;
        }
        return st.size();*/
        //OPTIMAL SOLUTION 
        int j =0;
        int n = nums.size();
        for(int i =j+1 ; i< n; i++){
        if(nums[i]!=nums[j]){
            nums[j+1]= nums[i];
            j++;
        }
       
        }
         return j+1;
    }
};