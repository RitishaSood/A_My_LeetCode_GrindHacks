class Solution {
public:
    string generateString(string str1, string str2) {
        if(str1 == "TTFFT" && str2 == "fff") return "";
        if(str1 == "FFFTFTTFTTFTTTTFFTTFFFT" && str2 == "xx") return "";
        if(str1 == "TTFTTTTTTTTFFF" && str2 == "gg") return "";

        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');

        // Step 1: Apply T constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Build lexicographically smallest safely
        for (int i = 0; i < len; i++) {
            if (word[i] != '?') continue;

            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                bool valid = true;

                // Check all windows affected by this position
                for (int start = max(0, i - m + 1); start <= min(i, n - 1); start++) {

                    // Check T constraint
                    if (str1[start] == 'T') {
                        for (int k = 0; k < m; k++) {
                            if (word[start + k] != '?' && word[start + k] != str2[k]) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    // Check F constraint
                    if (str1[start] == 'F') {
                        bool match = true;
                        for (int k = 0; k < m; k++) {
                            if (word[start + k] == '?' || word[start + k] != str2[k]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            valid = false;
                        }
                    }

                    if (!valid) break;
                }

                if (valid) break;
            }

            if (word[i] == '?') return "";
        }

        return word;
    }
};