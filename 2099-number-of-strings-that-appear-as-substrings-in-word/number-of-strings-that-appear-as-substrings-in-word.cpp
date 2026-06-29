class Solution {
public: 
    bool isSubstring(string word, string pattern) {
    int n = word.length();
    int m = pattern.length();
    
    if (m > n) return false;

    // Loop through every possible starting position in 'word'
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        
        // Check if the pattern matches starting from index i
        while (j < m && word[i + j] == pattern[j]) {
            j++;
        }
        
        // If we matched the entire pattern, we found a substring!
        if (j == m) return true;
    }
    
    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto &it : patterns){
            if(isSubstring(word,it)){
                cnt++;
            }

        }
        return cnt;
        
    }
};