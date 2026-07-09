class Solution {
public:
    bool dfs(int node, vector<int> &arr, int n){
        if (node < 0 || node >= n || arr[node] < 0) {
            return false;
        }
        if(arr[node]==0){
            return true;
        }
        int jump = arr[node];
        arr[node] = -arr[node];
        int i = node;
       
        if(dfs(i+jump, arr, n)) return true;
        
        
        if (dfs(i-jump, arr, n)) return true;
        
        return false;

    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // vector<int> vis(n);
        return dfs(start, arr, n);
        
    }
};