class Solution {
public:

    struct D {
        bool lower;
        bool upper;
        int lastocc;
        int firstocc;
    };

    int numberOfSpecialChars(string s) {
        
        vector<D> check(26, {false, false, -1, -1});

        for (int i = 0; i < s.length(); i++) {

            if (islower(s[i])) {

                check[s[i] - 'a'].lower = true;
                check[s[i] - 'a'].lastocc = i;

            } else {

                check[s[i] - 'A'].upper = true;

                if (check[s[i] - 'A'].firstocc == -1) {
                    check[s[i] - 'A'].firstocc = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            int l = check[i].lower;
            int r = check[i].upper;
            int a = check[i].lastocc;
            int b = check[i].firstocc;

            if (l && r && a < b) ans++;
        }

        return ans;
    }
};