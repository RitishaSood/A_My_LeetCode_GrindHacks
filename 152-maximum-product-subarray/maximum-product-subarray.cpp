class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //     //BRUTE FORCE , find all the subarrays and give their maxProduct !
    //     int maxprod = INT_MIN;
    //     for(int i = 0 ; i<nums.size() ; i++){
    //         int prod = 1;
    //         for(int j = i ; j<nums.size() ; j++){
    //         prod = prod*nums[j];
    //         maxprod = max(prod,maxprod);
    //         }
    //     }
    //     return maxprod;


    // if know if all positive then entire array is the maxprod
    //or if even number of negatives then the entire array
    // if odd no. of negatives then the exclude the minimum one 
    //what if , always the right prefic proguct of the left preficx product will give the max product
    int preffixprod = 1;
    int suffixprod = 1;
    int maxprod = INT_MIN;
    for(int i = 0 ; i<nums.size(); i++){
        if(preffixprod == 0) preffixprod = 1;
        if(suffixprod == 0) suffixprod = 1;
        preffixprod = preffixprod * nums[i];
        suffixprod = suffixprod * nums[nums.size()-1-i];
        maxprod = max(maxprod,preffixprod);
        maxprod = max(maxprod,suffixprod);
    }
    return maxprod;
    }
};