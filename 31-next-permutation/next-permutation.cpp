class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
         if(index==-1){
            reverse(nums.begin(),nums.end());
        }else{
        for(int i = n-1;i>=index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        
        int start = index +1;
        int end = n-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        }
    }
};