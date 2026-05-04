class Solution {
public:
    string convert(string s, int numRows) {

        // Edge case: if only one row, zigzag doesn't change the string
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector to store characters row-wise
        vector<string> rows(numRows);

        int currentRow = 0;      // Keeps track of current row
        bool goingDown = false;  // Direction flag

        // Traverse each character in the string
        for (char ch : s) {

            // Add character to the current row
            rows[currentRow].push_back(ch);

            // Change direction when we reach top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move up or down based on direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into one final string
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};