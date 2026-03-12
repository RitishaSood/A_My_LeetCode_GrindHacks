class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map <int, int> mpp;
        for(auto i: nums){
            mpp[i]++;
        }
        vector<int> value;
        for(auto &p : mpp ){
            value.push_back(p.first);
        }
        sort(value.begin(),value.end());
        for(int i = 0 ; i< value.size();i++){
            for(int j = i+1; j<value.size();j++){
                if( mpp[value[i]]!= mpp [value[j]]){
                    return {value[i],value[j]};
                }
            }
        }
        return{-1,-1};
        
        
    }
};