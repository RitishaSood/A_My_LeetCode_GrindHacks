class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // hashing 
        vector<int> hash(101,0);
        for(auto &it : logs){
            int start = it[0];
            int end = it[1];
            for(int i=start; i<end;i++){
                hash[i-1950]++;
            }
        }
        int max_people =0;
        int max_people_year = 0;
        for(int i=0; i<101;i++){
            if(hash[i] > max_people){
                max_people=hash[i];
                max_people_year = i+1950;
            }
        }
        return max_people_year;
        
    }
};