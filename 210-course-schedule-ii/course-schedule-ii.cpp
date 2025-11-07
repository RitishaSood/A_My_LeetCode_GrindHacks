class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> order;
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
queue<int> q;
// Add all courses with no prerequisites
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
// Kahn’s Algorithm 
        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
// If topological sort includes all courses
        if (order.size() == numCourses)
            return order;
        return {}; 
    }
};
