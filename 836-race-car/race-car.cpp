class Solution {
public:
    int racecar(int target) {
        // initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            // (moves) moves, (pos) position, (vel) velocity)
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) return moves;
            
            // avoid integer overflow - stop whenever we've passed twice the magnitude of target.
            if (abs(pos) > 2 * target) continue;
            
            //always consider moving the car in the direction it is already going
            q.push({moves + 1, pos + vel, 2 * vel});
            
            // only consider changing the direction of the car if one of the following conditions is true
           
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};