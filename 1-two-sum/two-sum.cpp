class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // Better using maps with Time Complexity O(NlogN) ;
      int n = nums.size();
      map <int , int> arrayElementWithIndex;
      //map always in the sorted order 
      for(int i = 0 ; i<n;i++){
        int currentElement = nums[i];
        int OtherPair = target - currentElement;
        if(arrayElementWithIndex.find(OtherPair) != arrayElementWithIndex.end()){
        return {arrayElementWithIndex[OtherPair],i};
        }else{
            arrayElementWithIndex[nums[i]]=i;
        }
      }
      return {-1,-1};
      
    }
};