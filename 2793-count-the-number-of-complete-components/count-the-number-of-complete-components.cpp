class Solution {
public:
    bool bfs(int startNode, const vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(startNode);
        vis[startNode] = 1;

        vector<int> componentNodes;
        
        // Standard BFS to discover all nodes in this connected component
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            componentNodes.push_back(curr);

            for (int neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        int numNodes = componentNodes.size();
        int expectedDegree = numNodes - 1;

        // Check if it's a complete component
        for (int node : componentNodes) {
            if (adj[node].size() != expectedDegree) {
                return false; 
            }
        }

        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int completeComponentCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // If the discovered component is complete, increment count
                if (bfs(i, adj, vis)) {
                    completeComponentCount++;
                }
            }
        }

        return completeComponentCount;
    }
};