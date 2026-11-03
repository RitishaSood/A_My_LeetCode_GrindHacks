class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(auto it:nums){
            maxi = max(maxi,it);
        }
        int count =0;
        for(auto&it:nums){
        count+=maxi-it;
        }
        return count;
        
    }
};