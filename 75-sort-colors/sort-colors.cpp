class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
    int n = nums.size();
    if(n==1)return;
    int i = 0;
    int j = n-1;
    int k = 0;
     while(i<=j){
        if(nums[i]==0){
                swap(nums[i],nums[k]);
                k++;
                i++;
        } 
        else if(nums[i]==1){
            i++;
        }
        else{
            swap(nums[i],nums[j]);
            j--;
        }
     }   
    }
};