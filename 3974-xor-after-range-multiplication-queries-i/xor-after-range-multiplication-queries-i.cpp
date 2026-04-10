class Solution {
public:
    const int MOD = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    for(int i = 0 ; i<queries.size() ; i++){
        vector<int> curr_query = queries[i];
        int inx = curr_query[0];
        int ri = curr_query[1];
        int ki = curr_query[2];
        int vi = curr_query[3];
        while(inx <= ri){
            nums[inx] = (( 1LL*nums[inx] * vi) % MOD)%MOD;
            inx += ki;
        }
    } 
    int ans = 0;
    for(int i = 0 ;i<nums.size();i++){
    ans = ans ^ nums[i];
    }
    return ans;
    }
};