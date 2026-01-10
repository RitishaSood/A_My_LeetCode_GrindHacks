class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // Brute force O(n2)
      int n = nums.size();
      for(int i = 0;i<n;i++){
        int sum = nums[i];
        for(int j=i+1;j<n;j++ ){
            if((sum+=nums[j])==target){
                return {i,j};
            }else{
                sum-=nums[j];//remember to remove !!!!!
            }
        }
      } 
      return {-1,-1} ;
    }
};