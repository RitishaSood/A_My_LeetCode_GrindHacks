class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); 
        int n = s.size();
        int maxLen = 0, left = 0;
        for (int right = 0; right < n; right++) {
            char c = s[right];

            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
