class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> hash(101,0);
        for(auto &it: logs){
           hash[it[0]-1950]++;
           hash[it[1]-1950]--;
        } 

        // prefix sum and max ele 
        int ans = 0;
        int mx = hash[0];
        for(int i = 1 ; i<101;i++){
            hash[i]+=hash[i-1];
            if(hash[i]>mx){
                mx = hash[i];
                ans =i;
            }
        }
        return ans +1950;
        
    }
};