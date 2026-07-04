class Solution {

public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        // memoization 
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<vector<int>> t(n+1,vector<int>(target+1,0));
        // for(int i = 0; i < n+1; i++){
        //     for(int j = 0; j<target+1; j++){
        //         if(i==0){
        //             t[i][j]=0;
                    
        //         }
        //         if(j==0 && i==0){
        //             t[i][j]=1;
                    
        //         }
        //     }
        // }
        t[0][0]=1;
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j<target+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] =  (t[i-1][j-arr[i-1]] + t[i-1][j])%MOD;
                    
                }else{
                    t[i][j] = t[i-1][j]%MOD;
                    
                }
            }
        }
        return t[n][target];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {

    int sum = 0;
    for (int x : nums)
        sum += x;

    if (abs(target) > sum)
        return 0;

    if ((sum + target) % 2)
        return 0;

    int required = (sum + target) / 2;

    return perfectSum(nums, required);
}
};