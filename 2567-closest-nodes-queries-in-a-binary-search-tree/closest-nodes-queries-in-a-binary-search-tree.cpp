class Solution {
public:
    void ino(vector<int> &inordervector, TreeNode* root){
        if(root == nullptr){
            return;
        }
        ino(inordervector, root->left);
        inordervector.push_back(root->val);
        ino(inordervector, root->right);
    }

    int findFloor(const vector<int>& nums, int value) {
        int low = 0, high = nums.size() - 1;
        int floor = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= value) {
                floor = nums[mid];
                low = mid + 1; // Try to find a closer larger value <= value
            } else {
                high = mid - 1;
            }
        }
        return floor;
    }

    int findCeil(const vector<int>& nums, int value) {
        int low = 0, high = nums.size() - 1;
        int ceil = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= value) {
                ceil = nums[mid];
                high = mid - 1; // Try to find a closer smaller value >= value
            } else {
                low = mid + 1;
            }
        }
        return ceil;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inordervector;
        ino(inordervector, root);

        vector<vector<int>> ans;
        for (int value : queries) {
            int floor = findFloor(inordervector, value);
            int ceil = findCeil(inordervector, value);
            ans.push_back({floor, ceil});
        }
        return ans;
    }
};