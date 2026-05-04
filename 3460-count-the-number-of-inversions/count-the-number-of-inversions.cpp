class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;

        // Map requirements: end -> cnt
        unordered_map<int, int> req;
        for (auto &r : requirements) {
            req[r[0]] = r[1];
        }

        int max_inv = n * (n - 1) / 2;

        vector<int> dp(max_inv + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> new_dp(max_inv + 1, 0);
            vector<int> prefix(max_inv + 2, 0);

            // Build prefix sum
            for (int j = 0; j <= max_inv; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }

            // Transition
            for (int k = 0; k <= max_inv; k++) {
                int left = max(0, k - (i - 1));
                int right = k;
                new_dp[k] = (prefix[right + 1] - prefix[left] + MOD) % MOD;
            }

            // Apply constraint if exists at index (i-1)
            if (req.count(i - 1)) {
                int target = req[i - 1];
                for (int k = 0; k <= max_inv; k++) {
                    if (k != target) new_dp[k] = 0;
                }
            }

            dp = new_dp;
        }

        long long ans = 0;
        for (int x : dp) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};