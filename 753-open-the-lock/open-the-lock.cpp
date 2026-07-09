class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        
        // Use the deadends set to track BOTH deadends and visited states
        unordered_set<string> visited(deadends.begin(), deadends.end());
        
        // If the starting point itself is a deadend, we can't move anywhere
        if (visited.count("0000")) {
            return -1;
        }
        
        q.push({"0000", 0});
        visited.insert("0000"); // Mark starting node as visited
        
        while (!q.empty()) {
            auto out = q.front();
            q.pop();
            string node = out.first;
            int steps = out.second;
            
            if (node == target) {
                return steps;
            }
            
            for (int i = 0; i < 4; i++) {
                char ch = node[i];
                
                // --- Spin Wheel Up (+1) ---
                char Next = (ch == '9') ? '0' : ch + 1;
                node[i] = Next;
                if (visited.find(node) == visited.end()) {
                    visited.insert(node); // Mark visited before pushing
                    q.push({node, steps + 1});
                }
                
                // --- Spin Wheel Down (-1) ---
                Next = (ch == '0') ? '9' : ch - 1;
                node[i] = Next;
                if (visited.find(node) == visited.end()) {
                    visited.insert(node); // Mark visited before pushing
                    q.push({node, steps + 1});
                }
                
                // CRUCIAL: Reset back to original character before moving to index i+1
                node[i] = ch; 
            }
        }
        return -1;
    }
};