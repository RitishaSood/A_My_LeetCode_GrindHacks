class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& path : paths) {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        
        // Array to store the final assigned flower for each garden
        vector<int> result(n, 0); // Initialize with 0 (uncolored)
        
        // Step 2: Iterate through each garden and pick an available flower
        for (int i = 1; i <= n; ++i) {
            // Track which colors are used by neighbors
            vector<bool> used(5, false);
            
            // Check neighbors of garden i
            for (int neighbor : adj[i]) {
                used[result[neighbor - 1]] = true;
            }
            
            // Pick the first available flower type (1 to 4)
            for (int flower = 1; flower <= 4; ++flower) {
                if (!used[flower]) {
                    result[i - 1] = flower;
                    break;
                }
            }
        }
        
        return result;
    }
};