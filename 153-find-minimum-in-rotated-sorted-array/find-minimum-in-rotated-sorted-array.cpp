class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MAX;
        if(n==1){
            return nums[l];
        }
        if(n==2){
            return min(nums[l],nums[r]);
        }
        while(l< r){
            int mid = ((l+r)/2+1);
            if(nums[mid]>nums[l]){
                ans = min(nums[l],ans);
                l = mid ;
            }else{
                ans = min(nums[mid],ans);
                r = mid-1;
            }
        }
        return ans;
    }
};