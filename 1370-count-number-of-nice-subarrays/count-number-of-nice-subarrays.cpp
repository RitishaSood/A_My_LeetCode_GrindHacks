class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // if i represent even as 0 and odd as 1 then # of subarrays with sum k is the the answer
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                v[i]=0;
            }else{
                v[i]=1;
            }
        } 
        map <int,int> mpp;
        mpp[0]=1;
        int curr_sum =0;
        int counter =0;
        for(int i=0;i<nums.size();i++){
            curr_sum += v[i];
            int req = curr_sum-k;
            if(mpp.find(req)!= mpp.end()){
                counter+=mpp[req];
            }
            mpp[curr_sum]++;
        }
        return counter;
    }
};