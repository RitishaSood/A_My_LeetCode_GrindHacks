class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        // 1993 1999
        //          2000 2010
        //     1       1
        //    1950     1961
        //         1960          1971
        //                   1970       1981
        //     1     2   1            1
        // vector array 
        // all years
        // birthyear add 1
        // death year sub 1
        int n = logs.size();
        int m = logs[0].size();
        // find the minimum births year
        int min_birth_year =logs[0][0];
        int max_death_year = logs[0][1];
        for(auto it:logs){
            if(it[0]<min_birth_year){
                min_birth_year = it[0];
            }
            if(it[1]>max_death_year){
                max_death_year = it[1];
            }
        } //O(N)
        int len = (max_death_year - min_birth_year)+1;
        vector<int> prefix(len,0);
        for(int i=0;i<n;i++){
            prefix[logs[i][0]-min_birth_year]+=1;
            prefix[logs[i][1]-min_birth_year]+=(-1);
        } // O(N)

        vector<int> prefix_sum((len),0);
        for(int i=1;i<len;i++){
            prefix_sum[i] = prefix_sum[i-1]+prefix[i];
        }//O(len)
        int max_ppl = 0;
        int ans = min_birth_year;
        for(int i=1;i<len ; i++){
             if(prefix_sum[i]>max_ppl){
                ans = min_birth_year + i;
                max_ppl = prefix_sum[i];
             }
        }//O(N)
        return ans;

        
    }
};