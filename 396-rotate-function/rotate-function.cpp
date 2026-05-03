class Solution {
public:
// -------------------------- BRUTE FORCE --------------------------------------------------------
    // vector<int> rotate(int n, vector<int> &nums,vector<int> temp){
    //     reverse(temp.begin(),temp.end());
    //     reverse(temp.begin(),temp.begin()+n);
    //     reverse(temp.begin()+n,temp.end());
    //     return temp;
    // }
    // int maxRotateFunction(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxprod = INT_MIN;
    //     vector<int> empty;
    //     for(int i = 0; i < n; i++){
    //         empty.erase();
    //         vector<int> temp = rotate(i, nums,empty);

    //         int prod = 0;
    //         for(int j = 0; j < n; j++){
    //             prod += j * temp[j];
    //         }

    //         maxprod = max(maxprod, prod);
    //     }

    //     return maxprod;
       
    // }

//-------------------------------------USING DP---------------------------------------
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        long long sum=0,f=0;
        for(int i = 0;i<n;i++){
            sum += 1LL*nums[i];
            f += 1LL*i*nums[i];
        }
        long long maxprod = f;
        for(int k=1;k<n;k++){
            f = f + sum - (1LL*n*nums[n-k]) ;
            maxprod = max(f,maxprod);
        }
        return maxprod;

       
    }
};