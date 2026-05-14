class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int max_val = n - 1; 
        vector<int> hash(n, 0); 
        for(auto it : nums) {
            if (it >= n || it < 1) return false; 
            hash[it]++;
        }

        for(int i = 1; i <= max_val; i++) {
            if (i < max_val) {
                if (hash[i] != 1) return false;
            } else {
                if (hash[i] != 2) return false;
            }
        }
        return true;
    }
};