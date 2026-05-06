class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //--------------------BRUTE------FORCE----------------------------
    // set <vector<int>> set;
    
    // int n = nums.size();
    // for(int i = 0;i<n;i++){
    //     unordered_map <int,int> mpp;
    //     for(int j = i+1; j<n;j++){
    //         int remaining = -(nums[i]+nums[j]);
    //         if(mpp.find(remaining) != mpp.end()){
    //             mpp[remaining]--;
    //             if(mpp[remaining] == 0){
    //                 mpp.erase(remaining);
    //             }
    //             vector<int> temp = {nums[i], nums[j], remaining};
    //             sort(temp.begin(), temp.end());
    //             set.insert(temp);
    //         }else{
    //             mpp[nums[j]]++;
    //         }

    //     }
    // }
    // // vector<vector<int>> ans;
    // // for(auto it : set){
    // //    ans.push_back(it);
    // // }
    // vector<vector<int>> ans(set.begin(), set.end());
    // return ans;
    int n = nums.size();
    vector<vector<int>> ans ;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        if(i != 0 && nums[i] == nums[i-1]) continue;
        int left = i+1;
        int right = n-1;
        while(left < right){
        int sum = nums[i] + nums[left] + nums[right];
        if(sum == 0){
            ans.push_back({nums[i],nums[left],nums[right]});
            
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
        }
        else if (sum < 0){
            left++;
        }else{
            right--;
        }
        }
    }
    return ans;
    
        
    }
};