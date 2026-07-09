class Solution {
public:
    bool dfs(int node, vector<int> &arr, vector<int>& vis, int n){
        if(arr[node]==0){
            return true;
        }
        vis[node] = 1;
        int i = node;
        if(i+arr[i] < n && vis[i+arr[i]] == 0){
            if(dfs(i+arr[i], arr, vis, n)) return true;
        }
        if(i-arr[i] >=0 && vis[i-arr[i]] == 0){
            if (dfs(i-arr[i], arr, vis, n)) return true;
        }
        return false;

    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n);
        return dfs(start, arr, vis, n);
        
    }
};