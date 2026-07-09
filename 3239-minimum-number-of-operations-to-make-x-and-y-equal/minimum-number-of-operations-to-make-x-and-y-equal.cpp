class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // If they are already equal, 0 operations needed
        if (x == y) return 0;

        // queue stores pairs of {current_number, operations_count}
        queue<pair<int, int>> q;
        q.push({x, 0});
        
        unordered_set<int> visited;
        visited.insert(x);
        
        // A safe upper bound to prevent unnecessary infinite increments
        // Since x, y <= 10^4, going slightly above 10000 + 11 is enough.
        int upperBound = 10011; 

        while (!q.empty()) {
            auto out = q.front();
            q.pop();
            
            int curr = out.first;
            int step = out.second;
            
            if (curr == y) {
                return step;
            }
            
            // Operation 1: Divide by 11
            if (curr % 11 == 0 && visited.find(curr / 11) == visited.end()) {
                q.push({curr / 11, step + 1});
                visited.insert(curr / 11);
            }
            
            // Operation 2: Divide by 5
            if (curr % 5 == 0 && visited.find(curr / 5) == visited.end()) {
                q.push({curr / 5, step + 1});
                visited.insert(curr / 5);
            }
            
            // Operation 3: Increment by 1 (with upper bound check)
            if (curr < upperBound && visited.find(curr + 1) == visited.end()) {
                q.push({curr + 1, step + 1});
                visited.insert(curr + 1);
            }
            
            // Operation 4: Decrement by 1 (with lower bound check)
            if (curr > 1 && visited.find(curr - 1) == visited.end()) {
                q.push({curr - 1, step + 1});
                visited.insert(curr - 1);
            }
        }
        
        return -1;
    }
};