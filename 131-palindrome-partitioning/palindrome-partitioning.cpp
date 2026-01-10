class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(int start, string &s) {
        // If we've used the whole string
        if (start==s.size()) {
            result.push_back(path);
            return;
        }
        //Try all possible substrings
        for (int end=start; end<s.size();end++) {
            if (isPalindrome(s,start,end)) {
                // Choose
                path.push_back(s.substr(start, end - start + 1));
                //Explore
                backtrack(end + 1, s);
                //Unchoose (backtrack)
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return result;
    }
};
