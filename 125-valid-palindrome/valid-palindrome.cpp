class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>temp;
        for (int i = 0; i < s.size(); i++) {
            if (std::isalnum(s[i])) {
                temp.push_back(std::tolower(s[i]));
            }
        }
        std::vector<char>c = temp;
        std::reverse(temp.begin(), temp.end());

        return temp == c;
        
    }
};