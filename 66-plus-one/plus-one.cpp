class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit and handle the carry
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;  // digit was 9, becomes 0
        }

        // If we're here, the number was all 9's (e.g. 999 → 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
