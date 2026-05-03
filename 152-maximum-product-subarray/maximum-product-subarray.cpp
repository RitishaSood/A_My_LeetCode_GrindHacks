class Solution {
public:
    int maxProduct(vector<int>& nums) {
// //-----------------------BRUTE-------FORCE-----------------------------------------------------------------
//           int maxprod = INT_MIN;
//           int n = nums.size();
//           for(int i = 0;i<n;i++){
//             int prod = 1;
//             for(int j = i;j<n;j++){ 
//                 prod*=nums[j];
//                 // if(prod == 0) {
//                 // maxprod = max(prod,maxprod);
//                 // continue;
//                 // }
//                 maxprod = max(prod,maxprod);
//             }
            
//           }




// -----------------------OPTIMAL-----SOLUTION--------------------------------------------------------------
        int maxprod = INT_MIN;
        int suffprod = 1;
        int preprod = 1;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(suffprod == 0) suffprod = 1;
            if(preprod == 0) preprod = 1;
            suffprod *= nums[n-1-i];
            preprod *= nums[i];
            maxprod = max(maxprod,suffprod);
            maxprod = max(maxprod,preprod);
        }
        return maxprod;
    }
};