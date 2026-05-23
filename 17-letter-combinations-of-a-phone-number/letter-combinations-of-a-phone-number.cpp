class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",    "",    "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        backtrack(0, digits, mapping, current, result);
        return result;
    }

    void backtrack(int index, const string& digits, const vector<string>& mapping,
                   string& current, vector<string>& result) {

        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const string& letters = mapping[digit];

        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, mapping, current, result);
            current.pop_back();
        }
    }
};