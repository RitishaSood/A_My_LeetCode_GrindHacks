class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        vector<bool> visited(1001, false);
        visited[start] = true;
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        while (!q.empty()) {
            auto [node, step] = q.front();
            q.pop();
            
            
            if (node == goal) return step;

            for (int i = 0; i < nums.size(); i++) {
               
                int next_nodes[] = {node + nums[i], node - nums[i], node ^ nums[i]};
                
                for (int next_node : next_nodes) {
                    
                    if (next_node == goal) {
                        return step + 1;
                    }
                    
                    
                    if (next_node >= 0 && next_node <= 1000 && !visited[next_node]) {
                        visited[next_node] = true;
                        q.push({next_node, step + 1});
                    }
                }
            }
        }
        return -1;
    }
};