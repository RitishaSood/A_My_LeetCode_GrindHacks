class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // adjust for 1-based indexing
            int rem = columnNumber % 26;
            char ch = 'A' + rem;
            result = ch + result;  // prepend character
            columnNumber /= 26;
        }
        return result;
    }
};
