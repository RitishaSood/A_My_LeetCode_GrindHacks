class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, len = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--; 
                r++;
            }
            return r - l - 1;
        };

        for (int i = 0; i < n; i++) {
            int len1 = expand(i, i);
            int len2 = expand(i, i + 1);
            int cur = max(len1, len2);
            if (cur > len) {
                len = cur;
                start = i - (cur - 1) / 2;
            }
        }
        return s.substr(start, len);
    }
};
