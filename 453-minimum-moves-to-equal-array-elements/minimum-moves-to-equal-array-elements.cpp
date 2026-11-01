class Solution {
public:
    int find_min_el(vector<int> &nums){
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini = nums[i];
            }
        }
        return mini;
    }
    int minMoves(vector<int>& nums) {
        int mini = find_min_el(nums);
        int count =0;
        for(int i=0;i<nums.size();i++){
            count += (nums[i]-mini);
            
        }
        return count;
        
    }
};