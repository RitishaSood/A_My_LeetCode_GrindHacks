class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> count(3, 0);  // counts for 'a', 'b', 'c'
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;

            // shrink window while valid
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += (n - right);  // all suffixes from right are valid
                count[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};
