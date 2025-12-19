class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;  // first element is always 1
        for (int i = 1; i <= rowIndex; i++) {
            // update from right to left
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};
